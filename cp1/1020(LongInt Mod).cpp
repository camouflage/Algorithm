// Sicily 1020
// long int mod.

#include<iostream>
#include<cstring>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;

int main() {
	// freopen("a.txt", "r", stdin);
	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int bArray[100];
		for ( int i = 0; i < n; i++ ) {
			cin >> bArray[i];
		}

		char longInt[401];
		cin >> longInt;
		int len = strlen(longInt);

		int ans[100];
		for ( int i = 0; i < n; i++ ) {
			int b = bArray[i];

			int modArray[400];
			modArray[0] = 1;
			int tenModB = 10 % b;

			for ( int j = 1; j < len; j++ ) {
				modArray[j] = (tenModB * modArray[j - 1]) % b;
			}

			int mod = 0;
			for ( int j = 0; j < len; j++ ) {
				int oneIntMod = (longInt[j] - '0') % b;
				int onePosMod = (oneIntMod * modArray[len - 1 - j]) % b;
				mod = (mod + onePosMod) % b;
			}

			ans[i] = mod;
		}

		cout << "(";
		for ( int i = 0; i < n - 1; i++ ) {
			cout << ans[i] << ",";
		}
		cout << ans[n - 1] << ")" << endl;
	}
}
