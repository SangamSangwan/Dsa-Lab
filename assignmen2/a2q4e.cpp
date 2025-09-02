#include<iostream>
#include<string>

using namespace std;

string change(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>=65 && str[i]<=91)
        {
            str[i]=char(32+str[i]);
        }
    }
    return str;
}

int main()
{
    cout << "enter the string to convert uppercase characters to lowercase" << endl;
    string str;
    getline(cin,str);
    cout << change(str) << endl;

}