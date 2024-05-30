bool ricercaBinaria(int V [], int X, int in, int fin)
{	if ( in >= fin ) // test per risoluzione diretta
        return ((in == fin) && (X==V[in]));
    else
    {	// individuazione dell'unico sottoproblema
        int medio = (in+fin)/2;
        if ( V[medio]<X )
            in = medio+1;
        else
        if (X < V[medio] )
            fin = medio - 1;
        else
            in = fin = medio;
        // risoluzione dell'unico sottoproblema e
        // utilizzo della sua soluzione
        return ricercaBinaria(V,X,in,fin);
    }
}