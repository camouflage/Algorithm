#include<iostream>
#include<map>
#include<cstdlib>
#include<cstring>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::strcmp;
using std::string;

/*
struct strComp {
   bool operator()(const char* a, const char* b) const {
      return strcmp(a, b) < 0;
   }
};

int main() {
    freopen("a.txt", "r", stdin);

    int n;
    while ( cin >> n ) {
        if ( n == 0 ) {
            break;
        }

        char id[13];
        char ip[16];
        typedef map<char*, char*, strComp> myMap;
        myMap ipId;
        myMap mainMJ;
        for ( int i = 0; i < n; i++ ) {
            cin >> id >> ip;

            if ( ipId.find(ip) == ipId.end() ) {
                ipId[ip] = id;
            } else {
                mainMJ[ipId[ip]] = id;
            }
        }
        
        for ( myMap::iterator ita = ipId.begin(); ita != ipId.end(); ++ita ) {
            cout << ita->first << " " << ita->second << endl;
        }

        myMap::iterator it = mainMJ.begin();
        for ( ; it != mainMJ.end(); ++it ) {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
    }
}
*/

struct strComp {
    bool operator()(const char* a, const char* b) const {
        return strcmp(a, b) < 0;
    }
};

int main() {
    // freopen("a.txt", "r", stdin);

    int n;
    while ( cin >> n ) {
        if ( n == 0 ) {
            break;
        }

        string id;
        string ip;
        typedef map<string, string> myMap;
        myMap ipId;
        myMap mainMJ;
        for ( int i = 0; i < n; i++ ) {
            cin >> id >> ip;

            if ( ipId.find(ip) == ipId.end() ) {
                ipId[ip] = id;
            } else {
                mainMJ[ipId[ip]] = id;
            }
        }

        myMap::iterator it = mainMJ.begin();
        for ( ; it != mainMJ.end(); ++it ) {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
    }
}
