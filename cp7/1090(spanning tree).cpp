#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct edge {
    int x;
    int y;
    int len;
};

int father[500];

int getRoot(int x) {
    if ( father[x] < 0 ) {
        return x;
    } else {
        return father[x] = getRoot(father[x]);
    }
}

void unionSet(int x, int y) {
    int rx = getRoot(x);
    int ry = getRoot(y);
    if ( rx != ry ) {
        father[rx] = ry;
    }
}

bool query(int x, int y) {
    return getRoot(x) == getRoot(y);
}

bool cmp(const struct edge a, const struct edge b) {
    return a.len < b.len;
}

/* Kruskal
int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        struct edge a[125000];
        int index = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                int dist;
                cin >> dist;
                if ( i > j ) {
                    struct edge tmp;
                    tmp.x = i;
                    tmp.y = j;
                    tmp.len = dist;
                    a[index++] = tmp;
                }
            }
        }

        memset(father, -1, sizeof(father));
        sort(a, a + index, cmp);

        int count = 0;
        for ( int i = 0; i < index; ++i ) {
            int x, y;
            x = a[i].x;
            y = a[i].y;
            if ( !query(x, y) ) {
                unionSet(x, y);
                ++count;
            }

            if ( count == n - 1 ) {
                cout << a[i].len << endl;
                break;
            }
        }

        if ( t != 0 ) {
            cout << endl;
        }
    }
}
*/

/* Prim */
int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        int a[500][500];
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                cin >> a[i][j];
            }
        }

        bool visit[500];
        memset(visit, 0, sizeof(visit));
        int dist[500];
        for ( int i = 0; i < n; ++i ) {
            dist[i] = a[0][i];
        }

        vector<int> edge;
        visit[0] = 1;
        for ( int i = 0; i < n - 1; ++i ) {
            int pos;
            int min = 1 << 30;
            for ( int j = 0; j < n; j++ ) {
                if ( visit[j] == 0 && dist[j] < min ) {
                    pos = j;
                    min = dist[j];
                }
            }

            edge.push_back(min);
            visit[pos] = 1;

            for ( int j = 0; j < n; ++j ) {
                if ( visit[j] == 0 && a[pos][j] < dist[j] ) {
                    dist[j] = a[pos][j];
                }
            }
        }

        int total = 0;
        int maxEdge = -1;
        for ( int i = 0; i < edge.size(); ++i ) {
            total += edge[i];
            if ( edge[i] > maxEdge ) {
                maxEdge = edge[i];
            }
        }

        cout << maxEdge << endl;

        if ( t != 0 ) {
            cout << endl;
        }
    }
}
