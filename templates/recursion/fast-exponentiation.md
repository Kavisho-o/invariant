## fast exponentiation (mod pow)
- tc: O(log n)
- sc: O(1)

## pattern
- "calculate a^n"
- "modular exponentiation"
- "power with large exponent"
- "pow(x, n)"
- "binary exponentiation"
- "fast exponentiation"
- "a^b % mod"

## algo
Initialize `ans = 1`
While exponent > 0:
- If exponent is odd → multiply `ans` by `base`
- Square the `base`
- Divide exponent by 2
Return `ans`

## intuition
Instead of multiplying `base` `n` times, repeatedly square the base and halve the exponent.

Example:

2^13

13 = 1101₂
   = 8 + 4 + 1

Therefore:

2^13 = 2^8 × 2^4 × 2^1

We generate powers by squaring:

2^1 → 2^2 → 2^4 → 2^8

For every `1` in the binary representation of the exponent,
multiply that power into `ans`.

### key idea
- `exp & 1` → check if current exponent bit is `1`
- `base = base * base` → move to the next power
- `exp >>= 1` → move to the next binary bit

So:

13 → 6 → 3 → 1 → 0

This gives O(log n) time.

## black box
```cpp
ll modPow(ll base, ll exp, ll mod) {

    ll ans = 1;
    base %= mod;

    while (exp > 0) {

        if (exp & 1) ans = (ans * base) % mod;
    
        base = (base * base) % mod;
        exp >>= 1;

    }
    return ans;
}