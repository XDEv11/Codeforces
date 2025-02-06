#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const long long mod{1000000007};

/* Iterative Function to calculate (a^b) % mod in O(log b) */
long long power_mod(long long a, long long b) { 
	long long res{1};
	while (b > 0) {
		if (b & 1) res = (res * a) % mod; 
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
	int n, k;
	cin >> n >> k;

	vector<long long> c(n + 1); // C(n, i)
	c[0] = 1;
	for (long long i{1}; i <= n; ++i)
		c[i] = c[i - 1] * (n - i + 1) % mod * inv_mod(i) % mod;

	long long s1{0}, s2{0};
	for (int i{0}; i < n; i += 2) s1 = (s1 + c[i]) % mod;
	if (n & 1) s1 = (s1 + c[n]) % mod;
	for (int i{0}; i <= n; ++i) s2 = (s2 + c[i]) % mod;

	long long ans{1};
	for (int i{0}; i < k; ++i) {
		ans = s1 * ans % mod;
		if (!(n & 1)) ans = (ans + power_mod(s2, i)) % mod;
	}

	cout << (ans + mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
