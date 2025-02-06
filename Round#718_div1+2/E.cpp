#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MA(ll a, ll b) { return (a + b) % PM; }

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;
	if (n == 1) return cout << "1\n", []{}();

	ll ans{};
	for (int k{0}; k < 4; ++k) { // (P)?(CC)*(CP)+(P)*(C)?
		bool fp{k & 1}, lc{k & 2};
		ll s{lc * v[n - 1]}, t{fp * v[0]};
		for (int i{fp}; i < n - lc; ++i) t += v[i];

		int j{fp};
		while (j < n - 1 - lc && s + v[j] < t - v[j]) s += v[j], t -= v[j], j += 2;
		int i{fp};
		while (i < j && s < t) {
			ans = MA(ans, (j - i) / 2);
			s += v[i + 1], t -= v[i + 1], i += 2;
			while (i < j && !(s < t)) j -= 2, s -= v[j], t += v[j];
		}
	}
	for (int k{0}; k < 4; ++k) { // (P)?(C)(CC)*(CP)+(P)*(C)?
		bool fp{k & 1}, lc{k & 2};
		ll s{lc * v[n - 1]}, t{fp * v[0]};
		s += v[fp];
		for (int i{fp + 1}; i < n - lc; ++i) t += v[i];

		int j{fp + 1};
		while (j < n - 1 - lc && s + v[j] < t - v[j]) s += v[j], t -= v[j], j += 2;
		int i{fp + 1};
		while (i < j && s < t) {
			ans = MA(ans, (j - i) / 2);
			s += v[i + 1], t -= v[i + 1], i += 2;
			while (i < j && !(s < t)) j -= 2, s -= v[j], t += v[j];
		}
	}
	{ // (P)*(C)*
		ll s{}, t{};
		for (int i{0}; i < n; ++i) t += v[i];
		for (int i{n}; i >= 0 && s < t; --i) {
			ans = MA(ans, 1);
			if (i) s += v[i - 1], t -= v[i - 1];
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
