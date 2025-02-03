#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // The problem requires splitting array into k parts
    // and taking even-indexed parts to form array b
    // We want to minimize the first position where b[i] != i

    // Since k is even, we'll have k/2 subarrays in b
    // We need to try different ways to split the array

    // Initialize result with maximum possible value
    ll ans = n + 1;

    // Try all possible splits using next_permutation approach
    vector<int> splits(n - 1, 0);
    for (int i = 0; i < k - 1; i++)
    {
        splits[i] = 1;
    }
    sort(splits.begin(), splits.end());

    do
    {
        vector<ll> b;
        int start = 0;
        bool isEven = false; // false for odd index, true for even index

        // Create subarrays based on splits
        for (int i = 0; i < n - 1; i++)
        {
            if (splits[i])
            {
                if (isEven)
                {
                    // Add elements to b if it's even-indexed subarray
                    for (int j = start; j <= i; j++)
                    {
                        b.push_back(a[j]);
                    }
                }
                start = i + 1;
                isEven = !isEven;
            }
        }

        // Handle the last subarray
        if (isEven)
        {
            for (int j = start; j < n; j++)
            {
                b.push_back(a[j]);
            }
        }

        // Add 0 at the end as required
        b.push_back(0);

        // Find the first position where b[i] != i
        ll cost = 1;
        while (cost < b.size() && b[cost - 1] == cost)
        {
            cost++;
        }

        ans = min(ans, cost);

    } while (next_permutation(splits.begin(), splits.end()));

    cout << ans << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}