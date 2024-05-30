#ifndef MOTO_H
#define MOTO_H

#include "Veicolo.h"
class Moto : public Veicolo{

    friend ostream& operator<<(ostream& out, const Moto& m){
        return m.print(out);
    }

    public:
        Moto(string t, float p, string c, string n): Veicolo(t,p,c,n){}
        float getPrezzo() const{
        
            float p = Veicolo::getPrezzo();

            if(p < 7000)
                p = p - ((p*3)/100);
            else if(p < 15000)
                p = p - ((p*7.5)/100);
            
            return p;
        }

        Moto* clone()const{
            return new Moto(*this);
        }

};
#endif