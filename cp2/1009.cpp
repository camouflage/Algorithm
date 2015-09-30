#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(long long n) {
    if ( n == 2 ) {
        return true;
    }

    for ( int i = 2; i <= sqrt(n); ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    return true;
}

void factor(long long num) {
    int a[15];
    int count = 0;
    while ( !isPrime(num) ) {
        for ( int i = 2; i <= sqrt(num); ++i ) {
            if ( num % i == 0 ) {
                a[count] = i;
                ++count;
                num = num / i;
            }
        }
    }

    a[count] = num;
    sort(a, a + count + 1);
    for ( int i = 0; i < count; ++i ) {
        cout << a[i] << " * ";
    }
    cout << a[count] << " = ";
}

int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    cin >> n;

    int count = 0;
    for ( int i = 2; i <= n; i++ ) {
        long long num = pow(2, i) - 1;
        if ( isPrime(i) && !isPrime(num) ) {
            factor(num);
            cout << num << " = ( 2 ^ " << i << " ) - 1" << endl;
        }
    }
}