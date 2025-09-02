#include <stdio.h>

int main (){

int arr[10]={1,2,3,4,5,6,7,8,9,10};
int start=0;
int end=9;
int found;
int bool=1;
while(bool)
{printf("enter the no to find out in between 1 to 10\n");

scanf("%d",&found);
if (found>0 && found<11)
{
    bool=0;    
}
else
printf("the number is outside the domain\n");
}
int it=1;
while(end>=start)
{
    int mid=(start+ end)/2;
    if(found>arr[mid])
    {
        start=mid+1;
    }
    else if (found<arr[mid])
    {
        end=mid-1;
    }
    else{
        printf("the number is found at %d position",(mid+1));
    it=0;
    break;
    }

}
if(it==1)
{
    printf("the number is not in the array");
}
    return 0;
}