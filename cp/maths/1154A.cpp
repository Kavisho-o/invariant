#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll p,q,r,s; cin>>p>>q>>r>>s;

    ll abc=(p+q+r+s)/3;
    
    if (p==abc) cout<<p-q<<" "<<p-r<<" "<<p-s<<endl;
    else if (q==abc) cout<<q-p<<" "<<q-r<<" "<<q-s<<endl;
    else if (r==abc) cout<<r-q<<" "<<r-p<<" "<<r-s<<endl;
    else cout<<s-q<<" "<<s-r<<" "<<s-p<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}