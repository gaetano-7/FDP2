void insertionSort(int V[], int in, int fin)
{   int temp, j, i;
	for(i=in;i<=fin;i++) 
	{  
		temp=V[i]; 
        	j=i-1; 
		while((V[j]>temp) && (j>=in)) { 
			V[j+1]=V[j]; 
			j--;
          } 
		V[j+1]=temp; 
	}
}

int partiziona(int V[], int in, int fin)
{
	int r=abs(rand()); 
	int iCasuale=r%(fin-in+1)+in;
	scambia(V[in],V[iCasuale]);
	
	int i=in, j=fin+1;
	while(i<j)
	{
		do j--; while(V[in]<V[j);
		do i++; while (V[in]>= V[i] && (i<j));
		if (i<j) scambia(V[i],V[j]);
	}
	scambia(V[in], V[j]);
	return j;
}

void quickSort(int V[], int in, int fin)
{
	if ((fin-in)<20) insertionSort(V,in,fin);
	else{
			int posOrd=partiziona(V,in,fin);
			quickSort(V,in,posOrd-1);
			quickSort(V,posOrd+1,fin);
	}
}

