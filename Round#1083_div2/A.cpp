//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> p(n);
		for (auto& x : p) cin >> x;

		for (int i{0}; i < n; ++i) {
			if (p[i] == n) { swap(p[0], p[i]); break; }
		}

		for (auto& x : p) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
