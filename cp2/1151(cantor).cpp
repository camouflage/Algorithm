#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<cstdlib>
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

void revCantor(int can, short a[8]) {
    int factorial[8] = {5040, 720, 120, 24, 6, 2, 1, 1};
    bool b[8];
    for ( int i = 0; i < 8; ++i ) {
        b[i] = 0;
    }

    for ( int i = 0; i < 8; ++i ) {
        int quotient = can / factorial[i];
        cout << can << " " << quotient << " ";
        while ( b[quotient] == 1 ) {
            ++quotient;
        }
        b[quotient] = 1;
        a[i] = quotient + 1;
        can = can % factorial[i];
        cout << can << endl;
    }
}

int main() {
    freopen("a.txt", "r", stdin);
    int n;
    while ( cin >> n ) {
        if ( n == - 1 ) {
            break;
        }

        struct state final;
        struct state init;
        cin >> final.num[0] >> final.num[1] >> final.num[2] >> final.num[3]
            >> final.num[4] >> final.num[5] >> final.num[6] >> final.num[7];
        
        for ( int i = 0; i < 4; ++i ) {
            init.num[i] = i + 1;
            init.num[i + 4] = 8 - i;
        }
        init.op = "";

        short a[8] = {1,2,3,4,5,7,6,8};
        short b[8];
        cout << cantor(a) << endl;
        revCantor(300, b);

        cout << endl;

        /*
        struct state node[40320];
        int factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

        vector<struct state> v;
        v.push_back(init);
        set<int> st;
        int flag = 0;
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
            st.insert(mpInt);

            struct state temp;
            int tempInt;

            temp = opa(front, count);
            tempInt = temp.up * 10000 + temp.down;
            if ( st.find(tempInt) == st.end() ) {
                v.push_back(temp);
            } else {
                --count;
            }

            temp = opb(front, count);
            tempInt = temp.up * 10000 + temp.down;
            if ( st.find(tempInt) == st.end() ) {
                v.push_back(temp);
            } else {
                --count;
            }

            temp = opc(front, count);
            tempInt = temp.up * 10000 + temp.down;
            if ( st.find(tempInt) == st.end() ) {
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
        */
    }

    return 0;
}
