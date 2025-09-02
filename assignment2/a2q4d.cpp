#include<iostream>
#include <string>
#include<vector>

using namespace std;
string sort(string str)
{
    vector<int> freq(26,0);

    for(int i=0;i<str.length();i++)
    {
        int f= str[i]-int('a');
        freq[f]=freq[f]+1;
    }
string str2;
    for(int i=0;i<26;i++)
    {
        while(freq[i]--)
        {
            str2+= char(i+int('a'));
        }
    }
    return str2;
}
int main()
{
    string str;
    cout << "enter the string only in lower case" << endl;
    cin >> str;

    string sorted = sort(str);
    cout << sorted << endl;
    return 0;
}