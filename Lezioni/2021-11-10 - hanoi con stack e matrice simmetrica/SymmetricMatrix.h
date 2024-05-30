// SymmetricMatrix.h: interface for the SymmetricMatrix class.
//	Definisce una matrice simmetrica, memorizzando solo la meta' inferiore della matrice
//////////////////////////////////////////////////////////////////////

#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <class T>
class SymmetricMatrix: public Matrix<T>
{	//N.B. con i template e' necessario dare un riferimento esplicito ai membri ed alle funzioni
	//della classe padre altrimenti il compilatore non riesce a risolvere i nomi. 
	//Alternative: 
	//uso della clausola using: using superclass<T>::membro
	//uso del prefisso: superclass<T>::membro
	//uso thi this: this->membro
	using Matrix<T>::mat;
	using Matrix<T>::rows;
	using Matrix<T>::cols;

	public:
	// Parameter construction with default value
	//N.B. le matrici simmetriche possono essere solo quadrate
	SymmetricMatrix(unsigned _rows, const T& _initial) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
			mat[i].resize(i+1, _initial);
		}
		rows = _rows;
		cols = _rows;

	}
	
	// Parameter construction without default value                   
	SymmetricMatrix(unsigned _rows) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
			mat[i].resize(i+1);
		}
		rows = _rows;
		cols = _rows;
	}

// Access the individual elements
// N.B. accedo solo alla matrice triangolare inferiore
	 T& operator()(const unsigned& row, const unsigned& col)
	{	assert(row<rows && col<cols);
		if (row<col) return mat[col][row];
		return mat[row][col];
	}
	 const T& operator()(const unsigned& row, const unsigned& col) const
	{	assert(row<this->rows && col<this->cols);
		if (row<col) return mat[col][row];
		return mat[row][col];
	}

	 void resize(unsigned _rows) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
			mat[i].resize(i+1);
		}
		rows = _rows;
		cols = _rows;
	}
};

#endif