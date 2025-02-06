//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	int query(int u, int v) {
		cout << (u + 1) << " " << (v + 1) << endl;
		return cin >> u, u;
	}
	void solve() {
		int n;
		cin >> n;

		for (int k{1}; k < n; ++k)
			for (int i{0}; i < n; ++i) {
				int j{(i + k) % n};
				auto r{query(i, j)};
				if (r) return ;
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
