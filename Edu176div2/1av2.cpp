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
        if (n % 2) // odd
        {
            n = n - k;
            counter++;
        }
        else
        {
            n = n - (k - 1);
            counter++;
        }
        if (n >= k)
        {
            counter += (n / (k - 1));
            if (n % (k - 1))
            {
                counter++;
            }
        }
        else if (n > 0)
        {
            counter++;
        }

        cout << counter << "\n";
    }
}