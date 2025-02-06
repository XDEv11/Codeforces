//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(m);
		for (auto& x : v) cin >> x;

		vector<ll> t(n + 1);
		for (auto& x : v) ++t[x];
		for (int i{n - 1}; i >= 1; --i) t[i] += t[i + 1];

		ll ans{};
		for (int i{1}; i < n; ++i) {
			int j{n - i};
			if (i <= j) ans += (t[i] - 1) * t[j];
			else ans += t[i] * (t[j] - 1);
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
