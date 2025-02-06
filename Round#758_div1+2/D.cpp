//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

static const long long mod{998244353};
static vector<long long> fac{}, inv{};
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

long long C_mod(int n, int m) {
	if (m < 0 || m > n) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
	int n;
	cin >> n;
	array<int, 3> l, r; l.fill(0), r.fill(0);
	bool flag{true};
	int uc{0};
	for (int i{0}; i < n; ++i) {
		char cl, cr;
		cin >> cl >> cr;
		switch (cl) {
			break; case 'B' : ++l[0];
			break; case 'W' : ++l[1];
			break; case '?' : ++l[2];
		}
		switch (cr) {
			break; case 'B' : ++r[0];
			break; case 'W' : ++r[1];
			break; case '?' : ++r[2];
		}
		if (cl != '?' && cl == cr) flag = false;
		if (cl == '?' && cr == '?') ++uc;
	}
	if (n == 1) return cout << "1\n"s, []{}();

	long long ans{0};
	for (int i{0}; i <= l[2]; ++i) {
		ans = (ans + C_mod(l[2], i) * C_mod(r[2], l[0] + i - r[1])) % mod;
	}
	long long d{0};
	if (flag) {
		d = power_mod(2, uc);
		if ((!l[0] && !r[1]) && (!l[1] && !r[0])) d -= 2;
		else if ((!l[0] && !r[1]) || (!l[1] && !r[0])) --d;
	}
	cout << ((ans - d + mod) % mod) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	const int maxn{100000};
	fac.resize(maxn + 1), inv.resize(maxn + 1);
	fac[0] = 1;
	for (int i{1}; i <= maxn; ++i) fac[i] = fac[i - 1] * i % mod;
	for (int i{0}; i <= maxn; ++i) inv[i] = inv_mod(fac[i]);

	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
