#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int n, m;
    int rdir[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; 
    int cdir[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int adir[8] = {-1, -1, 1, 1, 0, 0, 1, -1};
    int bdir[8] = {-1, 1, -1, 1, 1, -1, 0, 0};
    int board = 1;
    while ( cin >> n >> m && n != 0 && m != 0 ) {
        int a[1000][1000];
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                a[i][j] = 1;
            }
        }
        int numq, numk, nump;
        int q[200];
        int k[200];
        cin >> numq;
        for ( int i = 0; i < numq * 2; i += 2 ) {
            cin >> q[i] >> q[i + 1];
            a[q[i] - 1][q[i + 1] - 1] = 3;
        }
        cin >> numk;
        for ( int i = 0; i < numk * 2; i += 2 ) {
            cin >> k[i] >> k[i + 1];
            a[k[i] - 1][k[i + 1] - 1] = 4;
        }

        cin >> nump;
        for ( int i = 0; i < nump; ++i ) {
            int r, c;
            cin >> r >> c;
            a[r - 1][c - 1] = 2;
        }

        for ( int i = 0; i < numk * 2; i += 2 ) {
            int r = k[i] - 1;
            int c = k[i + 1] - 1;
            for ( int j = 0; j < 8; ++j ) {
                if ( r + rdir[j] >= 0 && r + rdir[j] < n &&
                     c + cdir[j] >= 0 && c + cdir[j] < m && 
                     a[r + rdir[j]][c + cdir[j]] == 1 ) {
                    a[r + rdir[j]][c + cdir[j]] = 0;
                }
            }
        }
        
        for ( int i = 0; i < numq * 2; i += 2 ) {
            int r = q[i] - 1;
            int c = q[i + 1] - 1;
            for ( int j = 0; j < 8; ++j ) {
                int k = 1;
                while ( 1 ) {
                    if ( r + adir[j] * k >= 0 && r + adir[j] * k < n &&
                         c + bdir[j] * k >= 0 && c + bdir[j] * k < m && 
                         a[r + adir[j] * k][c + bdir[j] * k] != 2 &&
                         a[r + adir[j] * k][c + bdir[j] * k] != 3 && 
                         a[r + adir[j] * k][c + bdir[j] * k] != 4 ) {
                        a[r + adir[j] * k][c + bdir[j] * k] = 0;
                        ++k;
                    } else {
                        break;
                    }
                }
            }
        }
        
        int count = 0;
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( a[i][j] == 1 ) {
                    // cout << i << " " << j << endl;
                    ++count;
                }
                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }

        printf("Board %d has %d safe squares.\n", board++, count);
    }
}
