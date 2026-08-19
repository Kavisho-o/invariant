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

bool poss(ll dmg, vector<ll>& v, ll h, ll n){

    // cout<<"dmg: "<<dmg<<endl;

    ll dmgDealt=0;
    for (ll i=0; i<n-1; i++) dmgDealt+=min(dmg,v[i+1]-v[i]);
    dmgDealt+=dmg;  // max damage for last second

    // cout<<"dmgDealt: "<<dmgDealt<<endl;

    return dmgDealt>=h;

}

void solve() {

    ll n,h; cin>>n>>h;
    vector<ll> v(n);
    for (ll i=0; i<n; i++) cin>>v[i];

    // cout<<"INPUTS: "<<n<<" "<<h<<"\n";

    // SAMPLE SPACE -> [1,h]
    ll s=1, e=h, res;
    while (s<=e){

        ll mid=s+(e-s)/2;
        if (poss(mid,v,h,n)){
            res=mid;
            e=mid-1;
        }
        else s=mid+1;

    }
    cout<<res<<endl;

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