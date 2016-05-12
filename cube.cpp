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
 
  glRotatef(rotate,0.7,y,0.4f);  // numpang naruh 'titik pusat rotasi'
 
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
// light properties
// ----------------------------------------------------------
const GLfloat light_ambient[]  = { 0.0f, 0.2f, 1.0f, 1.0f };
const GLfloat light1_ambient[]  = { 0.3f, 0.2f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat light1_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light1_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { -5.0f, 10.0f, 10.0f, 0.0f };
const GLfloat light1_position[] = { 5.0f, 10.0f, 5.0f, 0.0f };
const GLfloat spot_direction[] = { -10.0f, 10.0f, 0.0};

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 0.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


 
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
  glDepthFunc(GL_LESS);

  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);


  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
  glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

 
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}

