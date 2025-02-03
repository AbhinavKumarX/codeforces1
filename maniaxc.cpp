#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        bool even_n = n % 2;
        bool even_m = m % 2;
        if (even_m == 0 && even_n == 0)
        {
            if (n >= m)
            {
                cout << "YES";
            }
        }
        else if (even_m == 1 && even_n == 1)
        {
            if (n >= m)
            {
                cout << "YES";
            }
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }

    return 0;
}
