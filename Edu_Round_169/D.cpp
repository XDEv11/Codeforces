//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	const map<string, int> mp{[] {
		map<string, int> t{};
		t["BG"] = 0;
		t["BR"] = 1;
		t["BY"] = 2;
		t["GR"] = 3;
		t["GY"] = 4;
		t["RY"] = 5;
		return t;
	}()};
	const array<int, 6> op{5, 4, 3, 2, 1, 0};
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (auto& x : v) {
			string s{};
			cin >> s;
			x = mp.find(s)->second;
		}

		vector<array<int, 6>> pv(n);
		for (int k{0}; k < 6; ++k) pv[0][k] = -1;
		for (int i{0}; i < n; ++i) {
			if (i) pv[i] = pv[i - 1];
			pv[i][v[i]] = i;
		}
		vector<array<int, 6>> nx(n);
		for (int k{0}; k < 6; ++k) nx[n - 1][k] = n;
		for (int i{n - 1}; i >= 0; --i) {
			if (i + 1 < n) nx[i] = nx[i + 1];
			nx[i][v[i]] = i;
		}

		while (q--) {
			int i, j;
			cin >> i >> j, --i, --j;
			if (i > j) swap(i, j);

			bool f{false};
			if (op[v[i]] != v[j]) f = true;
			if (!f) {
				for (int k{0}; k < 6; ++k) {
					if (nx[i][k] == n || k == v[i] || k == op[v[i]]) continue;
					if (nx[i][k] < j) f = true;
				}
			}
			if (f) {
				cout << (j - i) << '\n';
				continue;
			}

			int mn{n};
			for (int k{0}; k < 6; ++k) {
				if (pv[i][k] == -1 || k == v[i] || k == op[v[i]]) continue;
				mn = min(mn, i - pv[i][k]);
			}
			for (int k{0}; k < 6; ++k) {
				if (nx[j][k] == n || k == v[j] || k == op[v[j]]) continue;
				mn = min(mn, nx[j][k] - j);
			}
			if (mn == n) cout << "-1\n";
			else cout << (j - i + 2 * mn) << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
