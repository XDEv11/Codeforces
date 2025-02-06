//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>

#include <cstdlib>

using namespace std;

namespace {
	int query(int u, int v) {
		cout << "? " << (u + 1) << ' ' << (v + 1) << endl;
		int w; cin >> w;
		if (w == -1) exit(EXIT_SUCCESS);
		return (w - 1);
	}
	void answer(vector<pair<int, int>>& ans) {
		cout << "! ";
		for (auto& [u, v] : ans) cout << (u + 1) << ' ' << (v + 1) << ' ';
		cout << endl;
	}
	void solve() {
		int n;
		cin >> n;

		vector<pair<int, int>> ans{};
		set<int> st{}; st.insert(0);
		for (int x{1}; x < n; ++x) {
			if (st.count(x)) continue;
			queue<pair<int, int>> qu{};
			qu.emplace(0, x);
			while (!qu.empty()) {
				auto [u, v]{qu.front()}; qu.pop();
				int w{query(u, v)};
				if (w != u) {
					if (!st.count(w)) qu.emplace(u, w);
					qu.emplace(w, v);
				} else ans.emplace_back(u, v), st.insert(v);
			}
		}

		answer(ans);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
