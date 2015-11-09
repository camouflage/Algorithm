#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct cylinder {
    double x;
    double y;
};

bool cmp(const struct cylinder& a, const struct cylinder& b) {
    return a.x < b.x;
}

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    for ( int k = 1; k <= t; ++k ) {
        int n;
        cin >> n;
        struct cylinder pos[10];
        for ( int i = 0; i < n; ++i ) {
            cin >> pos[i].x;
            pos[i].y = 1.0;
        }

        sort(pos, pos + n, cmp);

        while ( --n >= 1 ) {
            /*
            for ( int j = 0; j <= n; ++j ) {
                cout << pos[j].x << " " << pos[j].y << endl;
            }
            cout << endl;
            */
            
            for ( int i = 0; i < n; ++i ) {
                double x0 = pos[i].x;
                double x1 = pos[i + 1].x;
                double y0 = pos[i].y;
                double y1 = pos[i + 1].y;
                double hyp = sqrt( pow(x0 - x1, 2) + pow(y0 - y1, 2) );
                double alpha1 = acos(hyp / 4);
                double alpha2, alpha;
                if ( y1 >= y0 ) {
                    alpha2 = atan( (y1 - y0) / (x1 - x0) );
                    alpha = alpha1 + alpha2;
                    pos[i].x = x0 + 2 * cos(alpha);
                    pos[i].y = y0 + 2 * sin(alpha);
                } else {
                    alpha2 = atan( (y0 - y1) / (x1 - x0) );
                    alpha = alpha1 + alpha2;
                    pos[i].x = x1 - 2 * cos(alpha);
                    pos[i].y = y1 + 2 * sin(alpha);
                }
            }
        }
        printf("%d: %.4f %.4f\n", k, pos[0].x, pos[0].y);
    }
}
