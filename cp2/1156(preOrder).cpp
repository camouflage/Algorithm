#include<iostream>
using namespace std;

struct info {
	int num;
	char c;
	int l;
	int r;
};

void preOrder(int root, struct info a[]) {
	if ( root != 0 ) {
		cout << a[root].c;
		preOrder(a[root].l, a);
		preOrder(a[root].r, a);
	}
}

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	while ( cin >> n ) {
		bool b[1001];
		for ( int i = 1; i <= 1000; ++i ) {
			b[i] = -1;
		}
		
		struct info a[1001];
		int num[1000];
		for ( int i = 0; i < n; ++i ) {
			cin >> num[i];
			cin >> a[num[i]].c >> a[num[i]].l >> a[num[i]].r;
			b[num[i]] = 0;
		}
		
		for ( int i = 0; i < n; ++i ) {
			b[a[num[i]].l] = 1;
			b[a[num[i]].r] = 1;
		}
		
		// Find root
		int root;
		for ( int i = 1; i <= 1000; ++i ) {
			if ( b[i] == 0 ) {
				root = i;
				break;
			}
		}
		
		preOrder(root, a);
		cout << endl;
	}
	return 0;
}

