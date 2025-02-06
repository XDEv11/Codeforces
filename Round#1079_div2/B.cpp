//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> p(n), a(n);
		for (auto& x : p) cin >> x;
		for (auto& x : a) cin >> x;

		vector<int> idx(n + 1);
		for (int i{0}; i < n; ++i) idx[p[i]] = i;

		int mx{-1};
		for (int i{0}; i < n; ++i) {
			if (i && a[i] == a[i - 1]) continue;
			if (idx[a[i]] <= mx) return void(cout << "NO\n");
			mx = max(mx, idx[a[i]]);
			idx[a[i]] = -1;
		}
		cout << "YES\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
