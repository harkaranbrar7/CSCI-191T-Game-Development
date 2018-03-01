#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>

#include<GL/glut.h>
#include<iostream>

using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        GLint initGL();
        GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);
    protected:

    private:
};

#endif // GLSCENE_H
