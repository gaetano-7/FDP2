struct Tsoluzione{
Grafo G;
int k;
vector<int> W;

Tsoluzione(const Grafo & _G, int _k): G(_G), k(_k){}; 
}

void add(int x, Tsoluzione & sol)
{ sol.W.push_back(x);}

void remove(int x, Tsoluzione & sol)
{ sol.W.pop_back();}

bool isComplete (const Tsoluzione& sol)
{return sol.W.size()==sol.k;}

bool canAdd(int x, const Tsoluzione& sol)
{
	if (find(sol.W.begin(),sol.W.end(),x)!=sol.W.end()) return false;
	for (int i=0; i<sol.W.size(); i++)
		if(!sol.G(sol.W[i],x)) return false;
	
	return true; 

}

bool solve(Tsoluzione & sol) { 
	x = 0; 
	while (x < sol.G.n()) 
		if (canAdd(x,sol)) { 
			add(x,sol); //aggiungi x in coda a sol 
			if (isComplete(sol)) return true; 
			else if (solve(sol)) return true; 
			remove(x,sol); x++; //backtrack 
		} 
		else 
			x++; 
	return false; 

} 

