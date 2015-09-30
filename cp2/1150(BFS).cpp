#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct state {
    int up;
    int down;
    int level;
    char op[11];
};

struct state opa(struct state input) {
    struct state temp;
    temp.up = input.down;
    temp.down = input.up;
    temp.level = input.level + 1;
    /*
    strcpy(temp.op, input.op);
    strcat(temp.op, "A");
    */
    int cx = snprintf(temp.op, sizeof(temp.op), "%s", input.op);
    snprintf(temp.op + cx, sizeof(char) + 1, "A");
    return temp;
}

struct state opb(struct state input) {
    struct state temp;
    int upOne = input.up % 10;
    int downOne = input.down % 10;
    temp.up = upOne * 1000 + input.up / 10;
    temp.down = downOne * 1000 + input.down / 10;
    temp.level = input.level + 1;
    int cx = snprintf(temp.op, sizeof(temp.op), "%s", input.op);
    snprintf(temp.op + cx, sizeof(char) + 1, "B");
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
    int cx = snprintf(temp.op, sizeof(temp.op), "%s", input.op);
    snprintf(temp.op + cx, sizeof(char) + 1, "C");
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
        snprintf(init.op, sizeof(init.op), "");
        init.level = 0;

        queue<struct state> q;
        map<int, bool> mp;
        int flag = 0;
        q.push(init);
        while ( !q.empty() ) {
            struct state front = q.front();
            q.pop();
            if ( front.level >= n ) {
                break;
            }

            int mpInt = front.up * 10000 + front.down;
            mp[mpInt] = 1;
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
            }
        }

        if ( flag ) {
            cout << final.level << " " << final.op << endl;
        } else {
            cout << "-1" << endl;
        }
        // cout << input.up << " " << input.down << " " << input.op << endl;
    }

    return 0;
}
