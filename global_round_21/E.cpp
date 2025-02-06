//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod{1000000007};
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
const int maxn{400000};
const vector<long long> fac{[](){
	vector<long long> v(maxn + 1);
	v[0] = v[1] = 1;
	for (int i{2}; i <= maxn; ++i) v[i] = v[i - 1] * i % mod;
	return v;
}()};

void solve() {
	int n;
	cin >> n, ++n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	for (int i{0}; i < n && v[i]; ++i) {
		ans = (ans + fac[i + v[i]] * inv_mod(fac[i + 1]) % mod * inv_mod(fac[v[i] - 1]) % mod) % mod;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
