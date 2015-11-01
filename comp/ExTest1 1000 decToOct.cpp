#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    while ( cin >> n && n != 0 ) {
        stringstream ss;
        ss << n;
        string s = ss.str();
        
        int num = 0;
        int base = 1;
        for ( int i = s.length() - 1; i >= 0; --i ) {
            if ( s[i] - '0' > 7 ) {
                num += base * (s[i] - '0' - 2);
            } else if ( s[i] - '0' > 2 ) {
                num += base * (s[i] - '0' - 1);
            } else {
                num += base * (s[i] - '0');
            }
            base *= 8;
        }
        cout << s << ": " << num << endl;
    }
}
