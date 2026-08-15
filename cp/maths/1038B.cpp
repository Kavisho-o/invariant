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
    int n; cin >> n;
    if (n <= 2) { cout << "No\n"; return; }  // can't split into 2 non-empty sets meaningfully / gcd always 1

    // key idea: pick a single element d that is guaranteed to divide
    // total = n*(n+1)/2, regardless of whether n is odd or even.
    // d = (n+1)/2 works because:
    //   if n odd:  total = n * d        -> d divides total
    //   if n even: total = d * (n+1)    -> d divides total
    // putting {d} alone in S1 gives sum(S1)=d, sum(S2)=total-d,
    // and since d | total, d also divides (total-d) => gcd(S1,S2) >= d >= 2 for n>=3
    int d = (n + 1) / 2;

    cout << "Yes\n";

    // S1 = { d }
    cout << 1 << " " << d << "\n";

    // S2 = all other numbers from 1..n except d
    cout << n - 1 << " ";
    for (int i = 1; i <= n; i++) if (i != d) cout << i << " ";
    cout << "\n";
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