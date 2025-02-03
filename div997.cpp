#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t; // number of test cases

    while (t--)
    {
        int n;
        cin >> n; // number of vertices

        vector<vector<int>> graph(n, vector<int>(n));
        vector<int> degree(n, 0);

        // Read the adjacency matrix and calculate degrees
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 1)
                {
                    degree[i]++;
                }
            }
        }

        // Create a vector of pairs (degree, vertex_index)
        vector<pair<int, int>> degree_vertex(n);
        for (int i = 0; i < n; i++)
        {
            degree_vertex[i] = {degree[i], i};
        }

        // Sort the vertices by their degree (ascending order)
        sort(degree_vertex.begin(), degree_vertex.end());

        // Output the permutation
        for (int i = 0; i < n; i++)
        {
            // We add 1 to the index since the problem uses 1-based indexing
            cout << degree_vertex[i].second + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}