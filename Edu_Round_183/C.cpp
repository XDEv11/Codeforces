//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		vector<int> ps(n + 1);
		for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] + (v[i] == 'a' ? 1 : -1);

		vector<vector<int>> tmp(2 * n + 1);
		for (int i{n}; i >= 0; --i) tmp[n + ps[i]].push_back(i);

		int ans{n};
		for (int i{0}; i < n; ++i) {
			int t{n + ps[i] + ps[n]};
			if (clamp(t, 0, 2 * n) != t) continue;

			while (!tmp[t].empty() && tmp[t].back() < i) tmp[t].pop_back();
			if (!tmp[t].empty()) ans = min(ans, tmp[t].back() - i);
		}

		cout << (ans == n ? -1 : ans) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
