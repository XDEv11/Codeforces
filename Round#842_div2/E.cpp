//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b, long long mod) {
    long long res{1};
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

/* exists when a and mod are coprime */
long long inv_mod(long long a, long long mod) {
    return power_mod(a, mod - 2, mod);
}

void solve() {
	using ll = long long;

	int n, M;
	cin >> n >> M;

	vector<ll> fac(3 * n + 1), inv(3 * n + 1);
	fac[0] = 1;
	for (ll i{1}; i <= 3 * n; ++i) fac[i] = (fac[i - 1] * i) % M;
	for (ll i{0}; i <= 3 * n; ++i) inv[i] = inv_mod(fac[i], M);
	auto Cmn{[&fac, &inv, &M](int m, int n) {
		return fac[m] * inv[n] % M * inv[m - n] % M;
	}};

	ll ans{0};

	ll cnt1{(fac[2 * n] * 2 - fac[n]) % M};
	ans = (ans + 1 * (cnt1 - 1)) % M;

	ll cnt2{(Cmn(2 * n, n) * fac[n] % M * fac[2 * n] % M * 2) % M};
	for (int i{0}; i <= n; ++i) {
		cnt2 = (cnt2 - Cmn(n, i) * Cmn(n, n - i) % M * Cmn(2 * n - i, n) % M * fac[n] % M * fac[n] % M * fac[n] % M) % M;
	}
	ans = (ans + 2 * (cnt2 - cnt1)) % M;

	ll cnt3{fac[3 * n]};
	ans = (ans + 3 * (cnt3 - cnt2)) % M;

	cout << (ans + M) % M << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
