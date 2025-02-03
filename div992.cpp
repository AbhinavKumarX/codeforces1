#include <iostream>
using namespace std;

int main()
{
    int input_range;
    cin >> input_range;
    for (int i = 0; i < input_range; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int result = abs(a - b - 1);
        if (result % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0; // Program ends after processing all test cases
}