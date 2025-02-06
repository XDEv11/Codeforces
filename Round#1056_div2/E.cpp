//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m, l;
		cin >> n >> m >> l;
		vector<pair<int, int>> a(l);
		for (auto& [x, y] : a) cin >> x >> y, --x, --y;

		map<int, int> cnt{};
		for (auto& [x, y] : a) ++cnt[y];

		if (n > 1) {
			for (auto& [k, v] : cnt) {
				if (k && (v & 1)) return void(cout << "Mimo\n");
			}
			cout << "Yuyu\n";
		} else cout << (cnt[1] & 1 ? "Mimo\n" : "Yuyu\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
