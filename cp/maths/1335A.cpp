#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;  

    // range of a=[(n+1/2),n-1]
    // range of n : n-1 - (n+1)/2 + 1 = (n-1)/2
    cout<<(n-1)/2<<endl;

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