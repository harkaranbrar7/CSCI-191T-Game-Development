#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include<GL/gl.h>
#include<SOIL.h>

class TextureLoader
{
    public:
        TextureLoader();
        virtual ~TextureLoader();

        void bindTexture(char*);
        void binder();

        unsigned char* image;
        int width, height;
        GLuint tex;

    protected:

    private:
};

#endif // TEXTURELOADER_H
