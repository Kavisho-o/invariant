#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using vi  = vector<int>;
using vl  = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int INF  = 2e9;
const ll  LINF = 4e18;
const ll  MOD  = 1e9+7;

#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define pb            push_back
#define eb            emplace_back
#define fi            first
#define se            second
#define sz(x)         (int)(x).size()
#define rep(i,a,b)    for(int i=(a); i<(b); ++i)
#define rrep(i,a,b)   for(int i=(a); i>=(b); --i)
#define each(x,v)     for(auto& x : v)

auto chmin = [](auto& a, auto b){ return b<a ? a=b,true : false; };
auto chmax = [](auto& a, auto b){ return b>a ? a=b,true : false; };

void solve() {

    ll n,k; cin>>n>>k;
    if (n==1) { cout<<0<<endl; return; }
    if (n-1>k*(k+1)/2) {cout<<-1<<endl; return; }

    // sample space -> [1,k]
    ll s=1, e=k, Sn; 
    while (s<=e){

        ll mid=s+(e-s)/2;
        Sn=mid*(2*k-mid-1)/2;

        if (Sn==n-1) {cout<<mid<<endl; return ;}
        else if (Sn>n-1) e=mid-1;
        else s=mid+1;

    }

    if (n-1 >= s*(s+1)/2) {
        cout<<s<<endl;
        return;
    }

    cout<<-1<<endl;

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