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

    int c,s; cin>>c>>s;
    
    // since cost is k^2 burles, it makes sense to use as many raditors as i can to minimize cost
    ll rad=min(c,s);

    // also to minimize cost, it is best to evenly distribute the sections across all radiators
    ll distbt=s/rad;
    ll rem=s%rad;

    // suppose 10 is the sum of sections and 3 is the amount of radiators
    // then we distribute 3 sections to each radiator to get
    // 3 | 3 | 3
    
    // now 1 section remains, we cant add more radiators since this is max
    // we have to evenly add rem amount to each of these (which is 1 here)
    // so 
    // 4 | 3 | 3

    // amount of normal prethought radiators (the ones with 3 sections here) = rad-rem ; their cost = distbt*distbt ; 3^2
    // amount of modified radiators (the ones with 4 sections here) = rem ; their cost = (distbt+1)*(distbt+1) ; 4^2

    ll res= (rad-rem)*distbt*distbt + rem*(distbt+1)*(distbt+1);
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