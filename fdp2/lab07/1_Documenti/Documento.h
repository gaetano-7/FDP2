#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <string>
#include <iostream>

using namespace std;

class Documento{
protected:
    string proprietario;
    string descrizione;
    int dimensioneFile;     

public:
    Documento(){}
    Documento(string proprietario ,string descrizione ,int dimensioneFile ) :
        proprietario{proprietario},
        descrizione{descrizione},
        dimensioneFile{dimensioneFile}{}
    
    string getProprietario() const {return proprietario;}
    string getDescrizione() const {return descrizione;}
    int getDimensioneFile() const {return dimensioneFile;}

    void setProprietario(string proprietario) {this->proprietario=proprietario;}
    void setDescrizione(string descrizione){this->descrizione=descrizione;}
    void setDimensioneFile(int dimensioneFile){this->dimensioneFile=dimensioneFile;}
};

class DocumentoPDF : public Documento{
private:
    bool firmato;
public:
    DocumentoPDF() : Documento(), firmato(false) {}

    DocumentoPDF(string pr,string des,int df,bool f) : Documento(pr,des,df), firmato(f) {};
    
    bool isFirmato() const { return firmato;}
    void setFirmato(bool f) { firmato=f;}
};

class DocumentoMP3 : public Documento{
private:
    float durata;
public:
    DocumentoMP3() : Documento(), durata(0) {}
    DocumentoMP3(string pr, string des, int df, float d) : Documento(pr, des, df), durata(d) {}
    
    float isDurata() const { return durata;}
    void setDurata(float d) {durata=d;}
};
#endif