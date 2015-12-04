#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool DFS(int st, vector<int> a[], bool visit[], int depth, int& maxDepth, int width[]) {
    visit[st] = true;
    if ( depth > maxDepth ) {
        maxDepth = depth;
    }
    ++width[depth];

    for ( int i = 0; i < a[st].size(); ++i ) {
        if ( visit[a[st][i]] ) {
            return false;
        } else if ( !DFS(a[st][i], a, visit, depth + 1, maxDepth, width) ) {
            return false;
        }
    }

    return true;
}

int main() {
    // freopen("a.txt", "r", stdin);
    int n, m;
    while ( cin >> n >> m && n != 0 ) {
        vector<int> a[101];
        int degree[101];
        memset(degree, 0, sizeof(degree));
        while ( m-- ) {
            int st, ed;
            cin >> st >> ed;
            a[st].push_back(ed);
            ++degree[ed];
        }

        bool valid = true;
        int maxDepth = 0;
        int maxWidth = 0;
        bool visit[101];
        memset(visit, 0, sizeof(visit));
        int width[101];
        memset(width, 0, sizeof(width));
        bool hasRoot = false;

        for ( int i = 1; i <= n; ++i ) {
            if ( degree[i] > 1 ) {
                // Two edges point to the same node
                valid = false;
                break;
            } else if ( degree[i] == 0 ) {
                // Search
                hasRoot = true;
                int depth = 0;
                if ( !DFS(i, a, visit, depth, maxDepth, width) ) {
                    valid = false;
                    break;
                }
            } 
        }

        if ( !valid || !hasRoot ) {
            cout << "INVALID" << endl;
        } else {
            for ( int i = 0; i <= maxDepth; ++i ) {
                if ( width[i] > maxWidth ) {
                    maxWidth = width[i];
                }
            }

            cout << maxDepth << " " << maxWidth << endl;
        }
    }
}
