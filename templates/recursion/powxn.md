# Binary Exponentiation (Pow(x, n))

- tc: O(log n)
- sc: O(log n) (recursion stack) / O(1) iterative variant

## pattern
- "calculate x^n"
- "power function"
- "pow(x, n)"
- "fast exponentiation"
- "exponentiation by squaring"
- "large exponent"
- "negative exponent"

## algo
- Base case → if n == 0 → return 1
- Recursively calculate `x^(n/2)`
- Square the result
- If n is odd → multiply by one extra `x`
- For negative n → replace `x` with `1/x` and make n positive
- Use `long long` for n to safely handle `INT_MIN`

## black box
```cpp
double help(double x, long long n) {

    if (n==0) return 1.0;

    double half = help(x,n/2);

    if (n%2) return half*half*x;
    return half*half;

}

double myPow(double x, int n) {

    long long N=n;

    if (N<0) {

        x=1/x;
        N=-N;

    }

    return help(x,N);

}
```

## intuition
- Don't multiply `x` `n` times → repeatedly divide the exponent by 2
- `x^n = x^(n/2) × x^(n/2)` when `n` is even
- `x^n = x^(n/2) × x^(n/2) × x` when `n` is odd
- Recursion calculates the half-power only once
- Squaring the half-power gives the full power
- Negative powers → `x^(-n) = (1/x)^n`

## mental model
```text
                x^n
                 |
             n == 0?
            /       \
          YES        NO
           |          |
           1       solve n/2
                      |
                   half
                  /    \
              n even   n odd
                |        |
            half²     half² × x
```
