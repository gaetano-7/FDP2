#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
using namespace std;

class Camera{
    private:
        int id;
        int tipo;
        int costo;
    public:
        Camera(){};
        Camera(int i,int t,int c);
        int getCosto();
        int getTipo();
        virtual int calcolaCosto(int numero){};
        virtual int tipologia(){};
};
#endif