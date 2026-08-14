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

    ll a,b,c; cin>>a>>b>>c;

    // total damage in a series of 7 blows = 9
    // so our sum of healths should be divisible by 9
    // also (sum/9) which is number of series 7 blows should be <= min(a,b,c)
    // cause if its not, one elem will end up becoming 0 before the 1hp thing
    // due to the triple blows
    // also it should be >=1 as it only fires the strong bullet starting at 7
    
    ll sum=a+b+c;
    (sum%9)==0 && (sum/9)<=min({a,b,c}) && (sum/9)>=1 ? cout<<"YES\n" : cout<<"NO\n";

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