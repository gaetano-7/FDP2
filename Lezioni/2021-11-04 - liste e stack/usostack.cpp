LETTA UNA ESPRESSIONE PARENTESIZZATA (una stringa)
determinare se essa è ben parentesizzata (ad ogni parentesi aperta corrisponde una corretta parentesi chiusa)
stampare inoltre la coppia di posizioni di apertura/chiusura di ciascuna parentesi

( (x+2)+(y-3)* (  (k^2)-2x)  )
0 1   5  7  10 11 12  16  20 21

((x+2))+(y-3)*((k^2)-2x))
(x+2))
((x+2)

#include <iostream>
using namespace std;
#include <string>
#include "Stack.h"

int main(){

	string expr;
	
	Stack<int> s;
	getline(cin,expr);
	bool esci=false;
	
	for(int i=0; i<expr.length() &&!esci; i++)
	{
		if (expr[i]=='(')
			s.push(i);
		else if (expr[i]==')')
			if (s.empty()) {esci=true;}
			else
			{
			int pos=s.top();
			s.pop();
			cout<<"la parentesi in posizione "<<pos<<" si chiude in posizione "<<i<<endl; 
			}
	
	}
	if ((esci==true)||(!s.empty()) cout<<"L'espressione non e' ben parentesizzata"<<endl; 
	else cout<<"L'espression e' ben parentesizzata"<<endl; 
	
	cout<<"fine elaborazione"<<endl;
}