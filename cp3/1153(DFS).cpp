#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct pos {
	int x;
	int y;
	int count;
};

bool cmp(const struct pos& a, const struct pos& b) {
	return a.count < b.count;
}

void DFS(struct pos init, bool visit[8][8], int v[64], bool& flag, int& count) {
	if ( flag == 1 ) {
		return;
	}
	
	visit[init.x][init.y] = 1;
	v[count] = init.x * 8 + init.y + 1;
	++count;
	
	if ( count == 64 ) {
		flag = 1;
		return;
	}
	
	int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	struct pos a[8];
	int valid = 0;
	for ( int i = 0; i < 8; ++i ) {
		a[valid].x = init.x + x[i];
        a[valid].y = init.y + y[i];
        if ( a[valid].x >= 0 && a[valid].x <= 7 &&
        	 a[valid].y >= 0 && a[valid].y <= 7 &&
        	 !visit[a[valid].x][a[valid].y] ) {
            a[valid].count = 0;
        } else {
            continue;
        }
		
		for ( int j = 0; j < 8; ++j ) {
			if ( a[valid].x + x[j] >= 0 && a[valid].x + x[j] <= 7 &&
				 a[valid].y + y[j] >= 0 && a[valid].y + y[j] <= 7 &&
				 !visit[a[valid].x + x[j]][a[valid].y + y[j]] ) {
				++a[valid].count;
			}
		}
		++valid;
	}
	sort(a, a + valid, cmp);

	for ( int i = 0; i < valid; ++i ) {
		struct pos newPos;
		newPos.x = a[i].x;
		newPos.y = a[i].y;
		DFS(newPos, visit, v, flag, count);
	}
	
	visit[init.x][init.y] = 0;
	--count;
}

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	while ( cin >> n && n != -1 ) {
		struct pos init;
		init.x = (n - 1) / 8;
		init.y = (n - 1) % 8;
		
		bool visit[8][8];
		bool flag = 0;
		int count = 0;
		memset(visit, 0, sizeof(visit));
		int v[64];
		
		DFS(init, visit, v, flag, count);
		
		for ( int i = 0; i < 63; ++i ) {
			cout << v[i] << " ";
		}
		cout << v[63] << endl;
	}
}

