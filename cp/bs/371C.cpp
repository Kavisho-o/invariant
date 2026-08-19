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
// #define pb            push_back
#define eb            emplace_back
#define fi            first
#define se            second
#define sz(x)         (int)(x).size()
#define rep(i,a,b)    for(int i=(a); i<(b); ++i)
#define rrep(i,a,b)   for(int i=(a); i>=(b); --i)
#define each(x,v)     for(auto& x : v)

auto chmin = [](auto& a, auto b){ return b<a ? a=b,true : false; };
auto chmax = [](auto& a, auto b){ return b>a ? a=b,true : false; };

ll cost(ll k, int b, int s, int c, int nb, int ns, int nc, int pb, int ps, int pc){

    ll res=0;
    if (k*b>nb) res+=(k*b-nb)*pb;
    if (k*s>ns) res+=(k*s-ns)*ps;
    if (k*c>nc) res+=(k*c-nc)*pc;
    return res;

}

void solve() {

    // string S; cin>>S;

    // int b=0,s=0,c=0;
    // for (char C: S) {
    //     if (C=='B') b++;
    //     if (C=='S') s++;
    //     if (C=='C') c++;
    // }

    // int nb,ns,nc; cin>>nb>>ns>>nc;
    // int pb,ps,pc; cin>>pb>>ps>>pc;
    // ll r; cin>>r;

    // ll res=0;
    // while (true){

    //     if (ns==0 && nb==0 && nc==0){ res+=(r/(pb*b+ps*s+pc*c)); break; }

    //     (nb>=b) ? nb-=b : (r-=(1LL*b-nb)*pb, nb=0);
    //     (ns>=s) ? ns-=s : (r-=(1LL*s-ns)*ps, ns=0);
    //     (nc>=c) ? nc-=c : (r-=(1LL*c-nc)*pc, nc=0);

    //     if (r>=0) res++;
    //     else break;

    // }

    // cout<<res<<endl;

    // this works fine as the brute force but doesnt pass for given constraints 
    // so binary search : we choose k number of hamburgers and see if we can afford that 
    // over a monotonic range of costs up until r

    string S; cin>>S;

    int b=0,s=0,c=0;
    for (char C: S) {
        if (C=='B') b++;
        if (C=='S') s++;
        if (C=='C') c++;
    }

    int nb,ns,nc; cin>>nb>>ns>>nc;
    int pb,ps,pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;

    // SAMPLE SPACE -> r can be upto 10^12, min cost : 3, max(nb,ns,nc) = 100
    // so 10^12 / 3 ~ 4*10^12

    ll l=0, rt=4*1e12;
    while (l<rt){

        ll mid=l+(rt-l+1)/2; // round up to avoid infinite loop
        if (cost(mid,b,s,c,nb,ns,nc,pb,ps,pc)>r) rt=mid-1;
        else l=mid;

        // cout<<l<<endl;

    }
    cout<<l<<endl;

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