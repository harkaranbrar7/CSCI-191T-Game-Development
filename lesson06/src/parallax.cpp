#include "parallax.h"
#include "TextureLoader.h"


TextureLoader *btex = new TextureLoader();



parallax::parallax()
{
    //ctor
    Xmax = 1.0f;
    Ymax = 0.0f;
    Xmin = 0.0f;
    Ymin = 1.0f;

}

parallax::~parallax()
{
    //dtor
}
void parallax::drawSquare(float width, float height)
{
    glColor3f(1.0,1.0,1.0);
    btex->binder();
    glBegin(GL_POLYGON);

        glTexCoord2f(Xmin,Ymin);
        glVertex3f(-width/height,-1,-8.0f);

        glTexCoord2f(Xmax,Ymin);
        glVertex3f(width/height,-1,-8.0f);

        glTexCoord2f(Xmin,Ymax);
        glVertex3f(width/height,1,-8.0f);

        glTexCoord2f(Xmin,Ymax);
        glVertex3f(-width/height,1,-8.0f);

    glEnd();


}

void parallax::parallaxInit(char * FileName)
{
        btex->binder();
        btex->bindTexture(FileName);

}

void parallax::scroll(bool, string, float)
{

}
