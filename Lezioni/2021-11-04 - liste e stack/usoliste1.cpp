//leggere una parola e determinare se è palindroma (usando le liste)
#include "List.h"
#include "Iterator.h"
#include....

int main(){
	List<char> N;
	Iterator<char> sin(N), des(N);
	
	char c; 
	while(cin>>c){
		N.pushBack(c);
	}
	
	sin.moveAtFirst();
	des.moveAtLast();
	bool palindroma=true; 
	while((sin!=des)&&palindroma)
	{
		if (*sin!=*des)  //if (sin.getCurrentValue()!=des.getCurrentValue())
			palindroma=false;
		else{
			++sin;
			if (sin!=des) --des;
		}
	}
	if (palindroma) cout<<"e' palindroma"<<endl;
	else cout<<"Non e' palindroma"<<endl; 
	
	return 0;
}
