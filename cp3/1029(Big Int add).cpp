#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define LEN 50

struct num {
    char a[LEN + 1];
    int len;
    num() {
        memset(a, 0, sizeof(a));
        a[LEN] = '\0';
        len = 0;
    }
    num(const num& numc) {
        strcpy(a, numc.a);
        len = numc.len;
    }
};

// a = a + b
void add(char a[], char b[], int& alen ) {
    for ( int i = LEN - 1; i >= LEN - alen; --i ) {
        if ( a[i] + b[i] >= 10 ) {
            a[i] = a[i] + b[i] - 10;
            ++a[i - 1];
        } else {
            a[i] = a[i] + b[i];
        }
    }
    if ( a[LEN - alen - 1] == 1 ) {
        ++alen;
    }
}

int main() {
    // freopen("a.txt", "r", stdin);
    int m, d;
    while ( cin >> m >> d && !(m == 0 && d == 0) ) {
        struct num month[11];
        month[m].a[LEN - 1] = 1;
        month[m].len = 1;
        
        while ( d-- ) {
            add(month[m].a, month[m - 1].a, month[m].len);
            for ( int i = m - 1; i > 0; --i ) {
                month[i] = month[i - 1];
            }
            month[0] = month[m];
            /*
            for ( int i = 0; i <= m; ++i ) {
                for ( int j = 0; j < LEN; ++j ) {
                    printf("%d", month[i].a[j]);
                }
                cout << endl;
            }
            cout << endl;
            */
        }

        for ( int i = 0; i < m; ++i ) {
            add(month[m].a, month[i].a, month[m].len);
        }

        int flag = 0;
        for ( int i = 0; i < LEN; ++i ) {
            if ( flag == 0 && month[m].a[i] != 0 ) {
                flag = 1;
            }
            if ( flag == 1 ) {
                printf("%d", month[m].a[i]);
            }
        }
        cout << endl;
    }
}
