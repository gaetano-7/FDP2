#include "Gioielleria.h"

/*
    Un tipo T e` "prezioso" se il numero di gioielli d'oro di quel tipo 
    e` maggiore o uguale al numero di gioielli d'oro di ogni altro tipo.
    
    Un gioiello e` d'oro se come materiale ha ORO_BIANCO oppure ORO_GIALLO oppure ORO_ROSA.
    
    Restituire il primo tipo prezioso presente nella lista di gioielli 
    in base all'ordine di apparizione.
    
	Se non sono presenti gioielli o tipi preziosi, restituire ALTRO_TIPO.   
    
    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 500, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 200, OROLOGIO, ORO_ROSA)
 
    il metodo restituirebbe OROLOGIO. Infatti, avremmo:
    	OROLOGIO 	-> 2 gioielli d'oro
    	ANELLO 		-> 2 gioielli d'oro
    	COLLANA 	-> 1 gioiello d'oro
    	ORECCHINI 	-> 1 gioiello d'oro
    ed inoltre, tra OROLOGIO ed ANELLO nella lista compare prima OROLOGIO.
            
*/
Tipo Gioielleria::metodo1()
{
    //Implementare qui
    return ALTRO_TIPO;
}

/*
    Un materiale M1 e` "economico" se esiste almeno un altro materiale M2 tale per cui 
    la cui media dei prezzi dei gioielli di materiale M2 e` strettamente maggiore 
    della media dei prezzi dei gioielli di materiale M1.
    
    Restituire il numero di materiali economici nella gioielleria.
    
	Se non sono presenti materiali economici, restituire 0.   
	Se non sono presenti gioielli, restituire -1.    
    
    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 600, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 200, OROLOGIO, ORO_ROSA)
 
    il metodo restituirebbe 2. I materiali economici sono ORO_BIANCO e ORO_ROSA.
    Infatti, avremmo come medie dei prezzi:
    	ORO_BIANCO 	-> 475
    	ORO_GIALLO 	-> 600
    	ORO_ROSA 	-> 333
    	ARGENTO 	-> 600
            
*/
int Gioielleria::metodo2()
{
    //Implementare qui
    return -1;    
}

/*
	Sia T il tipo diverso da ALTRO_TIPO che abbia il minor numero di gioielli 
	ma tale per cui nella lista esista almeno un gioiello di tipo T.
	Nel caso in cui piu` tipi soddisfino tale proprieta`, si consideri come T 
	il primo tipo in ordine alfabetico presente nella lista.

	Restituire la descrizione del gioiello piu` costoso di tipo T.
	Nel caso in cui piu` gioielli soddisfino tale proprieta`, si consideri la descrizione 
	del primo gioiello in ordine di apparizione nella lista.

	Se non sono presenti gioielli, restituire "-1".
	Se non sono presenti gioielli con tipo diverso da ALTRO_TIPO, restituire "-2".

    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("O1", 150, OROLOGIO, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("A2", 600, ANELLO, ORO_GIALLO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("A3", 500, ANELLO, ARGENTO)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("O2", 50, OROLOGIO, ACCIAIO)
 
    il tipo T sarebbe COLLANA, pertanto il metodo restiruirebbe "C1".
            
*/
string Gioielleria::metodo3()
{
    //Implementare qui
    return "-1";
}

/*
	Un materiale M e` predominante per un tipo T se tutti i gioielli di materiale M hanno tipo T.           
	Restituire il numero di materiali predominanti per almeno un tipo.

	Se non sono presenti gioielli, restituire -1.
	Se non sono presenti materiali che soddisfino tale proprieta`, restituire -2.

    Ad esempio, se la gioielleria contenesse i seguenti gioielli:
 
    ("B1", 400, BRACCIALE, ORO_BIANCO)
    ("A1", 800, ANELLO, ORO_BIANCO)
    ("C1", 300, COLLANA, ORO_ROSA)
    ("OR1", 500, ORECCHINI, ORO_ROSA)
    ("A2", 500, ANELLO, ARGENTO)
    ("A3", 50, ANELLO, ACCIAIO)
    ("B2", 100, BRACCIALE, ORO_GIALLO)
    ("B3", 100, BRACCIALE, ORO_GIALLO)
 
    il materiale ARGENTO sarebbe predominante per il tipo ANELLO,
    il materiale ACCIAIO sarebbe predominante per il tipo ANELLO.
    il materiale ORO_GIALLO sarebbe predominante per il tipo BRACCIALE.
    Pertanto il metodo restituirebbe 3.
            
*/
int Gioielleria::metodo4()
{
    //Implementare qui
    return -1;
}


