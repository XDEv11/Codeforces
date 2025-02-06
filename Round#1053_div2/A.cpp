//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(m);
		for (auto& x : v) cin >> x;

		for (int i{0}; i + 1 < m; ++i) {
			if (v[i] >= v[i + 1]) return cout << "1\n", []{}();
		}

		cout << (n + 1 - v[m - 1]) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
