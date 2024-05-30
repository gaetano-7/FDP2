#ifndef TRIPLA_H
#define TRIPLA_H
#include "Camera.h"

class Tripla: public Camera
{
private:

public:
Tripla(){};
Tripla(int i):Camera(i,3,75){}
int calcolaCosto(int numeCamera) { return numeCamera*getCosto();   }
int tipologia(){return getTipo();}


};
#endif