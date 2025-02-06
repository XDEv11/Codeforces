#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> p(n + 1, n), nxt(n);
	for (int i{n - 1}; i >= 0; --i) {
		nxt[i] = p[v[i]];
		p[v[i]] = i;
	}

	int a{-1}, b{-1}, na{n}, nb{n}, ans{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == a || v[i] == b) {
			if (v[i] == a) na = nxt[i];
			if (v[i] == b) nb = nxt[i];
			continue;
		}
		++ans;
		if (na >= nb) a = v[i], na = nxt[i];
		else b = v[i], nb = nxt[i];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
