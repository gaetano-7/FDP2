// SCRIVERE UNA CLASSE CHE COSTRUITA SU UN PARAMETRO N CONSENTA DI OTTENERE
// TUTTE LE COMBINAZIONI DI VALORI VERO/FALSO DI N VARIABILI

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Combinazione{
	vector<bool> v;
	void reset(){v.assign(v.size(),false);}
	
	public:
	Combinazione(int n):v(n,false){}
	
	vector<bool> first(){reset(); return v;}
	vector<bool> next()
	{
		if (v[0]==false) v[0]=true;
		else{
			v[0]=false;
			int i;
			for(i=1;i<v.size() && v[i];i++)
				v[i]=false;
			if (i<v.size()) v[i]=true;
		}
		return v;
	}
	bool last(){
		if (find(v.begin(),v.end(),false)!=v.end()) return false;
		return true;
	}
	
};

void print(const vector<bool>& v){
    for(auto e : v)
		cout<<(e)?"1":"0";
    cout<<endl;
}

int main(){
	int n;
	cin>>n;
	while(n>=0){
		Combinazione c(n);
		print(c.first());
		while(!c.last())
		{
			print(c.next());
		}
	cin>>n;
	}
}