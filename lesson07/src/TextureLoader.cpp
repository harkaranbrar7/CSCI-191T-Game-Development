#include "TextureLoader.h"
#include <iostream>

using namespace std;

TextureLoader::TextureLoader()
{
    //ctor
}

TextureLoader::~TextureLoader()
{
    //dtor
}
void TextureLoader::bindTexture(char* fileName)
{

    glGenTextures(1,&tex);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D,tex);

    image =  SOIL_load_image(fileName,&width,&height,0,SOIL_LOAD_RGB);

    if(!image)
        cout<<"Fail to find image"<<endl;

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

void TextureLoader::binder()
{
      glBindTexture(GL_TEXTURE_2D,tex);
}
