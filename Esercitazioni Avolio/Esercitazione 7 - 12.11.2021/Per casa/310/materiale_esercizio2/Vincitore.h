
#ifndef Vincitore_H_
#define Vincitore_H_

#include <iostream>
#include <string>

using namespace std;


enum Disciplina { CENTO = 0, DUECENTO, STAFFETTA };
#include <algorithm>
    

class Vincitore
{
private:
    string atleta;
    int premio;
    Disciplina disciplina;
    
public:
    Vincitore(string _atleta = "", int _premio = 0, Disciplina _disciplina = CENTO) : atleta(_atleta), premio(_premio), disciplina(_disciplina) {}

    string getAtleta() const { return atleta; }
    void setAtleta(string v) { atleta = v; }

    int getPremio() const { return premio; }
    void setPremio(int v) { premio = v; }

    Disciplina getDisciplina() const { return disciplina; }
    void setDisciplina(Disciplina v) { disciplina = v; }

    

    bool operator==(const Vincitore& right) const { return atleta == right.atleta && premio == right.premio && disciplina == right.disciplina; }

friend ostream& operator<<(ostream& out, const Vincitore& x) { return out << "[" << x.atleta << ", " << x.premio << ", " << x.disciplina << "]"; }
};

#endif
