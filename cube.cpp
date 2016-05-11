// COMPILE : g++ cube.cpp -o cube -lGL -lGLU -lglut

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();
 
// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate=0;
double x=0.0;
double y=0.0; 

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  glRotatef(rotate,x,y,0.0f);  // numpang naruh 'titik pusat rotasi'
 
  // Yellow side - FRONT
  glBegin(GL_POLYGON); // 1
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.4,  0.4,  0.5 );
  glVertex3f( -0.2,  0.4,  0.5 );
  glVertex3f( -0.2,  0.2,  0.5 );
  glVertex3f( -0.4,  0.2,  0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.1,  0.4,  0.5 );
  glVertex3f(  0.1,  0.4,  0.5 );
  glVertex3f(  0.1,  0.2,  0.5 );
  glVertex3f( -0.1,  0.2,  0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f(  0.2,  0.4,  0.5 );
  glVertex3f(  0.4,  0.4,  0.5 );
  glVertex3f(  0.4,  0.2,  0.5 );
  glVertex3f(  0.2,  0.2,  0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.4,  0.1,  0.5 );
  glVertex3f( -0.2,  0.1,  0.5 );
  glVertex3f( -0.2, -0.1,  0.5 );
  glVertex3f( -0.4, -0.1,  0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.1,  0.1,  0.5 );
  glVertex3f(  0.1,  0.1,  0.5 );
  glVertex3f(  0.1, -0.1,  0.5 );
  glVertex3f( -0.1, -0.1,  0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f(  0.2,  0.1,  0.5 );
  glVertex3f(  0.4,  0.1,  0.5 );
  glVertex3f(  0.4, -0.1,  0.5 );
  glVertex3f(  0.2, -0.1,  0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.4, -0.2,  0.5 );
  glVertex3f( -0.2, -0.2,  0.5 );
  glVertex3f( -0.2, -0.4,  0.5 );
  glVertex3f( -0.4, -0.4,  0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f( -0.1, -0.2,  0.5 );
  glVertex3f(  0.1, -0.2,  0.5 );
  glVertex3f(  0.1, -0.4,  0.5 );
  glVertex3f( -0.1, -0.4,  0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f(  0.4, -0.2,  0.5 );
  glVertex3f(  0.2, -0.2,  0.5 );
  glVertex3f(  0.2, -0.4,  0.5 );
  glVertex3f(  0.4, -0.4,  0.5 );
  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON); // 1
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.4,  0.4,  -0.5 );
  glVertex3f( -0.2,  0.4,  -0.5 );
  glVertex3f( -0.2,  0.2,  -0.5 );
  glVertex3f( -0.4,  0.2,  -0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.1,  0.4,  -0.5 );
  glVertex3f(  0.1,  0.4,  -0.5 );
  glVertex3f(  0.1,  0.2,  -0.5 );
  glVertex3f( -0.1,  0.2,  -0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f(  0.2,  0.4,  -0.5 );
  glVertex3f(  0.4,  0.4,  -0.5 );
  glVertex3f(  0.4,  0.2,  -0.5 );
  glVertex3f(  0.2,  0.2,  -0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.4,  0.1,  -0.5 );
  glVertex3f( -0.2,  0.1,  -0.5 );
  glVertex3f( -0.2, -0.1,  -0.5 );
  glVertex3f( -0.4, -0.1,  -0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.1,  0.1,  -0.5 );
  glVertex3f(  0.1,  0.1,  -0.5 );
  glVertex3f(  0.1, -0.1,  -0.5 );
  glVertex3f( -0.1, -0.1,  -0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f(  0.2,  0.1,  -0.5 );
  glVertex3f(  0.4,  0.1,  -0.5 );
  glVertex3f(  0.4, -0.1,  -0.5 );
  glVertex3f(  0.2, -0.1,  -0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.4, -0.2,  -0.5 );
  glVertex3f( -0.2, -0.2,  -0.5 );
  glVertex3f( -0.2, -0.4,  -0.5 );
  glVertex3f( -0.4, -0.4,  -0.5 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f( -0.1, -0.2,  -0.5 );
  glVertex3f(  0.1, -0.2,  -0.5 );
  glVertex3f(  0.1, -0.4,  -0.5 );
  glVertex3f( -0.1, -0.4,  -0.5 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f(  0.4, -0.2,  -0.5 );
  glVertex3f(  0.2, -0.2,  -0.5 );
  glVertex3f(  0.2, -0.4,  -0.5 );
  glVertex3f(  0.4, -0.4,  -0.5 );
  glEnd();
 
  // Blue side - LEFT
  glBegin(GL_POLYGON); // 1
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.4,  -0.4 );
  glVertex3f( -0.5,  0.4,  -0.2 );
  glVertex3f( -0.5,  0.2,  -0.2 );
  glVertex3f( -0.5,  0.2,  -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.4,  -0.1 );
  glVertex3f( -0.5,  0.4,   0.1 );
  glVertex3f( -0.5,  0.2,   0.1 );
  glVertex3f( -0.5,  0.2,  -0.1 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.4,   0.2 );
  glVertex3f( -0.5,  0.4,   0.4 );
  glVertex3f( -0.5,  0.2,   0.4 );
  glVertex3f( -0.5,  0.2,   0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.1,  -0.4 );
  glVertex3f( -0.5,  0.1,  -0.2 );
  glVertex3f( -0.5, -0.1,  -0.2 );
  glVertex3f( -0.5, -0.1,  -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.1,  -0.1 );
  glVertex3f( -0.5,  0.1,   0.1 );
  glVertex3f( -0.5, -0.1,   0.1 );
  glVertex3f( -0.5, -0.1,  -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5,  0.1,  0.2 );
  glVertex3f( -0.5,  0.1,  0.4 );
  glVertex3f( -0.5, -0.1,  0.4 );
  glVertex3f( -0.5, -0.1,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5, -0.2,  -0.4 );
  glVertex3f( -0.5, -0.2,  -0.2 );
  glVertex3f( -0.5, -0.4,  -0.2 );
  glVertex3f( -0.5, -0.4,  -0.4 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5, -0.2,  -0.1 );
  glVertex3f( -0.5, -0.2,   0.1 );
  glVertex3f( -0.5, -0.4,   0.1 );
  glVertex3f( -0.5, -0.4,  -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 0.0, 0.0, 1.0 );    
  glVertex3f( -0.5, -0.2,   0.4 );
  glVertex3f( -0.5, -0.2,   0.2 );
  glVertex3f( -0.5, -0.4,   0.2 );
  glVertex3f( -0.5, -0.4,   0.4 );
  glEnd();
 
  // Red side - RIGHT
  glBegin(GL_POLYGON); // 1
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.4,  -0.4 );
  glVertex3f(  0.5,  0.4,  -0.2 );
  glVertex3f(  0.5,  0.2,  -0.2 );
  glVertex3f(  0.5,  0.2,  -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.4,  -0.1 );
  glVertex3f(  0.5,  0.4,   0.1 );
  glVertex3f(  0.5,  0.2,   0.1 );
  glVertex3f(  0.5,  0.2,  -0.1 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.4,   0.2 );
  glVertex3f(  0.5,  0.4,   0.4 );
  glVertex3f(  0.5,  0.2,   0.4 );
  glVertex3f(  0.5,  0.2,   0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.1,  -0.4 );
  glVertex3f(  0.5,  0.1,  -0.2 );
  glVertex3f(  0.5, -0.1,  -0.2 );
  glVertex3f(  0.5, -0.1,  -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.1,  -0.1 );
  glVertex3f(  0.5,  0.1,   0.1 );
  glVertex3f(  0.5, -0.1,   0.1 );
  glVertex3f(  0.5, -0.1,  -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5,  0.1,  0.2 );
  glVertex3f(  0.5,  0.1,  0.4 );
  glVertex3f(  0.5, -0.1,  0.4 );
  glVertex3f(  0.5, -0.1,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5, -0.2,  -0.4 );
  glVertex3f(  0.5, -0.2,  -0.2 );
  glVertex3f(  0.5, -0.4,  -0.2 );
  glVertex3f(  0.5, -0.4,  -0.4 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5, -0.2,  -0.1 );
  glVertex3f(  0.5, -0.2,   0.1 );
  glVertex3f(  0.5, -0.4,   0.1 );
  glVertex3f(  0.5, -0.4,  -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 1.0, 0.0, 0.0 );    
  glVertex3f(  0.5, -0.2,   0.4 );
  glVertex3f(  0.5, -0.2,   0.2 );
  glVertex3f(  0.5, -0.4,   0.2 );
  glVertex3f(  0.5, -0.4,   0.4 );
  glEnd();
 
  // Green side - BOTTOM
  glBegin(GL_POLYGON); // 1
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.4,  0.5,  0.4 );
  glVertex3f( -0.2,  0.5,  0.4 );
  glVertex3f( -0.2,  0.5,  0.2 );
  glVertex3f( -0.4,  0.5,  0.2 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.1,  0.5,  0.4 );
  glVertex3f(  0.1,  0.5,  0.4 );
  glVertex3f(  0.1,  0.5,  0.2 );
  glVertex3f( -0.1,  0.5,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f(  0.2,  0.5,  0.4 );
  glVertex3f(  0.4,  0.5,  0.4 );
  glVertex3f(  0.4,  0.5,  0.2 );
  glVertex3f(  0.2,  0.5,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.4,  0.5,  0.1 );
  glVertex3f( -0.2,  0.5,  0.1 );
  glVertex3f( -0.2,  0.5, -0.1 );
  glVertex3f( -0.4,  0.5, -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.1,  0.5,  0.1 );
  glVertex3f(  0.1,  0.5,  0.1 );
  glVertex3f(  0.1,  0.5, -0.1 );
  glVertex3f( -0.1,  0.5, -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f(  0.2,  0.5,  0.1 );
  glVertex3f(  0.4,  0.5,  0.1 );
  glVertex3f(  0.4,  0.5, -0.1 );
  glVertex3f(  0.2,  0.5, -0.1 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.4,  0.5, -0.2 );
  glVertex3f( -0.2,  0.5, -0.2 );
  glVertex3f( -0.2,  0.5, -0.4 );
  glVertex3f( -0.4,  0.5, -0.4 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f( -0.1,  0.5, -0.2 );
  glVertex3f(  0.1,  0.5, -0.2 );
  glVertex3f(  0.1,  0.5, -0.4 );
  glVertex3f( -0.1,  0.5, -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 0.0, 1.0, 0.0 );    
  glVertex3f(  0.4,  0.5, -0.2 );
  glVertex3f(  0.2,  0.5, -0.2 );
  glVertex3f(  0.2,  0.5, -0.4 );
  glVertex3f(  0.4,  0.5, -0.4 );
  glEnd();
 
  // Purple side - UP
  glBegin(GL_POLYGON); // 1
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.4,  -0.5,  0.4 );
  glVertex3f( -0.2,  -0.5,  0.4 );
  glVertex3f( -0.2,  -0.5,  0.2 );
  glVertex3f( -0.4,  -0.5,  0.2 );
  glEnd();

  glBegin(GL_POLYGON); // 2
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.1,  -0.5,  0.4 );
  glVertex3f(  0.1,  -0.5,  0.4 );
  glVertex3f(  0.1,  -0.5,  0.2 );
  glVertex3f( -0.1,  -0.5,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 3
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f(  0.2,  -0.5,  0.4 );
  glVertex3f(  0.4,  -0.5,  0.4 );
  glVertex3f(  0.4,  -0.5,  0.2 );
  glVertex3f(  0.2,  -0.5,  0.2 );
  glEnd();
 
  glBegin(GL_POLYGON); // 4
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.4,  -0.5,  0.1 );
  glVertex3f( -0.2,  -0.5,  0.1 );
  glVertex3f( -0.2,  -0.5, -0.1 );
  glVertex3f( -0.4,  -0.5, -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 5
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.1,  -0.5,  0.1 );
  glVertex3f(  0.1,  -0.5,  0.1 );
  glVertex3f(  0.1,  -0.5, -0.1 );
  glVertex3f( -0.1,  -0.5, -0.1 );
  glEnd();

  glBegin(GL_POLYGON); // 6
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f(  0.2,  -0.5,  0.1 );
  glVertex3f(  0.4,  -0.5,  0.1 );
  glVertex3f(  0.4,  -0.5, -0.1 );
  glVertex3f(  0.2,  -0.5, -0.1 );
  glEnd();
 
  glBegin(GL_POLYGON); // 7
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.4,  -0.5, -0.2 );
  glVertex3f( -0.2,  -0.5, -0.2 );
  glVertex3f( -0.2,  -0.5, -0.4 );
  glVertex3f( -0.4,  -0.5, -0.4 );
  glEnd();
 
  glBegin(GL_POLYGON); // 8
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f( -0.1,  -0.5, -0.2 );
  glVertex3f(  0.1,  -0.5, -0.2 );
  glVertex3f(  0.1,  -0.5, -0.4 );
  glVertex3f( -0.1,  -0.5, -0.4 );
  glEnd();

  glBegin(GL_POLYGON); // 9
  glColor3f( 1.0, 0.0, 1.0 );    
  glVertex3f(  0.4,  -0.5, -0.2 );
  glVertex3f(  0.2,  -0.5, -0.2 );
  glVertex3f(  0.2,  -0.5, -0.4 );
  glVertex3f(  0.4,  -0.5, -0.4 );
  glEnd();
  
  glFlush();
  glutSwapBuffers();
 
}
 
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int a, int b ) {
  usleep(1000); 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT){
    x -= x>0.0?1.0:0; 
    y += y<1.0?1.0:0;  
    int frame = 90 / 5;
    for(int i=0;i<frame;i++) {
        rotate += 5;      
        display();
    }
  }
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT) {
    x -= x>0.0?1.0:0; 
    y += y<1.0?1.0:0;  
    int frame = 90 / 5;
    for(int i=0;i<frame;i++) {
        rotate -= 5;      
        display();
    }
  }
 
  else if (key == GLUT_KEY_UP) {
    x += x<1.0?1.0:0; 
    y -= y>0.0?1.0:0;  
    int frame = 90 / 5;
    for(int i=0;i<frame;i++) {
        rotate += 5;      
        display();
    }
  }
 
  else if (key == GLUT_KEY_DOWN) {
    x += x<1.0?1.0:0; 
    y -= y>0.0?1.0:0;  
    int frame = 90 / 5;
    for(int i=0;i<frame;i++) {
        rotate -= 5;      
        display();
    }
  }
 
  //  Request display update
  glutPostRedisplay();
 
}
 
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutCreateWindow("Awesome Cube");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
