#include "Camera.h"

Camera::Camera(int i,int t, int c){
id=i;
tipo=t;
costo=c;
}

int Camera::getCosto(){
return costo;
}

int Camera::getTipo(){
return tipo;
}

