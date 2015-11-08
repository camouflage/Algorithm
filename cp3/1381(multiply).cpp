#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define LEN 105

void add(char* a, char* b) {
    for ( int i = LEN - 1; i > 0; --i ) {
        a[i] = a[i] + b[i];
        if ( a[i] >= 10 ) {
            a[i - 1]++;
            a[i] -= 10;
        }
    }
}

void multiply(char* result, char* a, char* b, int len) {
    for ( int i = 1; i <= len; ++i ) {
        for ( int j = 0; j < b[LEN - i]; ++j ) {
            add(result, a);
        }
        // append 0
        for ( int j = 0; j < LEN - 1; ++j ) {
            a[j] = a[j + 1];
        }
        a[LEN - 1] = 0;
    }
}



int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        char a[LEN];
        char b[LEN];
        char result[LEN];
        cin >> a >> b;

        char num1[LEN];
        char num2[LEN];
        memset(num1, 0, LEN);
        memset(num2, 0, LEN);
        memset(result, 0, LEN);

        for ( int i = LEN - 1, j = strlen(a) - 1; i >= LEN - strlen(a); --i, --j ) {
            num1[i] = a[j] - '0';
        }

        for ( int i = LEN - 1, j = strlen(b) - 1; i >= LEN - strlen(b); --i, --j ) {
            num2[i] = b[j] - '0';
        }

        // add(num1, num2);
        multiply(result, num1, num2, strlen(b));

        int flag = 0;
        for ( int k = 0; k < LEN; ++k ) {
            if ( flag == 0 && result[k] != 0 ) {
                flag = 1;
            }
            if ( flag == 1 ) {
                printf("%d", result[k]);
            }
        }
        if ( flag == 0 ) {
            cout << "0";
        }
        cout << endl;
    }
}
