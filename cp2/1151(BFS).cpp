#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

struct state {
    int num;
    int up;
    int down;
    int level;
    char op;
    int pre;
};

struct state opa(struct state input, int& count) {
    struct state temp;
    temp.up = input.down;
    temp.down = input.up;
    temp.level = input.level + 1;
    temp.pre = input.num;
    temp.num = count;
    count++;
    temp.op = 'A';
    return temp;
}

struct state opb(struct state input, int& count) {
    struct state temp;
    int upOne = input.up % 10;
    int downOne = input.down % 10;
    temp.up = upOne * 1000 + input.up / 10;
    temp.down = downOne * 1000 + input.down / 10;
    temp.level = input.level + 1;
    temp.pre = input.num;
    temp.num = count;
    count++;
    temp.op = 'B';
    return temp;
}

struct state opc(struct state input, int& count) {
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
    temp.pre = input.num;
    temp.num = count;
    count++;
    temp.op = 'C';
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
        init.op = '-';
        init.level = 0;
        init.num = 0;
        init.pre = -1;

        vector<struct state> v;
        map<int, bool> mp;
        int flag = 0;
        v.push_back(init);
        int fp = 0;
        int count = 1;
        while ( !v.empty() ) {
            struct state front = v[fp];
            if ( front.up == final.up && front.down == final.down ) {
                final = front;
                flag = 1;
                break;
            }
            if ( front.level >= n ) {
                break;
            }

            int mpInt = front.up * 10000 + front.down;
            mp[mpInt] = 1;
            struct state temp;
            int tempInt;

            temp = opa(front, count);
            tempInt = temp.up * 10000 + temp.down;
            if ( mp.find(tempInt) == mp.end() ) {
                v.push_back(temp);
            } else {
                --count;
            }

            temp = opb(front, count);
            tempInt = temp.up * 10000 + temp.down;
            if ( mp.find(tempInt) == mp.end() ) {
                v.push_back(temp);
            } else {
                --count;
            }

            temp = opc(front,count);
            tempInt = temp.up * 10000 + temp.down;
            if ( mp.find(tempInt) == mp.end() ) {
                v.push_back(temp);
            } else {
                --count;
            }

            ++fp;
        }

        if ( flag ) {
            string ans;
            int i = final.num;
            while ( i != -1 ) {
                ans += v[i].op;
                i = v[i].pre;
            }

            cout << final.level << " ";
            for ( int i = final.level - 1; i >= 0; --i ) {
                cout << ans[i];
            }
            cout << endl;

        } else {
            cout << "-1" << endl;
        }

        // cout << input.up << " " << input.down << " " << input.op << endl;
    }

    return 0;
}
