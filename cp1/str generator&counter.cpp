#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {
    // Randomly generate a string.
    ofstream file;
    int n = 10000;
    file.open("a.txt");
    srand(time(NULL));
    char c;
    for ( int i = 0; i < n; i++ ) {
        int ranNum = rand() % 52;
        if ( ranNum < 26 ) {
            c = 'A' + ranNum;
            file << c;
        } else {
            c = (char)'a' + (ranNum - 26);
            file << c;
        }
    }

    // Get the distribution of each letter
    int arr[52];
    for ( int i = 0; i < 52; i++ ) {
        arr[i] = 0;
    }

    freopen("input.txt", "r", stdin);
    for ( int i = 0; i < n; i++ ) {
        cin >> c;
        if ( c >= 'A' && c <= 'Z' ) {
            arr[c - 'A']++;
        } else {
            arr[c - 'a' + 26]++;
        }
    }

    int count = 0;
    for ( int i = 0; i < 52; i++ ) {
        count += arr[i];
    }

    cout << count << endl;

    return 0;
}
