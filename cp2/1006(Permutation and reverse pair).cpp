#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	while ( cin >> n ) {
		if ( n == 0 ) {
			break;
		}
		
		int a[100][5];
		for ( int i = 0; i < n; ++i ) {
			char rank[6];
			cin >> rank;
	
			for ( int j = 0; j < 5; ++j ) {
				a[i][rank[j] - 'A'] = j;
			}

		}
		
		int minScore = 99999999;
		int min[5];
		int init[5] = {0, 1, 2, 3, 4};
		do {
			// cout << init[0] << init[1] << init[2] << init[3] << init[4] << endl;
			int score = 0;
			for ( int i = 0; i < n; ++i ) {
				for ( int j = 0; j < 4; ++j ) {
					for ( int k = j + 1; k < 5; ++k ) {
						if ( a[i][j] < a[i][k] && init[j] > init[k] ||
							 a[i][j] > a[i][k] && init[j] < init[k] ) {
							 	++score;
						}
					}
				}
			}
			
			if ( score < minScore ) {
				minScore = score;
				for ( int i = 0; i < 5; ++i ) {
					min[i] = init[i];
				}
			}
		} while ( next_permutation(init, init + 5) );
		
		char minChar[5];
		for ( int i = 0; i < 5; ++i ) {
			minChar[min[i]] = 'A' + i;
		}
		
		for ( int i = 0; i < 5; ++i ) {
			cout << minChar[i];
		}
		
		cout << " is the median ranking with value " << minScore << "." << endl;
		/*
		for ( int i = 0; i < n; ++i ) {
			for ( int j = 0; j < 5; ++j ) {
				cout << a[i][j];
			}
			cout << endl;
		}
		*/
	}
	
	return 0;
}

