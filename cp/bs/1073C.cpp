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

ll n;
string s;
ll x,y;
vector<ll> prefx,prefy;

bool poss(ll L){
    
    if (L==0) return (prefx[n]==x && prefy[n]==y);  

    for (ll l=0; l+L<=n; l++){

        ll r=l+L;

        // outside window contributions: 
        ll owx=prefx[n]-(prefx[r]-prefx[l]);
        ll owy=prefy[n]-(prefy[r]-prefy[l]);

        // now remaining job is to be done by our window
        ll needx=x-owx;
        ll needy=y-owy;

        // check poss using manhattan dist
        ll manh_dist=llabs(needx)+llabs(needy);
        if (manh_dist<=L && (L-manh_dist)%2==0) return true;

    }

    return false;

}

void solve() {

    // binary search for the len of changed segment (needs to be minimized) -> a window of size mid
    // possible len ~ [0,n]

    // since the cost of changing is only the idx(max elem changed) - idx(min elem changed)
    // it creates a window in which we can apply any no. of operations 
    // and everything outside the window remains the same
    
    // let the window be [l,r) then len of window is r-l, let L
    // so we can modify L moves inside the window

    // now the sum contribution from outside the window and window contribution (we choose) 
    // should be equal to (x,y)

    // i.e., (contribution from window) = (x,y) - (contribution from outside window)

    // contribution from window has L unit steps
    // to reach (x,y) we need atleast the manhattan dist --> |needx|+|needy|
    // if there are more elems, then they must cancel out --> this can be done by just checking
    // if the remaining no. of elems if even (cause we can just make them cancel out by changing elems)

    // i.e., manhattan = |needX| + |needY|
    // feasible  ⟺  manhattan <= L   AND   (L - manhattan) % 2 == 0

    // contribution from outside the window can be done using prefix sums
    // prefx[i] = net x-displacement after first i moves
    // prefy[i] = net y-displacement after first i moves
    // contribution of window [l,r) = (prefx[r]-prefx[l],prefy[r]-prefy[l])
    // contribution from outside window = contribution from entire string - (prefx[r]-prefx[l],prefy[r]-prefy[l])
    //                                  = (prefx[n],prefy[n]) - (prefx[r]-prefx[l],prefy[r]-prefy[l])

    cin>>n>>s>>x>>y;
    prefx.assign(n+1,0);
    prefy.assign(n+1,0);

    for (ll i=0; i<n; i++) {

        prefx[i+1]=prefx[i] + ((s[i]=='R')-(s[i]=='L'));
        prefy[i+1]=prefy[i] + ((s[i]=='U')-(s[i]=='D'));

    }

    if (!poss(n)) { cout<<-1<<endl; return ; }

    ll s=0, e=n;
    while (s<e){

        ll mid=s+(e-s)/2;
        if (poss(mid)) e=mid;
        else s=mid+1;

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