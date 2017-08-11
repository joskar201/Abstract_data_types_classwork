#include <stdio.h>
#define MAX 5

// author: Humphrey Mugambi

int main()
{
    int array[MAX] = {1, 2, 3, 4, 5};
    int i = 0, j = 0, k = 2, n = 4;

    //print the current array
    for (i = 0; i <= n; i++)
    {
        printf("Array at position %d is %d\n", i, array[i]);
    }
    j = k;
    printf("j %d\n", j);
    while (j < n)
    {
        array[j - 1] = array[j];
        j = j + 1;
    }
    n = n - 1;
    // array after deletion
    for (i = 0; i <= n; i++)
    {
        printf("Array at position %d is %d\n", i, array[i]);
    }
    return 0;
}