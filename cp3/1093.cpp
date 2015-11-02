#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int w1, r1, w2, r2, w3, r3, r4;
    int set = 1;
    while ( cin >> w1 >> r1 >> w2 >> r2 >> w3 >> r3 >> r4 ) {
        int w;
        cout << "Set number " << set << ":\n";
        while ( cin >> w && w != 0 ) {
            int price;
            int add = 0;
            if ( w <= w1 ) {
                price = w * r1;
                if ( (w1 + 1) * r2 < price ) {
                    price = (w1 + 1) * r2;
                    add = w1 + 1 - w;
                }
                if ( (w2 + 1) * r3 < price ) {
                    price = (w2 + 1) * r3;
                    add = w2 + 1 - w;
                }
                if ( (w3 + 1) * r4 < price ) {
                    price = (w3 + 1) * r4;
                    add = w3 + 1 - w;
                }
            } else if ( w <= w2 ) {
                price = w * r2;
                if ( (w2 + 1) * r3 < price ) {
                    price = (w2 + 1) * r3;
                    add = w2 + 1 - w;
                }
                if ( (w3 + 1) * r4 < price ) {
                    price = (w3 + 1) * r4;
                    add = w3 + 1 - w;
                }
            } else if ( w <= w3 ) {
                price = w * r3;
                if ( (w3 + 1) * r4 < price ) {
                    price = (w3 + 1) * r4;
                    add = w3 + 1 - w;
                }
            } else {
                price = w * r4;
            }

            printf("Weight (%d) has best price $%d (add %d pounds)\n", w, price, add);
        }

        ++set;
        cout << endl;
    }
}
