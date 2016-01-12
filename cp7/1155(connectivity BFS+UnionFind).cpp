#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

/* Union Find */
int getRoot(int x, int* father) {
    if ( father[x] < 0 ) {
        return x;
    } else {
        return father[x] = getRoot(father[x], father);
    }
}

void unionSet(int x, int y, int* father) {
    int rx = getRoot(x, father);
    int ry = getRoot(y, father);
    if ( rx != ry ) {
        father[rx] = ry;
    }
}

bool query(int x, int y, int* father) {
    return getRoot(x, father) == getRoot(y, father);
}

int main() {
    // freopen("a.txt", "r", stdin);
    int n, m;
    while ( cin >> n && n != 0 ) {
        cin >> m;
        int father[200];
        for ( int i = 0; i < n; ++i ) {
            father[i] = -1;
        }

        for ( int i = 0; i < m; ++i ) {
            int st, end;
            cin >> st >> end;
            unionSet(st, end, father);
        }

        if ( query(0, n - 1, father) ) {
            cout << "I can post the letter\n";
        } else {
            cout << "I can't post the letter\n";
        }
    }
    return 0;
}

/* BFS
int main() {
    // freopen("a.txt", "r", stdin);
    int n, m;
    while ( cin >> n && n != 0 ) {
        cin >> m;
        bool a[200][200];
        bool visit[200];
        memset(a, 0, sizeof(a));
        memset(visit, 0, sizeof(visit));

        for ( int i = 0; i < m; ++i ) {
            int st, end;
            cin >> st >> end;
            a[st][end] = 1;
        }

        queue<int> q;
        q.push(0);
        int flag = 0;
        while ( !q.empty() ) {
            int cur = q.front();
            visit[cur] = 1;
            if ( cur == n - 1 ) {
                flag = 1;
                break;
            }
            q.pop();

            for ( int i = 0; i < n; ++i ) {
                if ( a[cur][i] != 0 && visit[i] == 0 ) {
                    q.push(i);
                }
            }
        }

        if ( flag ) {
            cout << "I can post the letter\n";
        } else {
            cout << "I can't post the letter\n";
        }
    }
    return 0;
}
*/
