//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<ll> b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		map<int, int> mp{};
		for (auto& x : a) {
			vector<int> pf{};
			int t{x};
			for (int f{2}; f * f <= x; ++f) {
				if (t % f == 0) {
					pf.push_back(f);
					while (t % f == 0) t /= f;
				}
			}
			if (t > 1) pf.push_back(t);
			for (auto& f : pf) {
				if (++mp[f] > 1) return cout << "0\n", []{}();
			}
		}

		ll ans{numeric_limits<ll>::max()};
		for (int i{0}; i < n; ++i) {
			auto x{a[i]};
			x += 1;
			vector<int> pf{};
			int t{x};
			for (int f{2}; f * f <= x; ++f) {
				if (t % f == 0) {
					pf.push_back(f);
					while (t % f == 0) t /= f;
				}
			}
			if (t > 1) pf.push_back(t);
			for (auto& f : pf) {
				if (mp.count(f)) ans = min(ans, b[i]);
			}
		}

		auto mn{min_element(b.begin(), b.end())};
		if (count(b.begin(), b.end(), *mn) == 1) {
			int i{distance(b.begin(), mn)};

			auto x{a[i]};
			vector<int> pf{};
			int t{x};
			for (int f{2}; f * f <= x; ++f) {
				if (t % f == 0) {
					pf.push_back(f);
					while (t % f == 0) t /= f;
				}
			}
			if (t > 1) pf.push_back(t);
			for (auto& f : pf) mp.erase(f);

			for (auto& [k, _] : mp) {
				ans = min(ans, b[i] * (k - a[i] % k));
			}
		}

		sort(b.begin(), b.end());
		ans = min(ans, b[0] + b[1]);

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
