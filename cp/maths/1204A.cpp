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

    // the highest set bit will contribute its (index/2) to our k
    // but if it is at an even index and there is atleast one other set bit present anywhere
    // then the answers bumps up to k+1 cause we include the highest set bit this time
    // but this is only when the set bit is prpesent at an even index (this is a power of 4)

    string s; cin>>s;

    int setbits=count(s.begin(),s.end(),'1');
    int msbidx=s.size()-1;
    
    int k=(msbidx+1)/2;
    if ((msbidx%2)==0 && setbits>1) k++;

    cout<<k<<endl;

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