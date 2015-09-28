#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    double d;
    int rev;
    double t;
    int count = 1;
    while ( cin >> d >> rev >> t ) {
        if ( rev == 0 ) {
            break;
        }

        double dist = 3.1415927 * d * rev / 63360;
        t /= 3600;
        double mph = dist / t;
        cout << "Trip #" << count << ": " << fixed << setprecision(2) << dist
             << " " << mph << endl;
        ++count;
    }

    return 0;
}
