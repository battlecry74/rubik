// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
    return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
    return ProjectionMatrix;
}


// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 5 ); 
// Origin
glm::vec3 origin = glm::vec3( 0, 0, 0);
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 10.0f; // 3 units / second
float mouseSpeed = 0.005f;



void computeMatricesFromInputs(){

    // glfwGetTime is called only once, the first time this function is called
    static double lastTime = glfwGetTime();

    // Compute time difference between current and last frame
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    // Get mouse position
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    // Reset mouse position for next frame
    glfwSetCursorPos(window, 1024/2, 768/2);

    // Compute new orientation
    horizontalAngle += mouseSpeed * float(1024/2 - xpos );
    verticalAngle   += mouseSpeed * float( 768/2 - ypos );

    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle), 
        sin(verticalAngle) * sin(horizontalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );
    
    // Right vector
    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f/2.0f), 
        0,
        cos(horizontalAngle - 3.14f/2.0f)
    );

    glm::vec3 left = glm::vec3(
        sin(horizontalAngle - 3.14f/2.0f), 
        0,
        sin(horizontalAngle - 3.14f/2.0f)
    );
    // X-Z vector
    glm::vec3 xz = glm::vec3(
        0,
        0,
        -cos(horizontalAngle)
        );
    
    // Up vector
    glm::vec3 up = glm::cross( right, direction );

//  position = ObjectCenter + ( radius * cos(time), height, radius * sin(time) )

    // Move forward
    if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
        position += up * deltaTime * speed;
    }
    // Move backward
    if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
        position -= up * deltaTime * speed;
    }
    // Strafe right
    if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
        position +=  right * deltaTime * speed;
//      position = glm::vec3(5.0f * sin(360), 0, 0);
    }
    // Strafe left
    if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
        position -= (left * deltaTime * speed);
    }

    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    ViewMatrix       = glm::lookAt(
                                position,           // Camera is here
                                origin, // and looks here : at the same position, plus "direction"
                                up                  // Head is up (set to 0,-1,0 to look upside-down)
                           );

    // For the next frame, the "last time" will be "now"
    lastTime = currentTime;
}
int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Rubik", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    // Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(window, 1024/2, 768/2);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat g_vertex_buffer_data[] = { 
		-1.0f,-1.0f,-1.0f,-1.0f,-1.0f, 1.0f,-1.0f, 1.0f, 1.0f,  1.0f, 1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,  1.0f, 1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f,-1.0f,  1.0f,-1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f, 1.0f, 1.0f, 1.0f, 1.0f,-1.0f, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,-1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,-1.0f, 1.0f, 1.0f, 1.0f,-1.0f, 1.0f,
	};

    GLfloat g_vertex_buffer_data_all[9*2*6 * 27];
    int j=0,k,l;
    for(int i=0;i<27;i++) {
        switch(i) {
            case 0:
                for(k=j;k<108;k++)
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[k];
                j = k;
                break;
            case 1:
                l = 0;
                for(k=j;k<216;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 2:
                l = 0;
                for(k=j;k<324;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 3:
                l = 0;
                for(k=j;k<432;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 4:
                l = 0;
                for(k=j;k<540;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 5:
                l = 0;
                for(k=j;k<648;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 6:
                l = 0;
                for(k=j;k<756;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 7:
                l = 0;
                for(k=j;k<864;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=0) 
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break; 
            case 8:
                l = 0;
                for(k=j;k<972;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 9:
                l = 0;
                for(k=j;k<1080;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 10:
                l = 0;
                for(k=j;k<1188;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 11:
                l = 0;
                for(k=j;k<1296;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 12:
                l = 0;
                for(k=j;k<1404;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3!=2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 13:
                l = 0;
                for(k=j;k<1512;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 14:
                l = 0;
                for(k=j;k<1620;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 15:
                l = 0;
                for(k=j;k<1728;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 16:
                l = 0;
                for(k=j;k<1836;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 17:
                l = 0;
                for(k=j;k<1944;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 18:
                l = 0;
                for(k=j;k<2052;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 19:
                l = 0;
                for(k=j;k<2160;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 20:
                l = 0;
                for(k=j;k<2268;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 21:
                l = 0;
                for(k=j;k<2376;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 22:
                l = 0;
                for(k=j;k<2484;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 23:
                l = 0;
                for(k=j;k<2592;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]-=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]+=2.2;
                    l++;
                }
                j = k;
                break;
            case 24:
                l = 0;
                for(k=j;k<2700;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l];
                    if(k%3==0)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==1)
                        g_vertex_buffer_data_all[k]+=2.2;
                    if(k%3==2)
                        g_vertex_buffer_data_all[k]-=2.2;
                    l++;
                }
                j = k;
                break;
            case 25:
                l = 0;
                for(k=j;k<2808;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l] + 2.2;
                    l++;
                }
                j = k;
                break;
            case 26:
                l = 0;
                for(k=j;k<2916;k++) {
                    g_vertex_buffer_data_all[k] = g_vertex_buffer_data[l] - 2.2;
                    l++;
                }
        }
    }


	// One color for each vertex. They were generated randomly.
	static const GLfloat g_color_buffer_data[] = { 
        0.5f, 0.2f, 1.0f, //BC
        0.5f, 0.2f, 1.0f,
        0.5f, 0.2f, 1.0f,

        0.0f, 1.0f, 0.0f, //front right
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        0.0f, 0.1f, 0.0f, //front bottom
        0.0f, 0.1f, 0.0f,
        0.0f, 0.1f, 0.0f,

        0.0f, 1.0f, 0.0f, //front right
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        0.5f, 0.2f, 1.0f, //BC
        0.5f, 0.2f, 1.0f,
        0.5f, 0.2f, 1.0f,

        0.0f, 0.1f, 0.0f, //front bottom
        0.0f, 0.1f, 0.0f,
        0.0f, 0.1f, 0.0f,

        1.0f, 0.0f, 1.0f, //AB
        1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f,

        0.5f, 0.35f, 0.05f, //front left
        0.5f, 0.35f, 0.05f,
        0.5f, 0.35f, 0.05f,
        0.5f, 0.35f, 0.05f, 
        0.5f, 0.35f, 0.05f,
        0.5f, 0.35f, 0.05f,

        0.0f, 0.1f, 0.8f, //front top
        0.0f, 0.1f, 0.8f,
        0.0f, 0.1f, 0.8f,
        0.0f, 0.1f, 0.8f,
        0.0f, 0.1f, 0.8f,
        0.0f, 0.1f, 0.8f,

        1.0f, 0.0f, 1.0f, //AB
        1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f,
	};

    GLfloat g_color_buffer_data_all[9*2*6 * 27];
    j=0;
    for(int i=0;i<27;i++) {
        for(k=0;k<108;k++)
            g_color_buffer_data_all[j++] = g_color_buffer_data[k];
    }

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_all), g_vertex_buffer_data_all, GL_STATIC_DRAW);

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_all), g_color_buffer_data_all, GL_STATIC_DRAW);

	do{

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 12*3*27); // 12*3 indices starting at 0 -> 12 triangles

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
