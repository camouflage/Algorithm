#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct emp {
	int id;
	int salary;
	int height;
	int boss;
	int sub; 
};

bool cmp(struct emp a, struct emp b) {
	return a.salary < b.salary;	
}


int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	cin >> n;
	while ( n-- ) {
		int m, q;
		cin >> m >> q;
		
		struct emp a[30000];
		for ( int i = 0; i < m; ++i ) {
			cin >> a[i].id >> a[i].salary >> a[i].height;
			a[i].boss = 0;
			a[i].sub = 0; 
		}
		
		sort(a, a + m, cmp);
		
		map<int, int> idPos;
		for ( int i = 0; i < m; ++i ) {
			idPos[a[i].id] = i;
		}
		
		for ( int i = 0; i < m; ++i ) {
			int boss = 0;
			for ( int j = i + 1; j < m; ++j ) {
				if ( a[j].height >= a[i].height ) {
						a[i].boss = a[j].id;
						boss = j;
						break;
				}
			}
			
			if ( boss != 0 ) {
				a[boss].sub += a[i].sub + 1;
			}
		} 
			
		while ( q-- ) {
			int query;
			cin >> query;
			int pos = idPos[query];
			
			cout << a[pos].boss << " " << a[pos].sub << endl;
		}
	}
	return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct emp {
	int id;
	int salary;
	int height;
};

bool cmp(struct emp a, struct emp b) {
	return a.salary < b.salary;	
}


int main() {
	freopen("a.txt", "r", stdin);
	int n;
	cin >> n;
	while ( n-- ) {
		int m, q;
		cin >> m >> q;
		
		struct emp a[30000];
		for ( int i = 0; i < m; ++i ) {
			cin >> a[i].id >> a[i].salary >> a[i].height;
		}
		
		sort(a, a + m, cmp);
		
		map<int, int> idPos;
		for ( int i = 0; i < m; ++i ) {
			idPos[a[i].id] = i;
		}
		
		while ( q-- ) {
			int query;
			cin >> query;
			int pos = idPos[query];
			
			int boss = 0;
			int subCount = 0;

			// Find boss
			for ( int i = pos + 1; i < m; ++i ) {
				if ( a[i].height >= a[pos].height ) {
					boss = a[i].id;
					break;
				}
			}
			
			// Count subordinates
			for ( int i = pos - 1; i >= 0; --i ) {
				if ( a[i].height <= a[pos].height ) {
					++subCount;
				}
			}
			
			cout << boss << " " << subCount << endl;
		}
	}
	return 0;
}
*/ 
