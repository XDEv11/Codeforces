#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

namespace D {
	int n;
	vector<int> v(n);
	set<int> st{};

	void dfs(int i, int t, int s = 0) {
		if (i == n) st.insert(s);
		else if (i == t) dfs(i + 1, t, s);
		else {
			dfs(i + 1, t, s + v[i]);
			dfs(i + 1, t, s);
			dfs(i + 1, t, s - v[i]);
		}
	}

	void solve() {
		cin >> n;
		v.assign(n, {});
		for (auto& x : v) cin >> x;

		for (int i{0}; i < n; ++i) {
			st.clear();
			dfs(0, i);
			if (st.find(v[i]) != st.end()) return cout << "YES\n"s, []{}();
		}
		cout << "NO\n"s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();

	return 0;
}
