#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m)); // Resize matrix
        vector<int> index(n);

        // Input matrix and initialize index
        for (int i = 0; i < n; i++)
        {
            index[i] = i + 1; // Create the index part
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j]; // Input matrix elements
            }
        }

        // Sort each row
        for (int i = 0; i < n; i++)
        {
            sort(matrix[i].begin(), matrix[i].end());
        }

        // Sort rows lexicographically based on the first row
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] > matrix[i + 1][j])
                {
                    swap(matrix[i], matrix[i + 1]);
                    swap(index[i], index[i + 1]);
                    break;
                }
                else if (matrix[i][j] < matrix[i + 1][j])
                {
                    break;
                }
            }
        }

        // Check matrix validity
        bool valid = true;
        for (int i = 0; i < n && valid; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] < matrix[i][j - 1])
                {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid)
        {
            cout << -1 << endl;
        }
        else
        {
            // Print the index
            for (int i = 0; i < n; i++)
            {
                cout << index[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}