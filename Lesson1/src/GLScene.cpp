#include "GLScene.h"

GLScene::GLScene()
{
 RotateX = 0.0;
 RotateY = 0.0;
 RotateZ = 0.0;
 Zoom = -8.0;
}

GLScene::~GLScene()
{
    //dtor
}
void GLScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)Width / (GLfloat)Height;
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity(); // Reset The Modelview Matrix

}

int GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
    glClearDepth(1.0f);
// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective
    Calculations
    return TRUE; // Initialization Went OK
}

int GLScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
    glLoadIdentity(); // Reset The Current Modelview Matrix
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslated(0.0,0.0,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    glutSolidTeapot(1.5);
    glPopMatrix();
    return TRUE; // Keep Going
}
