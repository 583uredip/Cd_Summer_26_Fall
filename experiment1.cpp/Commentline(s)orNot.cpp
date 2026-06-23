#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter Your Input:";
    cin>>s;
    if(s=="//")
    {
     cout << "This is a single-line comment" << endl;
    }
    else if(s=="/*")
    {
     cout << "This is a multi-line comment" << endl;
    }
    else
    {
        cout << "Not a comment symbol" << endl;
    }

    return 0;
}
