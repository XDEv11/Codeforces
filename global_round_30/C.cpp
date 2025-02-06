//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <set>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m), c(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		for (auto& x : c) cin >> x;

		vector<pair<int, int>> t1{};
		vector<int> t0{};
		for (int i{0}; i < m; ++i) {
			if (c[i]) t1.emplace_back(b[i], c[i]);
			else t0.push_back(b[i]);
		}
		sort(t0.begin(), t0.end());
		sort(t1.begin(), t1.end());

		int ans{};
		multiset<int> s{};
		for (auto& x : a) s.insert(x);

		auto it{s.begin()};
		for (auto& [x, y] : t1) {
			while (it != s.end() && *it < x) ++it;
			if (it == s.end()) break;
			++ans;
			if (y > *it) {
				s.insert(y);
				auto ni{next(it)};
				s.erase(it);
				it = ni;
			}
		}

		it = s.begin();
		for (auto& x : t0) {
			while (it != s.end() && *it < x) ++it;
			if (it == s.end()) break;
			++ans, ++it;
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
