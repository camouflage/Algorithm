#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct town {
	int num;
	int x;
	int y;
};

bool cmp(struct town a, struct town b) {
	return a.x < b.x;
}

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	cin >> n;
	
	struct town a[10000];
	for ( int i = 0; i < n; ++i ) {
		cin >> a[i].x >> a[i].y;
		a[i].num = i + 1;
	}
	
	sort(a, a + n, cmp);
	
	for ( int i = 0; i < n; i += 2 ) {
		cout << min(a[i].num, a[i + 1].num) << " " << max(a[i].num, a[i + 1].num) << endl;
	}
	
	return 0;
}
