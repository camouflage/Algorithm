#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// 保存节点信息
struct pos {
	int x;
	int y;
	int count;
};

// 比较函数，根据可达节点的数目进行比较
bool cmp(const struct pos& a, const struct pos& b) {
	return a.count < b.count;
}

void DFS(struct pos init, bool visit[8][8], int v[64], bool& flag, int& count) {
	// 搜索成功完成，退出
	if ( flag == 1 ) {
		return;
	}
	
	// 将该节点标记，并记录
	visit[init.x][init.y] = 1;
	v[count] = init.x * 8 + init.y + 1;
	++count;
	
	// 如果所有节点都被访问，则直接返回，不再进行探索
	if ( count == 64 ) {
		flag = 1;
		return;
	}
	
	// 8个方向的x, y坐标
	int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	struct pos a[8];
	// 可达节点的数目
	int valid = 0;
	for ( int i = 0; i < 8; ++i ) {
		// 下一个方向上节点的坐标
		a[valid].x = init.x + x[i];
        a[valid].y = init.y + y[i];
        // 如果下一个方向上的节点合法，则将其可达的节点初始化为0
        if ( a[valid].x >= 0 && a[valid].x <= 7 &&
        	 a[valid].y >= 0 && a[valid].y <= 7 &&
        	 !visit[a[valid].x][a[valid].y] ) {
            a[valid].count = 0;
        } else {
            continue;
        }
		
		// 计算下一个节点处可达节点的数目
		for ( int j = 0; j < 8; ++j ) {
			if ( a[valid].x + x[j] >= 0 && a[valid].x + x[j] <= 7 &&
				 a[valid].y + y[j] >= 0 && a[valid].y + y[j] <= 7 &&
				 !visit[a[valid].x + x[j]][a[valid].y + y[j]] ) {
				++a[valid].count;
			}
		}
		++valid;
	}
	// 按可达节点数目从小到大排序
	sort(a, a + valid, cmp);

	// 逐个探索下一个节点，从可达数最小的开始
	for ( int i = 0; i < valid; ++i ) {
		struct pos newPos;
		newPos.x = a[i].x;
		newPos.y = a[i].y;
		DFS(newPos, visit, v, flag, count);
	}
	
	// 回溯，将设定的访问信息复原
	visit[init.x][init.y] = 0;
	--count;
}

int main() {
	// freopen("a.txt", "r", stdin);
	int n;
	while ( cin >> n && n != -1 ) {
		// 初始化
		struct pos init;
		init.x = (n - 1) / 8;
		init.y = (n - 1) % 8;
		
		bool visit[8][8];
		bool flag = 0;
		int count = 0;
		memset(visit, 0, sizeof(visit));
		int v[64];
		
		DFS(init, visit, v, flag, count);
		
		// 输出
		for ( int i = 0; i < 63; ++i ) {
			cout << v[i] << " ";
		}
		cout << v[63] << endl;
	}
}

