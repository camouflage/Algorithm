#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

int main() {
    // freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;

        string s;
        map<string, bool> mp;
        for ( int i = 0; i < n; i++ ) {
            cin >> s;
            mp[s] = 1;
        }

        int count = 0;
        map<string, bool>::iterator it = mp.begin();
        for ( ; it != mp.end(); ++it ) {
            if ( it->second ) {
                string t = it->first;
                for ( int i = 0; i < t.length(); ++i ) {
                    if ( t[i] == 'A' ) {
                        t[i] = 'T';
                    } else if ( t[i] == 'T' ) {
                        t[i] = 'A';
                    } else if ( t[i] == 'C' ) {
                        t[i] = 'G';
                    } else if ( t[i] == 'G' ) {
                        t[i] = 'C';
                    }
                }

                if ( mp.find(t) != mp.end() && mp[t] == 1 ) {
                    it->second = 0;
                    mp[t] = 0;
                    ++count;
                }
            }
        }

        cout << count << endl;
    }
}
