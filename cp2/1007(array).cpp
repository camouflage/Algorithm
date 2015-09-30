#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int col;
    while ( cin >> col ) {
        if ( col == 0 ) {
            break;
        }

        char encrypted[201];
        cin >> encrypted;

        int row = strlen(encrypted) / col;
        // cout << row << " " << col << endl;
        char ori[row][col];
        int col2 = col * 2;
        for ( int i = 0; i < strlen(encrypted); ++i ) {
            if ( i % col2  < col ) {
                ori[i / col][i % col] = encrypted[i];
            } else {
                ori[i / col][col - 1 - i % col] = encrypted[i];
            }
        }

        for ( int i = 0; i < col; ++i ) {
            for ( int j = 0; j < row; ++j ) {
                cout << ori[j][i];
            }
        }

        cout << endl;
    }
}
