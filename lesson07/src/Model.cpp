#include <Model.h>
#include <TextureLoader.h>

#pragma comment(lib, "opengl32.lib")

TextureLoader *tex = new TextureLoader();


Model::Model()
{
   RotateX  = 0.0;
   RotateY  = 0.0;
   RotateZ  = 0.0;
   Zoom     = -8.0;
   Xpos = 0.0;
   Ypos = 0.0;
}

Model::~Model()
{
    //dtor
}

void Model::ModelInit(char *fileName)
{
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
    glutSolidTeapot(1.5);
}
