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

		int k{n - 2};
		while (k >= 0 && v[k] != v[k + 1]) --k;
		if (k < 0) return cout << "-1\n", []{}();

		int j{k - 2};
		while (j >= 0 && v[j] != v[j + 1]) --j;
		if (j >= 0) return cout << v[j] << ' ' << v[j] << ' ' << v[k] << ' ' << v[k] << '\n', []{}();

		int t{v[k]};
		v.erase(v.begin() + k), v.erase(v.begin() + k);
		for (int i{0}; i + 1 < n - 2; ++i) {
			if (v[i] + t * 2 > v[i + 1]) {
				return cout << t << ' ' << t << ' ' << v[i] << ' ' << v[i + 1] << '\n', []{}();
			}
		}
		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
