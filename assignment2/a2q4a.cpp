#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1="abc";
    string s2="def";
     cout << s2+s1 << endl;
    s1+=s2;

    cout << s1 << endl;
    return 0;
}