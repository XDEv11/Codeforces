#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> pmx(n, numeric_limits<ll>::min()), pmn(n, numeric_limits<ll>::max());
	for (int k{0}; k <= 1; ++k) {
		ll s{};
		for (int i{k}; i < n; i += 2) {
			s = max(0ll, s) + v[i];
			pmx[i] = max(pmx[i], s);
			if (i + 1 < n) {
				s -= v[i + 1];
				pmx[i + 1] = max(pmx[i + 1], s);
			}
		}
	}
	for (int i{1}; i < n; ++i) pmx[i] = max(pmx[i], pmx[i - 1]);
	for (int k{0}; k <= 1; ++k) {
		ll s{};
		for (int i{k}; i < n; i += 2) {
			s = min(0ll, s) + v[i];
			pmn[i] = min(pmn[i], s);
			if (i + 1 < n) {
				s -= v[i + 1];
				pmn[i + 1] = min(pmn[i + 1], s);
			}
		}
	}
	for (int i{1}; i < n; ++i) pmn[i] = min(pmn[i], pmn[i - 1]);

	vector<ll> smx(n, numeric_limits<ll>::min()), smn(n, numeric_limits<ll>::max());
	for (int k{n - 1}; k >= n - 2; --k) {
		ll s{};
		for (int i{k}; i >= 0; i -= 2) {
			s = max(v[i], max(0ll, s) + v[i] - (i + 1 < n ? v[i + 1] : 0));
			smx[i] = max(smx[i], s);
		}
	}
	for (int i{n - 2}; i >= 0; --i) smx[i] = max(smx[i], smx[i + 1]);
	for (int k{n - 1}; k >= n - 2; --k) {
		ll s{};
		for (int i{k}; i >= 0; i -= 2) {
			s = min(v[i], min(0ll, s) + v[i] - (i + 1 < n ? v[i + 1] : 0));
			smn[i] = min(smn[i], s);
		}
	}
	for (int i{n - 2}; i >= 0; --i) smn[i] = min(smn[i], smn[i + 1]);

	ll ans{};
	for (int k{1}; k < n; ++k) {
		ans = max(ans, abs(pmx[k - 1] - smn[k]));
		ans = max(ans, abs(pmn[k - 1] - smx[k]));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
