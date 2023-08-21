#ifndef SWAP_HEADER
#define SWAP_HEADER

void swap(int * a, int i)
{
    int tmp;
    tmp = a[i];
    a[i] = a[i + 1];
    a[i + 1] = tmp;
}

#endif