SCRIVERE UNA FUNZIONE CHE RICEVUTA UNA LISTA ED UN INTERO x SCORRE LA LISTA 
PER COPPIE DI ELEMENTI CONSECUTIVI ED ELIMINA IL SECONDO NODO
SE LA SOMMA TRA IL PRIMO NODO ED IL SECONDO FA x

void eliminaSomma(List<int>& L, int x)
{
	Iterator<int> it(L), it2(L);
	it.moveAtFirst(); it2.moveAtFirst();
	++it2;
	
	while(!it2){ // it2.null()
		if ((*it)+(*it2)==x)
		{
			cout<<"rimuovo "<<*it2<<endl;
			it2.remove();
		}
		else
		{
			++it;
			++it2;
		}
	}
}