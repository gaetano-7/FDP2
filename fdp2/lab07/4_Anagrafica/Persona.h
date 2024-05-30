#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;

class Persona {
private:
    string codiceFiscale;
    string nome;
    string cognome;
public:
    Persona() {}
    Persona(string cf,string n,string c) : codiceFiscale(cf), nome(n), cognome(c) {}
    virtual ~Persona() {}
        
    virtual Persona* clone() const { return new Persona(*this); }

    void setCodiceFiscale(string cf) { codiceFiscale = cf; }   
    void setNome(string n) { nome = n; }
    void setCognome(string c) { cognome = c; }
        
    string getCodiceFiscale() const { return codiceFiscale; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }

    virtual float getTariffaMensa() const { return 7.0; }
    
    friend ostream& operator<<(ostream& o, const Persona& p) {
        return p.stampa(o);
    }
protected:
    virtual ostream& stampa(ostream& o) const {
        o << codiceFiscale << " " << nome << " " << cognome;
        return o;
    } 
};

class Professore : public Persona {

    public:
        Professore() : Persona(), stipendio(0.0) {}
        Professore(string cf, string n, string c, float s) : Persona(cf, n, c), stipendio(s) {}
        
        Professore* clone() const { return new Professore(*this); }
        
        float getStipendio() const { return stipendio; }
        void setStipendio(float s) { stipendio = s; }
        
        float getTariffaMensa() const {
            if(stipendio <= 30000)
                return 2.5;
            if(stipendio <= 40000)
                return 3.5;
            return 5.0;
        }
        
    protected:
        ostream& stampa(ostream& o) const {
            Persona::stampa(o) << ", stipendio: " << stipendio;
            return o;
        }
        
    private:
        float stipendio;
};

class Studente : public Persona {

    public:
        Studente() : Persona(), isee(0.0) {}
        Studente(string cf, string n, string c, float is) : Persona(cf,n,c), isee(is) {}    
        
        Studente* clone() const { return new Studente(*this); }
        
        float getIsee() const { return isee; }
        void setIsee(float is) { isee = is; }
    
        float getTariffaMensa() const {
            if(isee <= 10000)
                return 0.0;
            if(isee <= 20000)
                return 2.0;
            if(isee <= 40000)
                return 3.0;
            return 4.0;
        }

    protected:
        ostream& stampa(ostream& o) const {
            Persona::stampa(o) << ", ISEE: " << isee;
            return o;
        }
        
    private:
        float isee;
};
#endif