/* Scopo: esempio di funzione ricorsiva */
/* Calcola il massimo comun divisore utilizzando un metodo ricorsivo */
/* Definizione induttiva di mcd(x,y)

     mcd(x,y) = x          se y = 0
     mcd(x,y) = mcd(y,r)   se y > 0 e x = q*y + r, con 0 <= r < y
*/

#include <iostream>
using namespace std;

int mcd(int, int);                               /* prototipo della funzione */

int main(void)
{
  int n1, n2;

  cout<<"inserisci 2 interi positivi\n";
  cin>>n1>>n2;
  cout<<"mcd( "<<n1<<", "<<n2<<")= "<<mcd(n1, n2);

  return 0;
} /* main */


int mcd(int x, int y)
{
  int resto;

  resto = x % y;
  if (resto == 0)
    return y;                  /* caso base */
  else
    return mcd(y, resto);      /* caso ricorsivo */
} /* mcd */
