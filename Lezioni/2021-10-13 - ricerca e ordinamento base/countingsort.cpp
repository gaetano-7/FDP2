void countingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;

    min = max = arr[0];   //Individua il min e il max in arr
    for(i = 1; i < sz; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;

    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;

    delete [] B;
}