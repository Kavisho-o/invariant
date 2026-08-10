#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    // first we find out the min no of coins needed 
    // to equalize everyone

    // need = (mx - other1) + (mx - other2)
    //  = 2*mx - (other1 + other2)
    //  = 2*mx - (a+b+c - mx)     [since other1+other2 = sum - mx]
    //  = 3*mx - sum

    int mx = max({a, b, c});
    int need = 3*mx-(a+b+c);

    n -= need;

    if (n < 0) {
        cout << "NO\n";
        return;
    }
    if (n % 3 == 0) cout << "YES\n";
    else cout << "NO\n";
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