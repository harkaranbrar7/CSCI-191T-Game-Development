#ifndef GLSCENE_H
#define GLSCENE_H


class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        void reSizeScene(int width, int height);
        int initGL();
        int drawScene();

        double RotateX;
        double RotateY;
        double RotateZ;
        double Zoom;

    protected:

    private:
};

#endif // GLSCENE_H
