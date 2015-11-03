#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        int a[20000];
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());

        int discount = 0;
        for ( int i = 2; i < n; i += 3 ) {
            discount += a[i];
        }

        cout << discount << endl;
    }
}
