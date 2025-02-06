//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int m;
	cin >> m;
	vector<vector<int>> v(m);
	for (int i{0}; i < m; ++i) {
		int n;
		cin >> n;
		v[i].resize(n);
		for (auto& x : v[i]) cin >> x;
	}

	vector<int> ans(m);
	set<int> st{};
	for (int i{m - 1}; i >= 0; --i) {
		bool f{false};
		for (auto& x : v[i]) {
			if (!f && !st.count(x)) ans[i] = x, f = true;
			st.insert(x);
		}
		if (!f) return cout << "-1\n", []{}();
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
