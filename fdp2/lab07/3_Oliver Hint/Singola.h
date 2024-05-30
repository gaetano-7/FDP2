#ifndef SINGOLA_H
#define SINGOLA_H
#include "Camera.h"

class Singola: public Camera
{
private:

public:
Singola(){};
Singola(int i):Camera(i,1,30){}
int calcolaCosto(int numeCamera) { return numeCamera*getCosto();   }
int tipologia(){return getTipo();}


};
#endif