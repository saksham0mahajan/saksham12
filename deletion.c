#include<stdio.h>
int main()
{
    int i,n,index,arr[10];
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
    printf("enter the index of the element to delete:\n ");
    scanf("%d",&index);
    if(index>=n+1)
    {
        printf("deletion is not possible in the array:\n");
    }
    else
    {

        for(i=index;i<n;i++)
        arr[i]=arr[i+1];
    printf("the array after deleting th element is:\n");
        for(i=0;i<n-1;i++)
            printf("%d ",arr[i]);
        return 0;
    }
}
