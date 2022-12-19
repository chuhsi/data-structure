#include <stdio.h>
/*
    算法描述：
        （1）初始化：取第一个关键字作为基准，两个指针i，j分别用于指示将要与基准进行比较左侧关键字和右侧关键字。
                   从右侧开始比较，在发生交换操作后，再从左侧比较。
        （2）用基准与右（左）侧进行比较：与指针j指向的关键字进行比较。
                   如果右侧关键字大，则继续与右侧记录进行比较，即j减一后，再用基准与指针j指向的关键字进行比较。
                   若右侧关键字小，则将当前右侧关键字赋值于左侧第一个关键字。
        （3）左右侧比较交替重复进行，知道指针i，j指向同一位置。
        
    快速排序是一个递归的过程，只要能实现一趟快速排序的算法，就可以利用递归的方法队第一趟后的左右区域分别进行快速排序。
*/
//  快速排序
void quick_sort(int *arr,int first, int end)
{
    int i,j,t;
    i=first,j=end,t=arr[i];
    while (i<j)
    {
        while(i<j && t<=arr[j]) j--;
        arr[i]=arr[j];
        while(i<j && arr[i]<=t) i++;
        arr[j]=arr[i];
    }
    arr[i]=t;
    if(first<i-1) quick_sort(arr,first,i-1);
    if(i+1<end) quick_sort(arr,i+1,end);
}
//  主程序
int main()
{
    int arr[8]={51,33,62,96,87,17,28,51};
    int f=0,e=7;
    quick_sort(arr,f,e);
    int i;
    for ( i = 0; i < 8; i++)
        printf("%d\n",arr[i]);
    return 0;
}