int * getTestCase(char * path)
{
    FILE *fp = fopen(path, "r");

    if (fp == NULL) 
    {
        perror("Error opening file");
        exit(1);
    }

    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        perror("Memory allocation error");
        exit(1);
    }

    for (int i = 0; i < n; ++i) 
    {
        fscanf(fp, "%d", &arr[i]);
    }

    return arr;
}