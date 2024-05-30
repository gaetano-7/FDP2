// Matrix.h: interface for the Matrix class.
// N.B. si puo' anche definire una matrice direttamente come vector<vector <T>> 
// Es. vector<vector<int> > matrix(3, vector<int>(4));
// Ma la liberta' lasciata dai vector non consente di garantire che tutte le righe
// e tutte le colonne abbiano la stessa dimensione. Definiamo una classe Matrix che
// limita le operazioni possibili
//////////////////////////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


template <class T>
class Matrix
{
protected:
	vector<vector<T>> mat;
	unsigned rows;
	unsigned cols;

public:
	//default constructor (creates a void matrix)
	Matrix(){
		rows = 0;
		cols = 0;
	}

	// Parameter construction with default value                   
	Matrix(unsigned _rows, unsigned _cols, const T& _initial) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
		mat[i].resize(_cols, _initial);
		}
		rows = _rows;
		cols = _cols;
	}
	
	// Parameter construction without default value                   
	Matrix(unsigned _rows, unsigned _cols) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
			mat[i].resize(_cols);
		}
		rows = _rows;
		cols = _cols;
	}

//Access the row and column sizes
                                                                  
  unsigned rsize() const {return rows;}
  unsigned csize() const {return cols;};


	// Copy contructor
	Matrix(const Matrix<T>& rhs) {
		mat = rhs.mat;
		rows = rhs.rsize();
		cols = rhs.csize();
	}

	//N.B. la print funzionerà anche per la matrice simmetrica
	//perche' uso l'operatore () per l'accesso. Questo verra' 
	//dinamicamente selezionato in base al tipo (Matrix o SymmetricMatrix)
	void print()
	{
		for (unsigned i=0; i<rows; ++i)
		{
			for (unsigned j=0; j<cols; ++j)
				cout<<(*this)(i,j)<<" ";
			cout<<endl;
		}
		
	}
	
// Access the individual elements
// N.B. Virtual per gestire il polimorfismo sulla matrice simmetrica
	virtual T& operator()(const unsigned& row, const unsigned& col)
	{	assert(row<rows && col<cols);
		return mat[row][col];
	}
	virtual const T& operator()(const unsigned& row, const unsigned& col) const
	{	assert(row<rows && col<cols);
		return mat[row][col];
	}
	
	//N.B. dato che si usa la rezise di vector, se si aumenta la dimensione i 
	//valori precedenti rimangono.
	virtual void resize(unsigned _rows, unsigned _cols) {
		mat.resize(_rows);
		for (unsigned i=0; i<mat.size(); i++) {
			mat[i].resize(_cols);
		}
		rows = _rows;
		cols = _cols;
	}
};
#endif

