void bubbleSort(int a[], int N)
{
    int temp;
    bool scambi;
    int x=N, lastswap;
    do {
        scambi=false;
        for(int i=0;i<x-1;i++)
        {	if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                scambi=true;
                lastswap=i+1;
            }
        }
        x=lastswap;
    } while (scambi);
}