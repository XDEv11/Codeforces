//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		while (true) {
			bool f{false};
			int c{};
			for (int i{0}; i < n; ++i) {
				if (v[i]) {
					if (++c > 2) f = true;
					int j{(i + 1) % n};
					v[j] = max(0, v[j] - v[i]);
				} else c = 0;
			}
			if (c) {
				for (int i{0}; i < n && v[i]; ++i) ++c;
				if (c > 2) f = true;
			}
			if (!f) break;
		}

		vector<int> ans{};
		for (int i{0}; i < n; ++i) {
			int j{(i - 1 + n) % n};
			if (v[j] == 0 && v[i]) ans.push_back(i + 1);
		}

		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
