#include <iostream>
#include <string>
using namespace std;
bool isIndentifier(string str)
{
   if(str.empty())
   {
       return false;
   }
   if(!isalpha(str[0])&& str[0]!='_')
   {
       return false;
   }
   for(int i=1;i<str.length();i++)
   {
       if(!isalnum(str[i]) && str[i]!='_')
       {
           return false;
       }
   }
   return true;
}
int main()
{
    string input;
    cout<<"Enter Your Input:";
    cin>>input;
    if(isIndentifier(input))
    {
        cout << "\"" << input << "\" is a Valid Identifier" << endl;
    }
    else
    {
         cout << "\"" << input << "\" is NOT a Valid Identifier" << endl;
    }
    return 0;
}
