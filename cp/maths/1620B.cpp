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

    ll w,h; cin>>w>>h;

    ll k; cin>>k;
    vector<ll> l1(k);
    for (ll i=0; i<k; i++) cin>>l1[i];

    ll l; cin>>l;
    vector<ll> l2(l);
    for (ll i=0; i<l; i++) cin>>l2[i];
    
    ll m; cin>>m;
    vector<ll> b1(m);
    for (ll i=0; i<m; i++) cin>>b1[i];
    
    ll n; cin>>n;
    vector<ll> b2(n);
    for (ll i=0; i<n; i++) cin>>b2[i];

    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());
    sort(b1.begin(),b1.end());
    sort(b2.begin(),b2.end());

    ll maxdiffhori = max(l1[(ll)l1.size()-1]-l1[0],l2[(ll)l2.size()-1]-l2[0]);
    ll maxdiffvert = max(b1[(ll)b1.size()-1]-b1[0],b2[(ll)b2.size()-1]-b2[0]);

    cout<<max(maxdiffhori*h,maxdiffvert*w)<<endl;
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