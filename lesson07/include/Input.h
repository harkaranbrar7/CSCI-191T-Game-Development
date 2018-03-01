#ifndef INPUT_H
#define INPUT_H

#include <Model.h>
#include <parallax.h>

class Input
{
    public:
        Input();
        virtual ~Input();
        WPARAM wParam;

        void KeyPressed(Model *);
        void KeyUP();
        void keyEnv(parallax *, float);

        void mouseEventDown(Model *,double ,double);
        void mouseEventUp();
        void mouseWheel(Model *,double);
        void mouseMove(Model *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Roatate;


    protected:

    private:
};

#endif // INPUT_H
