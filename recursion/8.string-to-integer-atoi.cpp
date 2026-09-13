#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")

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

class Solution {
public:
    long long readDigits(const string& s, int i, int sign, long long res) {

        if (i >= (int)s.size() || !isdigit(s[i])) return res;

        res = res * 10 + (s[i] - '0');

        if (sign == 1 && res > INT_MAX) return INT_MAX;
        if (sign == -1 && -res < INT_MIN) return INT_MIN;

        return readDigits(s, i + 1, sign, res);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // 2. Sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Recursively read digits, clamping as we go
        long long res = readDigits(s, i, sign, 0);

        return (int)(sign * res);
    }
};

// #define ll long long

// class Solution {
// public:

//     ll help(string s){

//         // cout<<s<<endl;

//         int lead0=0;
//         while (s[lead0]=='0') lead0++;
//         s=s.substr(lead0);

//         ll res=0;
//         ll placevalue=1;

//         for (int i=s.size()-1; i>=0; i--){

//             if (placevalue>INT_MAX) return (ll)INT_MAX+1;
//             res=res+(s[i]-'0')*placevalue;
//             placevalue*=10;

//         }

//         return res;

//     }

//     int myAtoi(string s) {

//         if (s.size()==0) return 0;

//         int whitespace=0;
//         while (whitespace<s.size() && s[whitespace]==' ') whitespace++;
//         s=s.substr(whitespace);

//         bool neg=s[0]=='-'?1:0;
//         if (neg || s[0]=='+') s=s.substr(1);

//         int keep=0;
//         while (keep<s.size() && s[keep]>='0' && s[keep]<='9') keep++;
//         s=s.substr(0,keep);

//         ll res=help(s);
//         if (neg) res*=-1;
//         // if (res==-INT_MAX && neg) return INT_MIN;
        
//         if (res<INT_MIN) return INT_MIN;
//         if (res>INT_MAX) return INT_MAX;
//         return (int)res;
        
//     }
// };

