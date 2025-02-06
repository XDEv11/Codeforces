#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> t{};
	t.push_back(v);
	while (true) {
		vector<int> cnt(n + 1, 0), nxt(n);
		for (auto& x : t.back()) ++cnt[x];
		for (int i{0}; i < n; ++i)
			nxt[i] = cnt[t.back()[i]];
		if (nxt == t.back()) break;
		t.push_back(move(nxt));
	}

	int q;
	cin >> q;
	while (q--) {
		int x, k;
		cin >> x >> k, --x;
		cout << t[min(int(t.size()) - 1, k)][x] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
