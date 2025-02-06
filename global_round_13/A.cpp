#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int cnt{static_cast<int>(count(v.begin(), v.end(), 1))};

	while (q--) {
		int op, var;
		cin >> op >> var;
		if (op == 1) {
			--var;
			v[var] = 1 - v[var];
			if (v[var] == 0) --cnt;
			else ++cnt;
		} else if (op == 2) cout << (cnt >= var ? 1 : 0) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
