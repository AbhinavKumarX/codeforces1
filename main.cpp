// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

void codeforces143()
{
    int range;
    cin >> range;
    int count = 0;
    for (int i = 0; i < range; i++)
    {
        int count0 = 0;
        for (int j = 0; j < 3; j++)
        {
            int temp;
            /* code */
            cin >> temp;
            count0 += temp;
        }
        if (count0 >= 2)
        {
            /* code */
            count++;
        }
    }
    cout << count;
}
void codeforces141()
{
    set<int> unique;
    for (int i = 0; i < 4; i++)
    {
        /* code */
        int temp;
        cin >> temp;
        unique.insert(temp);
    }
    cout << 4 - unique.size() << endl;
}
void codeforces126()

{
    double drinks;
    double liquid = 0;
    cin >> drinks;
    for (int i = 0; i < drinks; i++)
    {
        int temp;
        /* code */
        cin >> temp;
        liquid += temp;
    }
    cout << (liquid) / drinks;
}
void codeforcesb63()
{
    int range;
    int sumx = 0, sumy = 0, sumz = 0;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        /* code */
        sumx += x;
        sumy += y;
        sumz += z;
    }
    if (sumx == 0 && sumy == 0 && sumz == 0) // sumx == 0 && sumy == 0 && sumz == 0 DOES NOT WORK
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
void codeforcescp28_1a()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int temp;
        cin >> temp;
        cout << temp - 1 << endl;
    }
}
void codeforcescp28_1b()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        string temp;
        cin >> temp;
        for (int j = temp.length() - 1; j >= 0; j--)
        {
            /* code */
            if (temp[j] == 'p')
            {
                cout << 'q';
            }
            else if (temp[j] == 'q')
            {
                cout << 'p';
            }
            else
            {
                cout << 'w';
            }
        }
        cout << endl;
    }
}
void codeforcescp28_1c()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int seats, r1, r2, common, students = 0;
        cin >> seats >> r1 >> r2 >> common;
        if (r1 >= seats)
        {
            students += seats;
        }
        else
        {
            students += r1;
        }
        if (r2 >= seats)
        {
            students += seats;
        }
        else
        {
            students += r2;
        }
        if (common >= (2 * seats) - students)
        {
            students += ((2 * seats) - students);
        }
        else
        {
            students += common;
        }
        cout << students << endl;
    }
}
void codeforcescp28_2a()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int n, m;
        cin >> n >> m;
        cout << m - n << endl;
    }
}
void codeforcescp28_7c()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int numin, numout = 0;
        cin >> numin;
        for (int j = 0; j <= numin; j++)
        {
            int temp = j;
            while (temp > 0)
            {
                numout += (temp % 10);
                temp /= 10;
            }
        }
        cout << numout << endl;
    }
}
void codeforcescp28_2b()
{
    int range;
    cin >> range;
    for (int x = 0; x < range; x++)
    {
        int n;
        cin >> n;
        vector<string> grid(n);     // Initialize vector with size `n`
        for (int i = 0; i < n; i++) // Correct loop condition
        {
            cin >> grid[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] == '#')
                {
                    cout << j + 1 << " ";
                }
            }
        }
        cout << endl;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int range;
    cin >> range;
    for (int i = 0; i < range; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            sort(matrix[i].begin(), matrix[i].end());
        }
        int foundRow, foundRow2 = -1; // -1 means not found
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                continue;
            }
            if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end())
            {
                foundRow = i;

                break; // Exit the loop once the element is found
            }
            if (find(matrix[i - 1].begin(), matrix[i - 1].end(), target) != matrix[i - 1].end())
            {
                foundRow2 = i - 1;

                break; // Exit the loop once the element is found
            }
            if (foundRow2 == foundRow)
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}