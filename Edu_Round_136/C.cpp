//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod{998244353};

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

const vector<long long> fac{[](){
	vector<long long> v(121);
	v[0] = 1;
	for (int i{1}; i <= 120; ++i) v[i] = v[i - 1] * i % mod;
	return v;
}()};

long long Cmn(int m, int n) {
	return fac[m] * inv_mod(fac[n]) % mod * inv_mod(fac[m - n]) % mod;
};

void solve() {
	int n;
	cin >> n;

	long long a{0}, b{0};
	for (int i{n}; i >= 2; i -= 4) {
		a = (a + Cmn(i - 1, 1 + (i - 2) / 2)) % mod;
		if (i >= 4) b = (b + Cmn(i - 2, 2 + (i - 4) / 2)) % mod;
		if (i >= 4) {
			b = (b + Cmn(i - 3, 1 + (i - 4) / 2)) % mod;
			if (i >= 6) a = (a + Cmn(i - 4, 2 + (i - 6) / 2)) % mod;
		}
	}
	cout << a << ' ' << b << " 1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
