#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    vector<int> v(n);
    int badodds=0, badevens=0;

    for (int i=0; i<n; i++){

        cin>>v[i];
        if (i%2==1 && v[i]%2!=1) badodds++;
        if (i%2==0 && v[i]%2!=0) badevens++;

    }

    if (badodds!=badevens) cout<<-1<<endl;
    else cout<<badodds<<endl;

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