#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include <Input.h>
#include <parallax.h>
#include <player.h>

Model *Mdl = new Model();

Input *KbMs = new Input();

parallax *plx = new parallax();

player *ply = new player();

GLScene::GLScene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);

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


   // glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);

    Mdl->ModelInit("Image/texture_1.jpeg");

    plx->parallaxInit("Image/background.jpeg");



    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

    glPushMatrix();
        //Mdl->drawModel();
        ply->drawPlayer();
    glPopMatrix();

    glScaled(3.33,3.33,1.0);
    glPushMatrix();
        plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
    plx->scroll(true,"left",0.0005);

}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
   GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0,aspectRatio,0.1,100);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}


int GLScene::wndMsg(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM	lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    KbMs->wParam = wParam;
		    KbMs->KeyPressed(Mdl);
		    KbMs->keyEnv(plx, 0.005);
			break;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->KeyUP();
			KbMs->keyEnv(plx, 0.005);
			break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            KbMs->keyEnv(plx, 0.005);
            break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            KbMs->keyEnv(plx, 0.005);
            break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl,LOWORD(lParam),HIWORD(lParam));
            break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
            break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
            KbMs->mouseMove(Mdl, LOWORD(lParam),HIWORD(lParam));
             break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseWheel(Mdl,(double)GET_WHEEL_DELTA_WPARAM(wParam));
           break;								// Jump Back
        }

		case WM_SIZE:								// Resize The OpenGL Window
		{
                                                    // LoWord=Width, HiWord=Height
			resizeGLScene(LOWORD(lParam),HIWORD(lParam));
			break;								// Jump Back
		}
	}
}
