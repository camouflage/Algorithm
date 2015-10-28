#include<iostream>
#include<cmath>
using namespace std;

int score(int a[1000], int dp[1000][1000], int l, int r) {
    if ( dp[l][r] != 0 ) {
        return dp[l][r];
    }

    if ( l > r ) {
        return dp[l][r] = 0;
    } else if ( l == r ) {
        return dp[l][r] = a[l];
    } else {
        int lv, rv;
        // Take left
        if ( a[l + 1] >= a[r] ) {
            lv = score(a, dp, l + 2, r) + a[l] - a[l + 1];
        } else {
            lv = score(a, dp, l + 1, r - 1) + a[l] - a[r];
        }
        // Take right
        if ( a[l] >= a[r - 1] ) {
            rv = score(a, dp, l + 1, r - 1) + a[r] - a[l];
        } else {
            rv = score(a, dp, l, r - 2) + a[r] - a[r - 1];
        }
        return dp[l][r] = max(lv, rv);
    }
}

int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    int game = 1;
    while ( cin >> n && n != 0 ) {
        int a[1000];
        int dp[1000][1000];
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                dp[i][j] = 0;
            }
        }

        cout << "In game " << game << ", the greedy strategy might lose by as many as "
             << score(a, dp, 0, n - 1) << " points.\n";
        ++game;
    }
    return 0;
}
