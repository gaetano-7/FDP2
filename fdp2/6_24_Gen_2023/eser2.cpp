#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StatisticheVettore{
    public:
        virtual double compute(const vector<int>&) = 0;
};

class MediaVettore : public StatisticheVettore{
    public:
        double compute(const vector<int>& l) override{
            double somma = 0;
            for(auto i : l){
                somma+=i;
            }
            double media = somma / l.size();
            return media;
        }
};

class ModaVettore : public StatisticheVettore {
public:
    double compute(const vector<int>& l) override {
        int moda = 0;
        int corrente = 0;
        int max = 0;
        while (corrente!=l.size()){
            int cont = 0;
            for(int i : l){
                if(l[corrente]==i){
                    cont+=1;
                }
                if(cont>max){
                    max = cont;
                    moda = l[corrente];
                }
            }
            cont = 0;
            corrente++;
        }
        return moda;
    }
};

class MedianaVettore : public StatisticheVettore {
public:
    double compute(const vector<int>& l) override {
        vector<int> y = l;
        sort(y.begin(), y.end());
        double mediana = 0;
        int meta = l.size() / 2;

        if (y.size()%2==0){
            mediana = (y[meta - 1] + y[meta]) / 2.0;
        }
        else{
            mediana = y[meta];
        }
        return mediana;

    }
};

int main(){
    vector<StatisticheVettore*> S;
    vector<int> vettore = {1,2,7,5,4,3};
   
    // 1,2,3,4,5,7
    S.push_back(new MediaVettore());
    S.push_back(new ModaVettore());
    S.push_back(new MedianaVettore());

    double media = S[0]->compute(vettore);
    double moda = S[1]->compute(vettore);
    double mediana = S[2]->compute(vettore);

    cout<<media<<endl;
    cout<<moda<<endl;
    cout<<mediana<<endl;

    delete S[0];
    delete S[1];
    delete S[2];

    return 0;
}