#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q; // Stores {student index, remaining coffee needed}

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        q.push({i, a});
    }

    int lastStudent = 0;

    while (!q.empty()) {
        auto student = q.front();
        q.pop();

        if (student.second > m) {
            student.second -= m;
            q.push(student);
        } else {
            lastStudent = student.first;
        }
    }

    cout << lastStudent << endl;
    return 0;
}
