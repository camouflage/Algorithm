#include<iostream>
#include<cstring>
using namespace std;

struct pos {
	int x;
	int y;
};

void DFS(struct pos init, bool visit[5][6], int v[30], bool& flag, int& count) {
	if ( flag == 1 ) {
		return;
	}
	
	visit[init.x][init.y] = 1;
	v[count] = init.x * 6 + init.y + 1;
	++count;
	
	if ( count == 30 ) {
		flag = 1;
	}
	
	/* Direction choosing is quite tricky.
	 * It hugely affects the efficiency of the algorithm.
	 */
	int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	for ( int i = 0; i < 8; ++i ) {
		if ( flag == 0 && visit[init.x + x[i]][init.y + y[i]] == 0 &&
			 init.x + x[i] >= 0 && init.x + x[i] <= 4 &&
			 init.y + y[i] >= 0 && init.y + y[i] <= 5 ) {
			struct pos newPos;
			newPos.x = init.x + x[i];
			newPos.y = init.y + y[i];
			DFS(newPos, visit, v, flag, count);
		}
	}
	
	if ( flag == 0 ) {
		visit[init.x][init.y] = 0;
		--count;
	}
}

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	while ( cin >> n && n != -1 ) {
		struct pos init;
		init.x = (n - 1) / 6;
		init.y = (n - 1) % 6;
		
		bool visit[5][6];
		bool flag = 0;
		int count = 0;
		memset(visit, 0, sizeof(visit));
		int v[30];
		
		DFS(init, visit, v, flag, count);
		
		for ( int i = 0; i < 29; ++i ) {
			cout << v[i] << " ";
		}
		cout << v[29] << endl;
	}
}

