#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    // A value at the end contributes once, while a value between two zeros
    // contributes twice. Therefore, for n >= 3, place all m in an interior
    // position (0, m, 0) so every unit of m is counted twice.

    int n,m; cin>>n>>m;
    
    if (n==1) cout<<0<<endl;
    else if (n==2) cout<<m<<endl;
    else cout<<2*m<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}