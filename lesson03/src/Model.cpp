#include <Model.h>
//#include <TextureLoader.h>

#pragma comment(lib, "opengl32.lib")

//TextureLoader *tex = new TextureLoader();


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

void Model::ModelInit()
{
  //  tex->Binder();
   // tex->BindTexture("images/2.jpg");
}

void Model::drawModel()
{
    glTranslated(Xpos,-Ypos,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    glutSolidTeapot(1.5);
}
