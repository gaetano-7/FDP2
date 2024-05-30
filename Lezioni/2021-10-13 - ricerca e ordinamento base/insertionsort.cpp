void insertionSort(int a[], int N)
{	int temp, j;
    for(int i=1;i<N;i++) // n è la dimensione dell’array
    {
        temp=a[i];
        j=i-1;
        while((j>=0) && (a[j]>temp)) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}