#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, counter = 0;
        cin >> n >> k;
        while (n > k)
        {
            if (n % 2 == 0) // even
            {
                n = (n - (k - 1));
            }
            else
            { // odd
                n = (n - k);
            }
            counter++;
        }
        cout << counter + 1 << "\n";
    }
}