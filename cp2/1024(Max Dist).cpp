#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct node {
	int d;
	bool visited;
};

int main() {
	// freopen("a.txt", "r", stdin);
	
	int n, k;
	map< int, map<int, struct node> > mp;
	while ( cin >> n >> k ) {
		for ( int i = 0; i < n; ++i ) {
			int x, y;
			struct node n;
			cin >> x >> y >> n.d;
			n.visited = 0;
			mp[x][y] = n;
			mp[y][x] = n;
		}
	}

	vector<int> st;
	st.push_back(k);
	int dist[n + 1];
	for ( int i = 1; i <= n; ++i ) {
		dist[i] = 0;
	}
	
	for ( int j = 0; j < n - 1; ++j ) {
		int max = 0;
		int maxSt;
		map<int, struct node>::iterator maxIt;
		for ( int i = 0; i < st.size(); ++i ) {
			int startPoint = st[i];
			map<int, struct node> dest = mp[startPoint];
			map<int, struct node>::iterator it = dest.begin();
			for ( ; it != dest.end(); ++it ) {
				if ( it->second.visited == 0 && dist[startPoint] + it->second.d > max ) {
					max = dist[startPoint] + it->second.d;
					maxSt = startPoint;
					maxIt = it;
				}
			}
		}

		dist[maxIt->first] = max;
		mp[maxSt][maxIt->first].visited = 1;
		mp[maxIt->first][maxSt].visited = 1;
		st.push_back(maxIt->first);
		
		/*
		map< int, map<int, struct node> >::iterator out = mp.begin();
		for ( ; out != mp.end(); ++out ) {
			map<int, struct node> dest = out->second;
			map<int, struct node>::iterator in = dest.begin();
			for ( ; in != dest.end(); ++in ) {
				cout << out->first << " " << in->first << " " << in->second.d << " " << in->second.visited << endl; 
			}
		}
		
		for ( int i = 1; i <= n; ++i ) {
			cout << i << " " << dist[i] << endl;
		}
		
		for ( int i = 0; i < st.size(); ++i ) {
			cout << st[i] << " ";
		}
		cout << endl << endl;
		*/
	}
	
	int maxDist = 0;
	for ( int i = 1; i <= n; ++i ) {
		if ( dist[i] >= maxDist ) {
			maxDist = dist[i];
		}
	}
	cout << maxDist << endl;

	return 0;
}

