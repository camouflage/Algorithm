#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int n, m;
    while ( cin >> n >> m && !(n == 0 && m == 0) ) {
        int a[100000];
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }
        sort(a, a + n);

        cout << a[0];
        for ( int i = m; i < n; i += m ) {
            cout << " " << a[i];
        }
        cout << endl;
    }
    return 0;
}
