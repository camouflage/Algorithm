#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b < b + a;

    /* Fails when a = "dc", b = "d".
     * It returns ddc, however, dcd is smaller. 
    return a < b;
    */
}

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        string a[8];
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }

        sort(a, a + n, cmp);

        string ans = "";
        for ( int i = 0; i < n; ++i ) {
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}
