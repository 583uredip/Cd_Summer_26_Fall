#include<iostream>
using namespace std;
int main()
{
    string input;
    cout<<"Enter Your Input:";
    cin>>input;
    int count=1;
    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%' || input[i]=='=')
           {
               cout<<"Operator:"<<input[i]<<endl;
               count++;
           }

    }
}
