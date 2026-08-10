#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int a,b; cin>>a>>b;
    int s = max(2*min(a,b),max(a,b));
    cout<<s*s<<endl;

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