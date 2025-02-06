//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		for (int i{0}; i + 1 < n; ++i) {
			if (v[i] == i) continue;
			if (v[i] == i + 1 && v[i + 1] == i) swap(v[i], v[i + 1]);
			else return cout << "NO\n", []{}();
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
