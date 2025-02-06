//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<pair<int, int>> ans{};
		set<int> p0{-1}, p1{-1};
		for (int i{0}; i < n; ++i) {
			if (v[i] == 0) p0.insert(i);
			else if (v[i] == 1) p1.insert(i);
		}
		int i{0};
		for (; i < n; ++i) {
			if (v[i] == 0) continue;
			int l0{*p0.rbegin()};
			if (l0 < i) break;

			if (v[i] == 1) {
				ans.emplace_back(i, l0);
				v[i] = 0, p1.erase(i), p0.insert(i);
				v[l0] = 1, p0.erase(l0), p1.insert(l0);
			} else if (v[i] == 2) {
				int l1{*p1.rbegin()};
				ans.emplace_back(i, l1);
				v[i] = 1, p1.insert(i);
				v[l1] = 2, p1.erase(l1);

				ans.emplace_back(i, l0);
				v[i] = 0, p1.erase(i), p0.insert(i);
				v[l0] = 1, p0.erase(l0), p1.insert(l0);
			}
		}
		for (; i < n; ++i) {
			if (v[i] == 1) continue;
			int l1{*p1.rbegin()};
			if (l1 < i) break;

			ans.emplace_back(i, l1);
			v[i] = 1, p1.insert(i);
			v[l1] = 2, p1.erase(l1);
		}

		cout << ans.size() << '\n';
		for (auto& [x, y] : ans) cout << (x + 1) << ' ' << (y + 1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
