#include <iostream>
using namespace std;

double avg(int a[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    return (double)sum / n;
}

int mini(int a[], int n)
{
    int min = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }

    return min;
}

int maxi(int a[], int n)
{
    int max = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

int main()
{
    int n;

    cout << "Enter Your Size Of Array: ";
    cin >> n;

    int arr[100];

    cout << "Enter Your Array Elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Average = " << avg(arr, n) << endl;
    cout << "Minimum = " << mini(arr, n) << endl;
    cout << "Maximum = " << maxi(arr, n) << endl;

    return 0;
}
