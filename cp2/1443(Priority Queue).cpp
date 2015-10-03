#include<iostream>
#include<deque>
using namespace std;

int findMax(deque<int>& dq, int num) {
	int max = 0;
	int pos = 0;
	for ( int i = 0; i < dq.size(); ++i ) {
		if ( dq[i] > max ) {
			max = dq[i];
			pos = i;
		}
	}
	return pos;
}

int main() {
	// freopen("a.txt", "r", stdin);
	int t;
	cin >> t;
	while ( t-- ) {
		int n, m;
		cin >> n >> m;
		
		deque<int> dq;
		int num;
		for ( int i = 0; i < n; ++i ) {
			cin >> num;
			dq.push_back(num);
		}
		
		deque<int>::iterator it = dq.begin();
		/* It fails
		// eliminate smaller nums.
		int threshold = dq[m].num;
		while ( it != dq.end() ) {
			if ( it->num < threshold ) {
				it = dq.erase(it); 
			} else {
				++it;
			}
		}
		*/

		int time = 0;
		while ( !dq.empty() ) {
			int ed = findMax(dq, dq[m]);
			if ( ed == m ) {
				++time;
				break;
			}
			
			for ( int i = 0; i < ed; ++i ) {
				if ( m == 0 ) {
					m = dq.size();
				}
				--m;
				int fr = dq.front();
				dq.pop_front();
				dq.push_back(fr);
			}
			
			dq.pop_front();
			--m;
			++time;
			
			/*
			it = dq.begin();
			for ( ; it != dq.end(); ++it ) {
				cout << *it << " ";
			}
			cout << endl << time << " " << m << endl;
			*/
		}
		
		cout << time << endl;
	}
	
	return 0;
}

