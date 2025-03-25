#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Key insight: We want to choose the k largest numbers for initial coloring
        // AND make the largest possible number the last one to be colored

        // Sort the array values in descending order
        vector<pair<int, int>> sortedVals;
        for (int i = 0; i < n; i++)
        {
            sortedVals.push_back({a[i], i});
        }
        sort(sortedVals.begin(), sortedVals.end(), greater<pair<int, int>>());

        // Try each element as a potential "last colored"
        long long maxCost = 0;

        for (int i = 0; i < n; i++)
        {
            int lastIdx = sortedVals[i].second; // Try this as the last element to be colored
            int lastVal = sortedVals[i].first;

            // Create a graph where each connected component will eventually all be colored
            vector<vector<int>> adj(n);
            for (int j = 0; j < n - 1; j++)
            {
                adj[j].push_back(j + 1);
                adj[j + 1].push_back(j);
            }

            // Break the graph so that lastIdx becomes isolated
            if (lastIdx > 0)
            {
                // Remove the edge to the left
                adj[lastIdx].erase(remove(adj[lastIdx].begin(), adj[lastIdx].end(), lastIdx - 1), adj[lastIdx].end());
                adj[lastIdx - 1].erase(remove(adj[lastIdx - 1].begin(), adj[lastIdx - 1].end(), lastIdx), adj[lastIdx - 1].end());
            }
            if (lastIdx < n - 1)
            {
                // Remove the edge to the right
                adj[lastIdx].erase(remove(adj[lastIdx].begin(), adj[lastIdx].end(), lastIdx + 1), adj[lastIdx].end());
                adj[lastIdx + 1].erase(remove(adj[lastIdx + 1].begin(), adj[lastIdx + 1].end(), lastIdx), adj[lastIdx + 1].end());
            }

            // Find all connected components
            vector<bool> visited(n, false);
            vector<vector<int>> components;

            for (int j = 0; j < n; j++)
            {
                if (j != lastIdx && !visited[j])
                {
                    vector<int> component;
                    queue<int> q;
                    q.push(j);
                    visited[j] = true;

                    while (!q.empty())
                    {
                        int curr = q.front();
                        q.pop();
                        component.push_back(curr);

                        for (int next : adj[curr])
                        {
                            if (!visited[next] && next != lastIdx)
                            {
                                visited[next] = true;
                                q.push(next);
                            }
                        }
                    }

                    components.push_back(component);
                }
            }

            // For each component, we need at least one node to be initially colored
            int minInitialNeeded = components.size();

            if (minInitialNeeded <= k)
            {
                // We can make lastIdx the last colored element

                // We need to choose k initial elements:
                // 1. At least one from each component
                // 2. The remaining should be the largest possible

                // First, pick the largest element from each component
                vector<bool> isInitial(n, false);
                long long initialSum = 0;
                int initialCount = 0;

                for (const auto &component : components)
                {
                    int maxVal = -1;
                    int maxIdx = -1;

                    for (int idx : component)
                    {
                        if (a[idx] > maxVal)
                        {
                            maxVal = a[idx];
                            maxIdx = idx;
                        }
                    }

                    isInitial[maxIdx] = true;
                    initialSum += a[maxIdx];
                    initialCount++;
                }

                // Then, fill the remaining slots with largest unselected elements
                vector<pair<int, int>> remaining;
                for (int j = 0; j < n; j++)
                {
                    if (j != lastIdx && !isInitial[j])
                    {
                        remaining.push_back({a[j], j});
                    }
                }

                sort(remaining.begin(), remaining.end(), greater<pair<int, int>>());

                for (int j = 0; j < k - initialCount; j++)
                {
                    if (j < remaining.size())
                    {
                        initialSum += remaining[j].first;
                    }
                }

                // Calculate cost with this configuration
                long long cost = initialSum + lastVal;
                maxCost = max(maxCost, cost);
            }
        }

        cout << maxCost << endl;
    }

    return 0;
}