#include <stdio.h>
void swap(int* a , int* b);
 
int main(void)
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i<n ;i++)
    {
        printf("Enter array element [%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    for (int i = 0 ; i<n ; i++ )
    {
        printf("%d\t",arr[i]);
    }
    for (int i = 0;i<n;i++)
    {
        int swapcount = 0;
        for (int j = 0 ;j<n-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapcount += 1;
            }
        }
        if (swapcount == 0)
        {
            break ;
        }
    }
    printf("\nAfter sorting:\n");
    for (int i = 0 ; i<n ; i++ )
    {
        printf("%d\t",arr[i]);
    }

    return 0 ;
} 

void swap(int* a,int* b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}