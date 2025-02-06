#include <iostream>
#include <vector>
#include <optional>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	int k{0};
	vector<optional<int>> ans(n, nullopt);
	vector<bool> valid(n, true);
	for (int i{0}; i < n; ++i)
		if (valid[v[i]])
			ans[i] = v[i], ++k, valid[v[i]] = false;

	vector<int> bad{};

	for (int i{0}; i < n; ++i)
		if (!ans[i] && valid[i]) ans[i] = i, valid[i] = false, bad.push_back(i);

	for (int i{0}, j{0}; ; ++i, ++j) {
		while (i < n && ans[i]) ++i;
		while (j < n && !valid[j]) ++j;
		if (!(i < n)) break;
		ans[i] = j, valid[j] = false;
	}

	if (bad.size() == 1 && ans[bad[0]] == bad[0]) {
		for (int i{0}; i < n; ++i)
			if (ans[i] == v[bad[0]]) swap(ans[i], ans[bad[0]]);
	} else {
		for (int i{0}; i + 1 < bad.size(); ++i)
			swap(ans[bad[i]], ans[bad[i + 1]]);
	}

	cout << k << '\n';
	for (auto& x : ans) cout << x.value() + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
