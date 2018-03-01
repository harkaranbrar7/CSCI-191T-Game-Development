#ifndef INPUT_H
#define INPUT_H

#include <Model.h>

class Input
{
    public:
        Input();
        virtual ~Input();
        WPARAM wParam;

        void KeyPressed(Model *);
        void KeyUP();
        void mouseEventDown(Model *,double, double);
        void mouseEventUp();

        double prev_MouseX;
        double prev_Mousey;

    protected:

    private:
};

#endif // INPUT_H
