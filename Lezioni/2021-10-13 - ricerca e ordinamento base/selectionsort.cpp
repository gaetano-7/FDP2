void selectionSort(int a[], int N)
{	int min, temp;
    for(int i=0;i<N-1;i++)
    {
        min=i;
        for(int j=i+1;j<N;j++)
            if (a[j]<a[min])
                min= j;

        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}