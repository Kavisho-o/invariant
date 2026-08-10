#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll n,m,k; cin>>n>>m>>k;
    vector<ll> v(n); for(int i=0; i<n; i++) cin>>v[i];
    sort(v.rbegin(),v.rend());

    ll f=v[0];
    ll s=v[1];

    ll res=(m/(k+1))*(f*k+s) + (m%(k+1))*f;
    cout<<res<<endl;

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