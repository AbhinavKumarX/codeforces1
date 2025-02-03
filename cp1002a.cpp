#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    // Input arrays a and b
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // Since we only need to check if 3 distinct elements are possible,
    // we can try a few permutations of array a

    // First, try the original arrangement
    set<int> sums;
    for (int i = 0; i < n; i++)
    {
        sums.insert(a[i] + b[i]);
    }
    if (sums.size() >= 3)
    {
        cout << "YES\n";
        return;
    }

    // Try different permutations
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Try swapping positions i and j
            swap(a[i], a[j]);

            sums.clear();
            for (int k = 0; k < n; k++)
            {
                sums.insert(a[k] + b[k]);
            }

            if (sums.size() >= 3)
            {
                cout << "YES\n";
                return;
            }

            // Restore the original position
            swap(a[i], a[j]);
        }
    }

    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}