#include <iostream>
typedef long long ll;
using namespace std;

int constexpr maxn = 1e6 + 6, mod = 1e9 + 7;
int f[maxn], ifa[maxn], q;

int binpow(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if (b & 1)
            ans = ((ll) ans * a) % mod;
        a = ((ll) a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void fgen() {
    f[0] = 1;
    for (int i = 1; i < maxn; ++i)
        f[i] = ((ll)f[i - 1] * i) % mod;
}


void ifgen() {
    ifa[maxn - 1] = binpow(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; --i)
        ifa[i] = ((ll) ifa[i + 1] * (i + 1)) % mod;
}
int main() {
    fgen();
    ifgen();
    cin >> q;
    while (q--) {
        int n, r;
        cin >> n >> r;
        int ans = f[n];
        ans = ((ll) ans * ifa[r]) % mod;
        ans = ((ll) ans * ifa[n - r]) % mod;
        cout << ans << endl;
    }
    return 0;
}