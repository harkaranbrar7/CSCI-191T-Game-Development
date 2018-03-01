#ifndef MODEL_H
#define MODEL_H

#include<windows.h>
#include<GL/glut.h>

class Model
{
    public:
        Model();
        virtual ~Model();
        void drawModel();

        void ModelInit();

        double RotateX;
        double RotateY;
        double RotateZ;

        double Zoom;
        double Xpos;
        double Ypos;

    protected:

    private:
};

#endif // MODEL_H
