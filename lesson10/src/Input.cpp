#include "Input.h"

Input::Input()
{
    //ctor
}

Input::~Input()
{
    //dtor
}

void Input::keyEnv(parallax* plx, float speed)
{
    switch(wParam)
    {
    case VK_LEFT:
        plx->Xmin -= speed;
        plx->Xmax -= speed;
        break;

    case VK_RIGHT:
        plx->Xmin += speed;
        plx->Xmax += speed;
        break;

    case VK_UP:
        plx->Ymin += speed;
        plx->Ymax += speed;
        break;

    case VK_DOWN:
        plx->Ymin -= speed;
        plx->Ymax -= speed;
        break;
    }
}


void Input::KeyPressed(Model* Mdl)
{

    switch (wParam)
    {

        case VK_LEFT:
        Mdl->RotateY +=1.0;
            break;

        case VK_RIGHT:
        Mdl->RotateY -=1.0;
            break;

        case VK_DOWN:
        Mdl->RotateX -=1.0;
            break;

        case VK_UP:
        Mdl->RotateX +=1.0;
            break;

        case VK_ADD:
        Mdl->Zoom +=1.0;
            break;

        case VK_SUBTRACT:
            Mdl->Zoom -=1.0;
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
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Input::mouseWheel(Model *Model,double Delta)
{
    Model->Zoom += Delta/100;
}

void Input::mouseMove(Model *Model,double x,double y)
{
    /*
      if(Mouse_Translate)
      {
       Model->Xpos += (x-prev_Mouse_X)/100;
       Model->Ypos -= (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }
      */
}
