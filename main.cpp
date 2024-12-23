#include <iostream>
#include <set>
using namespace std;

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
int main()
{
    codeforces126();
}