#include<iostream>
using namespace std;

void search(long long a[], int target, int l, int& ans) {
    for ( int i = 0; i < l; ++i ) {
        if ( a[i] > ans && a[i] <= target ) {
            ans = a[i];
        }
    }

    if ( ans == target || l == 1 ) {
        return;
    }

    for ( int i = 0; i < l - 1; ++i ) {
        for ( int j = i + 1; j < l; ++j ) {
            long long b[5];
            int m = 0;
            for ( int k = 0; k < l; ++k ) {
                if ( k != i && k != j ) {
                    b[m++] = a[k];
                }
            }

            b[m] = a[i] + a[j];
            search(b, target, m + 1, ans);
            b[m] = a[i] - a[j];
            search(b, target, m + 1, ans);
            b[m] = a[j] - a[i];
            search(b, target, m + 1, ans);
            b[m] = a[i] * a[j];
            search(b, target, m + 1, ans);
            if ( a[j] != 0 && a[i] % a[j] == 0 ) {
                b[m] = a[i] / a[j];
                search(b, target, m + 1, ans);
            }
            if ( a[i] != 0 && a[j] % a[i] == 0 ) {
                b[m] = a[j] / a[i];
                search(b, target, m + 1, ans);
            }
        }
    }
}

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int target;
        long long a[5];
        for ( int i = 0; i < 5; ++i ) {
            cin >> a[i];
        }
        cin >> target;
        int ans = -99999999;
        search(a, target, 5, ans);
        cout << ans << endl;
    }
}
