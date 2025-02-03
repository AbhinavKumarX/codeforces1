#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    // Use vector instead of variable-length array
    vector<int> arr(t);

    // Input
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    // Original single-pass sorting algorithm
    for (int j = 0; j < t - 1; j++)
    {
        for (int i = 0; i < t - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] += (arr[i] - arr[i + 1]);
                arr[i] -= (arr[i] - temp);
            }
        }
    }

    // Output with spaces for readability
    for (int i = 0; i < t; i++)
    {
        cout << arr[i];
        if (i < t - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}