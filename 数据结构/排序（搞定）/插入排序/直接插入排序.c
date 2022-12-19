#include <stdio.h>
int main()
{
    int arr[] = {33, 62, 96, 87, 17, 28, 51};
    int i, temp;
    for (i = 1; i < 7; i++)
    {
        while (arr[i] < arr[i - 1] && i > 0)
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
    for (i = 0; i < 7; i++)
        printf("%d\n", arr[i]);
    return 0;
}
// I did it!!!
    /*
    int arr[]={51,33,62,96,87,17,28,51};
    int i,j,temp;
    for ( i = 1; i < 8; i++)
    {
        if(arr[i]<arr[i-1])
        {
            temp=arr[i];
            arr[i]=arr[i-1];
            i--;
            while (arr[i-1]>temp && i>=0)
            {
                arr[i]=arr[i-1];
                i--;
            }
            arr[i]=temp;
        }
    }
    for ( j = 0; j < 8; j++)
    {
        printf("%d\n",arr[j]);
    }
    */