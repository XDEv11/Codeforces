//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<vector<int>> u(n);
		for (auto& v : u) {
			int m;
			cin >> m;
			v.resize(m);
			for (auto& x : v) cin >> x;

			vector<int> t{};
			set<int> st{};
			for (int j{m - 1}; j >= 0; --j) {
				if (st.count(v[j])) continue;
				t.push_back(v[j]), st.insert(v[j]);
			}
			v = move(t);
		}

		vector<int> ans{};
		while (true) {
			int mx{-1};
			for (int i{0}; i < n; ++i) {
				if (u[i].empty()) continue;
				if (mx == -1) { mx = i; continue; }

				bool f{};
				for (int j{0}; j < u[mx].size(); ++j) {
					if (j >= u[i].size()) { f = true; break; }
					else if (u[i][j] < u[mx][j]) { f = true; break; }
					else if (u[i][j] > u[mx][j]) break;
				}
				if (f) mx = i;
			}
			if (mx == -1) break;

			set<int> st{};
			for (int j{0}; j < u[mx].size(); ++j) ans.push_back(u[mx][j]), st.insert(u[mx][j]);

			u[mx] = {};
			for (int i{0}; i < n; ++i) {
				vector<int> t{};
				for (int j{0}; j < u[i].size(); ++j) {
					if (st.count(u[i][j])) continue;
					t.push_back(u[i][j]);
				}
				u[i] = move(t);
			}
		}

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
