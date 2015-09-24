#include<iostream>
#include<stack>
#include<deque>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::stack;

int main() {
    // freopen("a.txt", "r", stdin);
    int n;
    while ( cin >> n ) {
        if ( n == 0 ) {
            break;
        }

        int a[200002];
        for ( int i = 0; i < n; i++ ) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
            a[y] = x;
        }

        deque<int> dq;
        stack<int> st;
        for ( int i = 1; i <= 2 * n; i++ ) {
            dq.push_back(i);
        }

        while ( !dq.empty() ) {
            if ( st.empty() ) {
                if ( a[dq.front()] == dq.back() ) {
                    dq.pop_front();
                    dq.pop_back();
                } else {
                    st.push(dq.front());
                    dq.pop_front();
                }
            } else {
                int top = st.top();
                if ( a[top] == dq.front() ) {
                    dq.pop_front();
                    st.pop();
                } else {
                    st.push(dq.front());
                    dq.pop_front();
                }
            }
        }

        if ( st.empty() ) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
