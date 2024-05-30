#ifndef PAIR_H
#define PAIR_H

template<class T1, class T2>
class Pair {

    public:
        Pair(T1 f, T2 s);
        T1 getFirst() const;
        T2 getSecond() const;
        void setFirst(T1 f);
        void setSecond(T2 s);

    private:
        T1 first;
        T2 second;
};

template<class T1, class T2>
Pair<T1,T2>::Pair(T1 f, T2 s) {
    first = f;
    second = s;
}

template<class T1, class T2>
T1 Pair<T1,T2>::getFirst() const {
    return first;
}

template<class T1, class T2>
T2 Pair<T1,T2>::getSecond() const {
    return second;
}

template<class T1, class T2>
void Pair<T1,T2>::setFirst(T1 f) {
    first = f;
}

template<class T1, class T2>
void Pair<T1,T2>::setSecond(T2 s) {
    second = s;
}

#endif

//========un possibile main: ======
//ESEMPIO D’USO DI PAIR SU DUE TIPI
#include "Pair.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Pair<int,char> p1(1,'a');
    Pair<string, string> p2("ciao", "mondo");

    cout << p1.getSecond() << endl;
    cout << p2.getFirst() << endl;
}
