#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int a,b; cin>>a>>b;

    if (a%b==0) { cout<<0<<endl; return; }
    cout<<b*(a/b + 1)-a<<endl;

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