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

ll pow10(int k) {

    ll r=1;
    for (int i=0; i<k; i++) r*=10;
    return r;

}

void solve() {

    int a,b,c; cin>>a>>b>>c;

    // x = 10^(a-1) -> smallest a-digit number, purely a power of 10

    // y = 10^(b-1) + 10^(c-1)
    // - 10^(b-1) alone guarantees y has exactly b digits (since c <= b,
    //   adding 10^(c-1) never carries into an extra digit)
    // - the "+10^(c-1)" term is what forces gcd(x,y) to have exactly c digits

    // gcd(x,y) = gcd(10^(a-1), 10^(b-1)+10^(c-1))
    //          = 10^(c-1) * gcd(10^(a-c), 10^(b-c)+1)
    // the second factor is always 1 because (10^(b-c)+1) is odd and not
    // divisible by 5, so it shares no prime factors with 10^(a-c) (only 2s and 5s)
    // => gcd(x,y) = 10^(c-1), which has exactly c digits
    cout<<pow10(a-1)<<" "<<pow10(b-1)+pow10(c-1)<<"\n";

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