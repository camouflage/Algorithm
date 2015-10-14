#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char a[252];
    cin >> a;

    int len = strlen(a);
    int count = 0;
    for ( int i = 0; i < len; ++i ) {
        count += a[i] - '0';
    }
	
	if ( count % 3 == 0 ) {
		cout << 2 << endl;
	} else {
		cout << 1 << endl << count % 3 << endl;
	}
	
	return 0;
}
