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

        char id[20][13];
        char ip[20][16];
        typedef map<char*, char*, strComp> myMap;
        myMap ipId;
        myMap mainMJ;
        for ( int i = 0; i < n; i++ ) {
            cin >> id[i] >> ip[i];

            if ( ipId.find(ip[i]) == ipId.end() ) {
                ipId[ip[i]] = id[i];
            } else {
                mainMJ[ipId[ip[i]]] = id[i];
            }
        }

        myMap::iterator it = mainMJ.begin();
        for ( ; it != mainMJ.end(); ++it ) {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
    }
}

/*
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
*/
