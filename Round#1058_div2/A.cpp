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
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		n = v.size();

		for (int i{0}; i < n; ++i) {
			if (v[i] != i) return cout << i << '\n', []{}();
		}
		cout << n << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
