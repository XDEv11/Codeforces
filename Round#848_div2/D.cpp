//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll mod{998244353};

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b) {
    long long res{1};
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

/* exists when a and mod are coprime */
long long inv_mod(long long a) {
    return power_mod(a, mod - 2);
}

void solve() {
	int n;
	cin >> n;
	vector<char> v1(n), v2(n);
	for (auto& x : v1) cin >> x;
	for (auto& x : v2) cin >> x;

	int k{0};
	for (int i{0}; i < n; ++i) k += (v1[i] != v2[i]);
	if (k == 0) return cout << "0\n", []{}();

	// f(n) = 1 + f(n - 1)
	vector<ll> c(n + 1); // f(i) = c[i] + d[i] * f(n - 1)
	c[n] = 1;
	for (int i{n - 1}; i - 1 >= 0; --i) c[i] = (n + (n - i) * c[i + 1]) % mod * inv_mod(i) % mod;

	vector<ll> f(n + 1); f[0] = 0;
	for (int i{1}; i <= n; ++i) f[i] = (c[i] + f[i - 1]) % mod;

	cout << f[k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
