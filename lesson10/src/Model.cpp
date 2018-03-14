#include <Model.h>
#include <TextureLoader.h>

#pragma comment(lib, "opengl32.lib")

TextureLoader *tex = new TextureLoader();


Model::Model()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;

   Zoom = -4.0;
   Xpos = -0.5;
   Ypos = -0.5;

    vertices[0].x = 0.0;vertices[0].y = 0.0;vertices[0].z = 1.0;
    vertices[1].x = 1.0;vertices[1].y = 0.0;vertices[1].z = 1.0;
    vertices[2].x = 1.0;vertices[2].y = 1.0;vertices[2].z = 1.0;
    vertices[3].x = 0.0;vertices[3].y = 1.0;vertices[3].z = 1.0;
}

Model::~Model()
{
    //dtor
}

void Model::ModelInit(char *fileName,bool trans)
{
    if(trans)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    }

    tex->binder();
    tex->bindTexture(fileName);
}

void Model::drawModel()
{
    glColor3f(0.8,0.5,0.0);
    tex->binder();
    glTranslated(Xpos,Ypos,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0,1.0);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);

    glTexCoord2f(1.0,1.0);
    glVertex3f(vertices[1].x,vertices[1].y,vertices[1].z);

    glTexCoord2f(1.0,0.0);
    glVertex3f(vertices[2].x,vertices[2].y,vertices[2].z);

    glTexCoord2f(0.0,0.0);
    glVertex3f(vertices[3].x,vertices[3].y,vertices[3].z);

    glEnd();
    //glutSolidTeapot(1.5);
}
