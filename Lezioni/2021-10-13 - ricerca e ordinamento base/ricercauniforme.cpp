bool ricercaUniforme(int V [], int X, int in, int fin)
{	if ( in >= fin || X<V[in] || V[fin]<X || V[in]==V[fin] )
        return ((in <= fin) && (X==V[in]));
    else
    {	// individuazione più accurata dell'unico sottoproblema
        int m = in+(fin-in)*(X-V[in])/(V[fin]-V[in]);
        if (V[m]<X)
            in = m+1;
        else
        if (X<V[m])
            fin = m - 1;
        else
            in = fin = m;
        // risoluzione dell'unico sottoproblema e
        // utilizzo della sua soluzione
        return ricercaUniforme(V,X,in,fin);
    }
}