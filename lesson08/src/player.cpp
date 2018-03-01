#include "player.h"

player::player()
{
    //ctor
    vertices[0].x = 0.0;vertices[0].y = 0.0;vertices[0].z = 0.0;
    vertices[1].x = 1.0;vertices[1].y = 0.0;vertices[1].z = 0.0;
    vertices[2].x = 1.0;vertices[2].y = 1.0;vertices[2].z = 0.0;
    vertices[3].x = 0.0;vertices[3].y = 1.0;vertices[3].z = 0.0;

    runspeed = 0.0;
    jumpspeed = 0.0;

}

player::~player()
{
    //dtor
}

void player::drawPlayer()
{
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glTexCoord2f(0.0,1.0);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);

    glTexCoord2f(1.0,1.0);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);

    glTexCoord2f(1.0,0.0);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);

    glTexCoord2f(0.0,0.0);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);
    glPopMatrix();
}

void player::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


}

void player::actions()
{

}
