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

ll n,k; 
vector<ll> a; 
vector<ll> b; 

bool poss(ll mid){

    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
    for (ll i=0; i<n; i++) pq.push({a[i]/b[i],a[i]%b[i],b[i]});

    rep(minute,0,k){

        auto [deadline,remainder,power_usage] = pq.top(); pq.pop();
        if (deadline<minute) return 0;

        ll new_battery=mid+remainder;
        ll new_deadline=deadline+new_battery/power_usage;
        ll new_remainder=new_battery%power_usage;

        pq.push({new_deadline,new_remainder,power_usage});

    }

    return 1;

}

void solve() {

    // we have to minimize the power output

    // binary search on minimum possible power output 
    // range for x -> its minimum size is 0 (when no charger is even needed,
    // i.e. all laptops survive on their own till minute k-1)
    // and max size is bounded by max(b[i]*(k-1)) across all laptops
    // (because with x that big, even the worst laptop only ever needs a single charge
    // to survive the whole contest, so going any higher never helps)

    // i.e. x -> [0, max(b[i]*(k-1))]

    // to check if current power x is feasible -->
    // we have to check for each minute, i.e., loop over each value from 0 to k-1
    // greedily, we will pick the laptop with the earliest deadline for the current minute
    // we can maintain a priority queue for this task

    // normally you would insert all the a[i]s into the pq
    // and keep updating them for every min
    // but thats too expensive

    // TRICK ---|>
    // we append the deadlines into the pq (after how many minutes this curr laptop will die)
    // at every minute, we pick the laptop with the earliest deadline greedily
    // and extend its deadline and push it back into the priority queue

    // but theres a subtle catch here, storing only deadlines will lead to loss of the values (battery %)
    // caused by the division of a[i] and b[i], so its important to store the remainder in a different variable 
    // along with the prior deadline in priority queue
    // also since we are purely storing deadlines and not the elems itself in the pq
    // knowing b[i]'s for each is also a task
    // so we have to store each b[i] as well

    // so new pq will store -> {deadline, remainder, power-usage or b[i]}

    // also note: pq must be rebuilt FRESH inside poss() every time, since each
    // binary search check has to start from the original state, not continue
    // from whatever the previous poss() call left behind

    // and when extending a laptop's deadline after charging it, the new deadline
    // is the OLD deadline plus however many whole minutes the new battery
    // (remainder + x) adds — not just the new battery divided by b[i] on its own,
    // since that would throw away all the whole minutes already banked

    cin>>n>>k;

    a.resize(n);
    b.resize(n);

    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];

    ll s=0, e=*max_element(all(b))*(k-1);
    if (!poss(e)) {cout<<-1<<endl; return ;}

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