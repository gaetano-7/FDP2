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

void merge(int V[], int in,int fin, int medio)
{
	int A[fin-in];
	int i1=in, i2=medio+1;
	int i3=0;
	while ((i1<=medio) && (i2<=fin))
	{
		if(V[i1]<V[i2])
		{
			A[i3]=V[i1]; ++i1;
		}
		else
		{
			A[i3]=V[i2]; ++i2;
		}
		++i3;
	}
	while(i1<=medio){
		A[i3]=V[i1]; ++i1; ++i3;
	}
	while(i2<=fin){
		A[i3]=V[i2]; ++i2;++i3;
	}
	
	for(i3=0, i1=in; i1<=fin; ++i3, ++i1)
		V[i1]=A[i3];
	
}

void mergeSort(int V[], int in, int fin)
{
	if ( (fin-in) < 20) insertionSort(V,in,fin);
	else
	{
		int medio=(in+fin)/2;
		mergeSort(V,in,medio);
		mergeSort(V,medio+1, fin);
		merge(V,in,fin,medio);
	}
}




