#include <stdio.h>
// BubbleSort
int main()
{
    int arr[] = {33, 62, 96, 87, 17, 28, 51};
    int i, j, temp, k;
    for (i = 0; i < 7 - 1; i++)
    {
        for (j = 1; j < 7 - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (k = 0; k < 7; k++)
        printf("%d\n", arr[k]);
    return 1;
}