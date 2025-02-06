//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		int k{-1};
		for (int i{0}; i < n; ++i) {
			if (a[i] >= b[i]) continue;
			if (k == -1) k = i;
			else return cout << "NO\n", []{}();
		}

		if (k != -1) {
			for (int i{0}; i < n; ++i) {
				if (i == k) continue;
				if (a[i] - b[i] < b[k] - a[k]) return cout << "NO\n", []{}();
			}
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
