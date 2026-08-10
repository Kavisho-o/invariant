#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int k=n/2;
    if (k%2==1) {cout<<"NO"<<endl; return;}

    cout<<"YES"<<endl;

    for (int i=1; i<=k; i++) cout<<2*i<<" ";
    for (int i=1; i<k; i++) cout<<2*i-1<<" ";
    cout<<3*k-1<<endl;

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