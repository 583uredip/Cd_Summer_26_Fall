#include<iostream>
#include<string>
using namespace std;
int main()
{
    string firstname,lastname,fullname;
    cout<<"Enter Your First Name:";
    cin>>firstname;
    cout<<"Enter Your Last Name:";
    cin>>lastname;
    fullname = firstname + " " +lastname;
    cout<<"Your Full name Is:"<<fullname<<endl;
    return 0;
}

