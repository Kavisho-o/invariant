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

bool poss(ll mid, vector<ll>& a, vector<ll> b, ll n, ll k){

    for (int i=0; i<n; i++){

        __int128 req=(__int128)mid*a[i];
        if (req<=b[i]) b[i]-=req;
        else if (k>=req-b[i]) k-=(req-b[i]);
        else return false;

    }
    return true;
}                   

void solve() {

    ll n,k; cin>>n>>k;
    vector<ll> a(n); rep(i,0,n) cin>>a[i];
    vector<ll> b(n); rep(i,0,n) cin>>b[i];

    ll s=0;
    ll e=accumulate(all(b),0LL)+k;

    while (s<e){

        ll mid=s+(e-s+1)/2;
        if (poss(mid,a,b,n,k)) s=mid;
        else e=mid-1;

    }
    cout<<s<<endl;

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