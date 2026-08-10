#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,k; cin>>n>>k;
    map<int,int,greater<int>> mp;

    for (int i=0; i<n; i++) {

        int t; cin>>t;
        mp[t]++;

    }

    int cnt=0;
    int sets=0;
    for (auto it=mp.begin(); it!=mp.end(); ){

        if (it->second%2==0) {

            cnt+=it->second;
            sets+=it->second/2;
            it=mp.erase(it);

        }   

        else if (it->second%2==1 && it->second!=1){

            cnt+=it->second-1;
            sets+=(it->second-1)/2;
            it->second=1;
            ++it;

        }

        else ++it;

        if (sets>=(n+1)/2) break;

    }

    for (auto it: mp){

        if (sets<(n+1)/2) {
            cnt++;
            sets++;
        }
        else break;

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