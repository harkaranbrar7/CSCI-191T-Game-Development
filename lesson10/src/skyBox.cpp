#include "skyBox.h"

   TextureLoader  tLoad

skyBox::skyBox()
{
    //ctor

    RotateX = 0;
    RotateY = 0;
    RotateZ = 0;

    translateX = 0;
    translateY = 0;
    translateZ = 0;
}

skyBox::~skyBox()
{
    //dtor
}
void skyBox::loadTextures()
{

    glEnable(GL_TEXTURE_2D);
    glGenTextures(6,tex);

    tex[0] = tload->bindTexture("images/Box/front.jpg");
    tex[1] = tload->bindTexture("images/Box/front.jpg");
    tex[2] = tload->bindTexture("images/Box/front.jpg");
    tex[3] = tload->bindTexture("images/Box/front.jpg");
    tex[4] = tload->bindTexture("images/Box/front.jpg");
    tex[5] = tload->bindTexture("images/Box/front.jpg");
    tex[6] = tload->bindTexture("images/Box/front.jpg");

}

void skyBox::drawBox()
{

}
