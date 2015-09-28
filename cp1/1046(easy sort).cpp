#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct info {
    int st;
    int ed;
    int time;
    double num;
};

bool cmp(struct info a, struct info b) {
    if ( a.num == b.num ) {
        if ( a.time == b.time ) {
            return a.ed < b.ed;
        }
        return a.time > b.time;
    }
    return a.num > b.num;
}

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    for ( int r = 1; r <= t; ++r ) {
        cout << "Result for run " << r << ":" << endl;
        int total;
        int period;
        int min;
        cin >> total >> period >> min;

        int plane[301];
        for ( int i = 1; i <= total; ++i ) {
            cin >> plane[i];
        }

        struct info a[45150];  // (1 + 300) * 300 / 2;
        int n = 0;
        for ( int i  = 1; i <= total - min + 1; ++i ) {
            for ( int j = i + min - 1; j <= total; ++j ) {
                a[n].st = i;
                a[n].ed = j;
                a[n].time = j - i + 1;
                double count = 0;
                for ( int k = i; k <= j; k++ ) {
                    count += plane[k];
                }
                a[n].num = count / a[n].time;
                ++n;
            }
        }
        /*
        for ( int i = 0; i < n; ++i ) {
            cout << a[i].st << "-" << a[i].ed << " " << a[i].num << endl;
        }
        */
        sort(a, a + n, cmp);
        int outNum = std::min(period, n);
        for ( int i = 0; i < outNum; ++i ) {
            // cout << a[i].st << "-" << a[i].ed << " " << a[i].num << endl;
            cout << a[i].st << "-" << a[i].ed << endl;
        }
    }
}
