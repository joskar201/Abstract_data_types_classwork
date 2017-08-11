#include <stdio.h>

// author: Humphrey Mugambi
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int j = 0, n = 5, item = 7;

    while (j < n)
    {
        if (array[j] == item)
        {
            printf("position is %d and item is %d\n", j, item);
            return 0;
        }
        j = j + 1;
    }
    printf("Item not found\n");
    return 0;
}