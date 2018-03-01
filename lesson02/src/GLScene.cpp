#include "GLScene.h"
#include "GLLight.h"

GLScene::GLScene()
{
    //ctor
}

GLScene::~GLScene()
{
    //dtor
}
GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);

    return true;

}

GLint GLScene::drawGLScene()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(0,0,-8.0);
    glColor3f(1.0,0.5,1.0);

    glPushMatrix();
    glutSolidTeapot(1.5);
    glPopMatrix();



}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
        GLfloat aspectRatio = (GLfloat) width/(GLfloat) height ;
        glViewport(0,0,width,height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0,aspectRatio,0.1,100);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}
