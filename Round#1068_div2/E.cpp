//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		vector<int> idx(n);
		for (int i{0}; i < n; ++i) idx[v[i]] = i;

		for (int i{0}; i < n - 1 - i; ++i) {
			int j{n - 1 - i};
			if (i >= j) break;

			auto op{[&](int x, int y) {
				cout << "? " << (x + 1) << ' ' << (y + 1) << endl;
				cin >> x;
				if (x == -1) exit(EXIT_SUCCESS);
				cin >> y, --x, --y;

				swap(v[x], v[y]);
				idx[v[x]] = x, idx[v[y]] = y;
			}};

			while (idx[i] != i || idx[j] != j) {
				if (idx[i] != i) op(idx[i], i);
				if (idx[j] != j) op(idx[j], j);
			}
		}
		cout << "!" << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
