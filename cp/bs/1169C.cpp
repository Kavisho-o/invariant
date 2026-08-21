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

bool poss(ll ops, ll n, ll m, vector<ll>& a){

    ll prev=0;
    rep(i,0,n){

        if (a[i]+ops<m) {

            if (prev<=a[i]) prev=a[i];
            else if (prev<=a[i]+ops) prev=prev;
            else return 0;

        }

        else{

            if (prev<=(a[i]+ops)%m) prev=prev;
            else if (prev<=a[i]) prev=a[i];
            else prev=prev;
            
        }

    }

    return 1;

}

void solve() {

    // binary search on no. of operations (to be minimized)
    // sample space -> [0,1e11]

    // since we have the option to pick any k elements to apply this operation to
    // the number of operations (obtained from binary search's mid), let x
    // can be applied to every element

    // but we can choose how many operations to apply to each
    // let the no. of operations we gotta apply to one such elem(let ai) be yi
    // then yi : [0,x]
    // and the result of these operation;  new value of ai(let bi) -> { bi = (ai+yi) % m } 
    
    // since we have to minimize x here, we need the min no. of operations for which 
    // b1<=b2<=b3<=.....<=bn
    
    // for each elem ai, the reachable values are -> [ai,ai+x]
    // if { ai+x < m } ------> no mod operation performed -> bi : [ai,ai+x]
    // if { ai+x >= m} ------> bi : [ai,ai+1,ai+2,....,m-1,0,1,....,(ai+x)%m]

    // GREEDY --------|> 
    // from left to right, we keep track of prev (prev bi, start=0)
    // at each index, the value bi>=prev
    // to pick elems greedily (for future cases), we will try to keep it minimum but >= prev

    // to cases arise here

    // 1. no wrap (ai+x<m) --> ordinary interval : [ai,ai+x]
    // if prev<=ai -> prev is smaller than whole interval -> bi=ai
    // if prev<=ai+x -> prev lies in the interval -> bi=prev
    // else -> prev is not in the interval at all -> not possible

    // 2. wrap (ai+x>=m) -> [ai,m-1]+[0,(ai+x)%m]
    // if prev<=(ai+x)%m -> bi=prev
    // else if prev<=ai -> interval not reachable here -> pick lowest reachable -> bi=ai
    // else (prev lies in [ai,m-1]) -> bi=prev

    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    ll s=0, e=1e11;
    while (s<e){

        ll mid=s+(e-s)/2;
        if (poss(mid,n,m,v)) e=mid;
        else s=mid+1;

    }

    cout<<e<<endl;

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