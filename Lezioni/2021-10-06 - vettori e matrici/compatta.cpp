/*
COMPATTA ARRAY

Letta una sequenza di numeri terminata da -1 e lunga al piu’ 100, 
memorizzarla opportunamente in un array e compattare l’array, 
cioe’ eliminare tutti i numeri duplicati ed eliminare i “buchi” cosi’ 
generati spostando a sinistra i valori rimanenti.

*/
 
#include <iostream>
using namespace std;

void leggi_array (int V[], int& dim)
{int c;
 dim=0;
 cout<<"Inserisci l'array terminato da un -1";
 cin>>c;
 while ((c!=-1)&&(dim<100))
 {V[dim]=c;
  dim++;
  cin>>c;
 }
}

void stampa_array (int V[], int dim)
{for (int i=0; i<dim; i++)
   cout<<V[i]<<" ";
 cout<<endl;
}

bool trovato(int x,int V[], int inf, int sup)
{ for (int i=inf; i<=sup; i++)
    if (V[i]==x)
      return true;
  return false;
}

void cancella (int V[], int pos, int & dim)
{ for (int i=pos; i<(dim-1); i++)
    V[i]=V[i+1];
  dim--;
}

void compatta (int V[], int & dim)
{ int i=0;
  while (i<dim)
  {if (trovato(V[i],V,0,i-1))
     cancella(V,i,dim);
   else
     i++;
  }
}

int main()
{int V[100];
 int dim;
 leggi_array(V,dim);
 compatta(V,dim);
 stampa_array(V,dim);     
 return 0; 
}
