//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k;
	if (!(cin >> n >> m >> k)) return false;
	vector<set<int>> f(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		f[u].insert(v);
		f[v].insert(u);
	}
	if (f[0].size() + k > n - 1) return cout << "impossible\n", true;

	set<int> st{};
	for (int v{1}; v < n; ++v) {
		if (f[v].size() == n - 2 && !f[v].count(0)) {
			if (!k--) return cout << "impossible\n", true;
			continue;
		}
		st.insert(v);
	}
	
	while (k--) {
		int w{-1};
		for (auto& v : st) {
			if (f[0].count(v)) continue;
			w = v;
			break;
		}
		if (w == -1) break;

		queue<int> qu{};
		qu.push(w), st.erase(w);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto it{st.begin()}; it != st.end(); ) {
				auto ni{next(it)};
				if (!f[u].count(*it)) qu.push(*it), st.erase(it);
				it = ni;
			}
		}
	}

	return cout << (st.empty() ? "possible\n" : "impossible\n"), true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
