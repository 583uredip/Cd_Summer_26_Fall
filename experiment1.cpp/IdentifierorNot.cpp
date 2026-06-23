#include<iostream>
#include <string>
using namespace std;
bool isIdentifier(string s)
{
     if (!((s[0] >= 65 && s[0] <= 90) ||(s[0] >= 97 && s[0] <= 122) ||(s[0] == 95)))
     {
         return false;
     }

     for(int i=1;i<s.length();i++)
     {
         if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||   (s[i] >= 48 && s[i] <= 57) || (s[i] == 95)))
        {
            return false;
        }
     }
     return true;
}
int main()
{
    string s;
    cout << "Enter Input: ";
    cin >> s;

    if (isIdentifier(s))
    {
        cout << s << " is an Identifier" << endl;
    }
    else
    {
        cout << s << " is Not an Identifier" << endl;
    }

    return 0;
}
