#include<iostream>
using namespace std;
bool isNumeric(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]<48 || str[i]>57)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter Your Input:";
    cin>>str;
    if(isNumeric(str))
    {
        cout<<"----Your Input Is Numeric Constant-----"<<endl;
    }
    else
    {
        cout<<"-----Your Input Is Not Numeric Constant-----"<<endl;
    }
    return 0;
}
