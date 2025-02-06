//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;
	const ll mod{998244353};

	int n;
	cin >> n;
	vector<int> v(n - 1);
	for (auto& x : v) cin >> x;

	vector<ll> f(n); f[0] = 1;
	for (int i{1}; i < n; ++i) f[i] = f[i - 1] * (i - v[i - 1]) % mod;

	ll ans{0};
	for (int i{1}; i < n; ++i) cout << (ans = (ans * i + !v[i - 1] * f[i - 1]) % mod) << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
