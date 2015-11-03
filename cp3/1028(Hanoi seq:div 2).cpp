#include<iostream>
#include<cstring>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    for ( int k = 1; k <= t; ++k ) {
        char a[105];
        cin >> a;
        int count = 0;
        int len = strlen(a);
        int num[105];
        for ( int i = 0; i < len; ++i ) {
            num[i] = a[i] - '0';
        }

        while ( num[len - 1] % 2 == 0 ) {
            for ( int i = 0; i < len; ++i ) {
                if ( num[i] % 2 == 1 ) {
                    num[i + 1] += 10;
                }
                num[i] = num[i] / 2;
            }
            ++count;
        }

        if ( k != t ) {
            cout << "Case " << k << ": " << count + 1 << endl << endl;
        } else {
            cout << "Case " << k << ": " << count + 1 << endl;
        }
    }
}
