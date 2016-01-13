#include<iostream>
#include<algorithm>
#include<cstring>
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
