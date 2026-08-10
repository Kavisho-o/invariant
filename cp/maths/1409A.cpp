#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll a,b; cin>>a>>b;

    ll dif=abs(a-b);
    cout<<dif/10+(dif%10!=0)<<endl;

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