#include<iostream>
#include<cstring>
using namespace std;

struct trie {
    struct trie* a[10];
    bool end;
    trie() {
        for ( int i = 0; i < 10; ++i ) {
            a[i] = NULL;
            end = false;
        }
    }
};

bool insert(struct trie* root, char* temp) {
    for ( int i = 0; i < strlen(temp); ++i ) {
        if ( i == strlen(temp) - 1 && root->a[temp[i] - '0'] != NULL ) {
            return false;
        }

        if ( root->a[temp[i] - '0'] == NULL ) {
            root->a[temp[i] - '0'] = new trie();
        } else if ( root->a[temp[i] - '0']->end == true ) {
            return false;
        }
        root = root->a[temp[i] - '0'];
    }
    root->end = true;
    return true;
}

void release(struct trie* root) {
    for ( int i = 0; i < 10; ++i ) {
        if ( root->a[i] != NULL ) {
            release(root->a[i]);
        }
    }
    delete root;
}

int main() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        struct trie* root = new trie();
        bool flag = 1;
        for ( int i = 0; i < n; ++i ) {
            char temp[11];
            cin >> temp;
            if ( insert(root, temp) == false ) {
                flag = 0;
            }
        }

        if ( flag ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        release(root);
    }
    return 0;
}
