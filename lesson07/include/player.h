#ifndef PLAYER_H
#define PLAYER_H
#include <Model.h>
#include <gl/gl.h>
#include <TextureLoader.h>


typedef struct
{
    float x;
    float y;
    float z;
}vec;

class player:Model
{
    public:
        player();
        virtual ~player();

        float scalesize[3]={1.0, 1.0, 1.0};
        vec vertices[4];

        float runspeed;
        float jumpspeed;

        void drawPlayer();
        void playerInit();
        void actions();

    protected:

    private:
};

#endif // PLAYER_H
