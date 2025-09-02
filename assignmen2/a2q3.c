#include <stdio.h>

int main (){
// let the array be such that it follows an A.P. sequence of which we dont know the common difference
int diff;
int arr[9]={5, 11, 14, 17, 20, 23, 26, 29, 32};
if(arr[2]-arr[1] == arr[3]-arr[2])
{
    diff=arr[2]-arr[1];
}
else{
    diff=arr[5]-arr[4];
}
int count=arr[0];
for(int i=0;i<9;i++)
{
    if(arr[i]!=count)
    {
        printf("one number is missing and that is %d which should be at %d position\n",count,(i+1));
        break;
    }

    count=count+diff;
}

    return 0;
}