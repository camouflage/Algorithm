#include<iostream>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;

struct state {
    short num[8];
    string op;
};

struct state opa(struct state& input) {
    struct state temp;
    for ( int i = 0; i < 4; ++i ) {
        temp.num[i] = input.num[i + 4];
    }
    for ( int i = 4; i < 8; ++i ) {
        temp.num[i] = input.num[i - 4];
    }
    temp.op = input.op + 'A';
    return temp;
}

struct state opb(struct state& input) {
    struct state temp;
    temp.num[0] = input.num[3];
    temp.num[4] = input.num[7];
    for ( int i = 0; i < 3; ++i ) {
        temp.num[i + 1] = input.num[i];
        temp.num[i + 5] = input.num[i + 4];
    }
    temp.op = input.op + 'B';
    return temp;
}

struct state opc(struct state& input) {
    struct state temp;
    temp.num[0] = input.num[0];
    temp.num[3] = input.num[3];
    temp.num[4] = input.num[4];
    temp.num[7] = input.num[7];

    temp.num[1] = input.num[5];
    temp.num[2] = input.num[1];
    temp.num[6] = input.num[2];
    temp.num[5] = input.num[6];
    temp.op = input.op + 'C';
    return temp;
}

int cantor(short a[]) {
    int factorial[8] = {5040, 720, 120, 24, 6, 2, 1, 1};
    bool b[8];
    for ( int i = 0; i < 8; ++i ) {
        b[i] = 0;
    }
    int can = 0;

    for ( int i = 0; i < 8; ++i ) {
        int count = 0;
        for ( int j = 0; j < a[i] - 1; ++j ) {
            if ( b[j] == 0 ) {
                ++count;
            }
        }
        can += count * factorial[i];
        b[a[i] - 1] = 1;
    }

    return can;
}

int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    while ( scanf("%d", &n) ) {
        if ( n == - 1 ) {
            break;
        }

        struct state final;
        struct state init;
        scanf("%hd%hd%hd%hd%hd%hd%hd%hd", &final.num[0], &final.num[1], &final.num[2], &final.num[3],
				&final.num[4], &final.num[5], &final.num[6], &final.num[7]);
        
        for ( int i = 0; i < 4; ++i ) {
            init.num[i] = i + 1;
            init.num[i + 4] = 8 - i;
        }
        init.op = "";

        queue<struct state> q;
        bool visit[40320];
        int flag = 0;
        q.push(init);
        for ( int i = 0; i < 40320; ++i ) {
            visit[i] = 0;
        }
		visit[cantor(init.num)] = 1;
		
        while ( !q.empty() ) {
            struct state front = q.front();
			q.pop();

            int equal = 1;
            for ( int i = 0; i < 8; ++i ) {
                if ( front.num[i] != final.num[i] ) {
                    equal = 0;
                    break;
                }
            }

            if ( equal == 1 ) {
                final = front;
                flag = 1;
                break;
            }

            if ( front.op.length() > n ) {
                break;
            }

            struct state temp;
			int can;

            temp = opa(front);
			can = cantor(temp.num);
            if ( visit[can] == 0 ) {
				visit[can] = 1;
                q.push(temp);
            }

            temp = opb(front);
			can = cantor(temp.num);
            if ( visit[can] == 0 ) {
				visit[can] = 1;
                q.push(temp);
            }

            temp = opc(front);
			can = cantor(temp.num);
            if ( visit[can] == 0 ) {
				visit[can] = 1;
                q.push(temp);
            }
        }

        if ( flag ) {
            cout << final.op.length() << " " << final.op << endl;

        } else {
            cout << "-1" << endl;
        }

    }

    return 0;
}

/* 0.36s Using two integers
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;

struct state {
    int up;
    int down;
    int level;
    string op;
};

struct state opa(struct state input) {
    struct state temp;
    temp.up = input.down;
    temp.down = input.up;
    temp.level = input.level + 1;
    temp.op = input.op + "A";
    return temp;
}

struct state opb(struct state input) {
    struct state temp;
    int upOne = input.up % 10;
    int downOne = input.down % 10;
    temp.up = upOne * 1000 + input.up / 10;
    temp.down = downOne * 1000 + input.down / 10;
    temp.level = input.level + 1;
    temp.op = input.op + "B";
    return temp;
}

struct state opc(struct state input) {
    struct state temp;
    int upOne = input.up % 10;
    int downOne = input.down % 10;
    int upTen = input.up / 10 % 10;
    int downTen = input.down / 10 % 10;
    int upHundred = input.up / 100 % 10;
    int downHundred = input.down / 100 % 10;
    temp.up = input.up / 1000 * 1000 + downHundred * 100 + upHundred * 10 + upOne;
    temp.down = input.down / 1000 * 1000 + downTen * 100 + upTen * 10 + downOne;
    temp.level = input.level + 1;
    temp.op = input.op + "C";
    return temp;
}


int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    while ( cin >> n ) {
        if ( n == - 1 ) {
            break;
        }

        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        cin >> x1 >> x2 >> x3 >> x4
            >> y1 >> y2 >> y3 >> y4;

        struct state final;
        final.up = x1 * 1000 + x2 * 100 + x3 * 10 + x4;
        final.down = y1 * 1000 + y2 * 100 + y3 * 10 + y4;
        struct state init;
        init.up = 1234;
        init.down = 8765;
        init.op = "";
        init.level = 0;

        if ( init.up == final.up && init.down == final.down ) {
            cout << 0 << endl;
            continue;
        }

        queue<struct state> q;
        map<int, bool> mp;
        int flag = 0;
        q.push(init);
        mp[init.up * 10000 + init.down] = 1;
        
        while ( !q.empty() ) {
            struct state front = q.front();
            q.pop();

            if ( front.level >= n ) {
                break;
            }

            struct state temp;
            int tempInt;

            temp = opa(front);
            tempInt = temp.up * 10000 + temp.down;
            if ( temp.up == final.up && temp.down == final.down ) {
                final = temp;
                flag = 1;
                break;
            }
            if ( mp.find(tempInt) == mp.end() ) {
                q.push(temp);
                mp[tempInt] = 1;
            }

            temp = opb(front);
            tempInt = temp.up * 10000 + temp.down;
            if ( temp.up == final.up && temp.down == final.down ) {
                final = temp;
                flag = 1;
                break;
            }
            if ( mp.find(tempInt) == mp.end() ) {
                q.push(temp);
                mp[tempInt] = 1;
            }

            temp = opc(front);
            tempInt = temp.up * 10000 + temp.down;
            if ( temp.up == final.up && temp.down == final.down ) {
                final = temp;
                flag = 1;
                break;
            }
            if ( mp.find(tempInt) == mp.end() ) {
                q.push(temp);
                mp[tempInt] = 1;
            }
        }

        if ( flag ) {
            cout << final.level << " " << final.op << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
*/
