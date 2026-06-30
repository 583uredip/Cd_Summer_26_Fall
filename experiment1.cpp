
#include <iostream>
#include <string>
using namespace std;

bool isNumeric(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < 48 || str[i] > 57)
        {
            return false;
        }
    }
    return true;
}

void numericCheck()
{
    string str;
    cout << "Enter Your Input: ";
    cin >> str;
    if (isNumeric(str))
        cout << "----Your Input Is Numeric Constant-----" << endl;
    else
        cout << "-----Your Input Is Not Numeric Constant-----" << endl;
}

void commentCheck()
{
    string s;
    cout << "Enter Your Input: ";
    cin >> s;
    if (s == "//")
        cout << "This is a single-line comment" << endl;
    else if (s == "/*")
        cout << "This is a multi-line comment" << endl;
    else
        cout << "Not a comment symbol" << endl;
}

bool isIdentifier(string str)
{
    if (str.empty())
        return false;

    if (!isalpha(str[0]) && str[0] != '_')
        return false;

    for (int i = 1; i < str.length(); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}

void identifierCheck()
{
    string input;
    cout << "Enter Your Input: ";
    cin >> input;
    if (isIdentifier(input))
        cout << "\"" << input << "\" is a Valid Identifier" << endl;
    else
        cout << "\"" << input << "\" is NOT a Valid Identifier" << endl;
}

double avg(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return (double)sum / n;
}

int mini(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int maxi(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void arrayStats()
{
    int n;
    cout << "Enter Your Size Of Array: ";
    cin >> n;
    int arr[100];
    cout << "Enter Your Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Average = " << avg(arr, n) << endl;
    cout << "Minimum = " << mini(arr, n) << endl;
    cout << "Maximum = " << maxi(arr, n) << endl;
}

void fullNameMaker()
{
    string firstname, lastname, fullname;
    cout << "Enter Your First Name: ";
    cin >> firstname;
    cout << "Enter Your Last Name: ";
    cin >> lastname;
    fullname = firstname + " " + lastname;
    cout << "Your Full name Is: " << fullname << endl;
}

int main()
{
    cout << "----- Numeric Constant Check -----" << endl;
    numericCheck();

    cout << "\n----- Comment Symbol Check -----" << endl;
    commentCheck();

    cout << "\n----- Identifier Check -----" << endl;
    identifierCheck();

    cout << "\n----- Array Average/Min/Max -----" << endl;
    arrayStats();

    cout << "\n----- Full Name Maker -----" << endl;
    fullNameMaker();

    return 0;
}
