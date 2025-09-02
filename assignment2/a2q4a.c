#include <stdio.h>

int main (){

int n;
printf("enter the size of array");
scanf("%d",&n);
int arr[n];
printf("enter the elements of the array \n");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("the array you made is \n");
for(int i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
int left=0,right=n-1;

while(left<=right)
{
    int temp;
    temp=arr[left];
    arr[left]=arr[right];
    arr[right]=temp;
    left++;
    right--;
}
printf("the reversed array is ");
for(int i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}


    return 0;
}