#include "Input.h"

Input::Input()
{
    //ctor
}

Input::~Input()
{
    //dtor
}


void Input::KeyPressed(Model* Mdl)
{

    switch (wParam)
    {

        case VK_LEFT:
        Mdl->RotateX +=1.0;
            break;

        case VK_RIGHT:
        Mdl->RotateX -=1.0;
            break;

        case VK_DOWN:
        Mdl->RotateY -=1.0;
            break;

        case VK_UP:
        Mdl->RotateY +=1.0;
            break;

        case VK_ADD:
        Mdl->Zoom +=1.0;
            break;

        case VK_SUBTRACT:
        Mdl->Zoom +=1.0;
            break;
    }


}

void Input::KeyUP()
{

}

void Input::mouseEventDown(Model*, double, double)
{

}

void Input::mouseEventUp()
{

}

