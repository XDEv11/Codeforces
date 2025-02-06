//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<array<int, 2>> v(n);
		for (auto& x : v) cin >> x[0] >> x[1];

		sort(v.begin(), v.end(), [](array<int, 2> a, array<int, 2> b) {
			if (a[0] > a[1]) swap(a[0], a[1]);
			if (b[0] > b[1]) swap(b[0], b[1]);
			return (a < b);
		});

		for (auto& x : v) cout << x[0] << ' ' << x[1] << ' ';
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
