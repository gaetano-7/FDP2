//Scrivere una funzione che, data una matrice, determini se esistono due righe esattamente identiche 

const int rowSize=3;
const int colSize=4;

bool verifica(const int m[][colSize], int rowSize, int colSize)
{
	bool trovate=false;
	for (int r1=0; r1rowSize-1&&!trovate; ++r1)
		for (int r2=r1+1; r2 rowSize&&!trovate; ++r2)
		{	
			bool identiche=true;
			for(int c=0; ccolSize && identiche; ++c)
				if (m[r1][c]!=m[r2][c]) 
					identiche=false;
			if (identiche) trovate=true;		
		}
	return trovate;
}
