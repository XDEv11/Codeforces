#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> gt(n, 0);
	for (int i{0}; i < m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (u > v) swap(u, v);
		++gt[u];
	}
	int ans{count(gt.begin(), gt.end(), 0)};

	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 3) cout << ans << '\n';
		else {
			int u, v;
			cin >> u >> v, --u, --v;
			if (u > v) swap(u, v);

			if (op == 1) {
				if (!gt[u]) --ans;
				++gt[u];
			} else {
				--gt[u];
				if (!gt[u]) ++ans;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
