#include<iostream>
#include <string>
using namespace std;
int main()
{
    string str="lets delete vowel from this";
    int n = str.length();
    cout << "size of string is : " << n << endl;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            for(int j=i;j<n;j++)
            {
                str[j]=str[j+1];
            }
            n--;
            i--;
        }
    }
    cout << str << endl;
    return 0;
}
