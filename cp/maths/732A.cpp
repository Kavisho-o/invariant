#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int k,r; cin>>k>>r;
    // 10 unit currency doesnt matter, it will always cancel everything out
    // that is not at the unit place because the currency is unlimited
    
    int K=k;
    int unit=K%10;
    if (unit==0) {cout<<1<<endl; return;}

    int cnt=1;
    while (unit!=r){

        cnt++;
        k+=K;
        unit=k%10;
        if (unit==0) {cout<<cnt<<endl; return;}

    }

    cout<<cnt<<endl;

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