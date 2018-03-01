#include "parallax.h"
#include <textureLoader.h>


TextureLoader *bTex = new TextureLoader();

parallax::parallax()
{
    //ctor
    Xmax= 1.0f;
    Ymax= 0.0f;
    Xmin= 0.0f;
    Ymin= 1.0f;
}

parallax::~parallax()
{
    //dtor
}

void parallax::drawSquare(float width, float height)
{
    glColor3f(1.0f,1.0f,1.0f);
    bTex->binder();
    glBegin(GL_POLYGON);
        glTexCoord2f(Xmin,Ymin);
        glVertex3f(-width/height,-1,-8.0f);

        glTexCoord2f(Xmax,Ymin);
        glVertex3f(width/height,-1,-8.0f);

        glTexCoord2f(Xmax,Ymax);
        glVertex3f(width/height,1,-8.0f);

        glTexCoord2f(Xmin,Ymax);
        glVertex3f(-width/height,1,-8.0f);
     glEnd();
}

void parallax::parallaxInit(char *FileName)
{
    bTex->binder();
    bTex->bindTexture(FileName);
}

void parallax::scroll(bool Auto, string Dir, float speed)
{
    if (Auto)
    {

        if (Dir == "up")
        {

            Ymin -= speed;
            Ymax -= speed;
        }
        if (Dir == "down")
        {

            Ymin += speed;
            Ymax += speed;
        }
        if (Dir == "left")
        {

            Xmin -= speed;
            Xmax -= speed;
        }
        if (Dir == "right")
        {

            Xmin += speed;
            Xmax += speed;
        }
    }

}
