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

ll calcN(ll mid){

    ll n=0;
    for (ll k=2; k*k*k<=mid; k++){

        // for (ll x=1; x<floor(mid/(k*k*k)); x++){
        //     if (x*k*k*k < mid) n++;
        // }

        n+=floor(mid/(k*k*k));

    }
    return n;

}

void solve() {

    ll m; cin>>m;

    // binary search for n for a given m :

    // for a current mid (n) -> 
    // values are for x(>=1) and k(>=2): x,xk, xk^2, xk^3
    // obv the max is xk^3
    // so if xk^3<n -> valid

    // to perform this -> we can fix k and check it for all possible x
    // possible x for a fix k -> 1,2,3,....,floor(n/k^3)
    // all possible k to loop over -> take min x (=1) 
    // then our check just becomes k^3<n -> k<n^(1/3) -> max k=floor(n^(1/3))

    // sample space -> [8,1e16]
    // 8 because thats the answer for the lowest m(=1) from a test case
    // 1e16 is more than safe for max m(=1e15)

    ll s=8, e=1e16, minN=-1;
    
    while (s<e){

        ll mid=s+(e-s)/2;
        ll N=calcN(mid);

        if (N>=m) e=mid;
        else s=mid+1;

    }

    if (calcN(s)==m) minN=s;
    cout<<minN<<endl;
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