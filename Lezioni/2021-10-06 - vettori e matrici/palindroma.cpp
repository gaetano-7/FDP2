//DETERMINARE SE UNA PAROLA LETTA DA INPUT E’ PALINDROMA
//palindroma
#include <iostream>
using namespace std;

const int maxdim=30;

void leggi_array (char V[], int& dim)
{char c;
 dim=0;
 cout<<"Inserisci la parola terminata da un punto";
 cin>>c;
 while ((c!='.')&&(dim<maxdim))
 {V[dim]=c;
  dim++;
  cin>>c;
 }

}

bool palindroma (char V[], int dim)
{bool trovato_diverso=false;
 for (int i=0; (i<dim/2)&&(!trovato_diverso); i++)
   if (V[i]!=V[dim-1-i])
     trovato_diverso=true;
 if (trovato_diverso)
   return false;
 else
   return true;

}

int main()
{char V[maxdim];
 int dim;
 leggi_array(V,dim);
 if (palindroma(V,dim))
   cout<<"La parola e' palindroma"<<endl;
 else
   cout<<"La parola non e' palindroma"<<endl;

 return 0;

}
