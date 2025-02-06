//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int g{n - (n - k) / 2};

	auto t{v};
	sort(t.begin(), t.end());
	int x{t.front()}, y{t.back()}, mn{y - x};
	for (int i{0}, j{g - 1}; j < n; ++i, ++j) {
		if (t[j] - t[i] < mn) x = t[i], y = t[j], mn = y - x;
	}

	cout << x << ' ' << y << '\n';
	int l{0};
	for (int i{0}; i < k - 1; ++i) {
		int r{l}, c{0};
		while (c < 1) x <= v[r] && v[r] <= y ? ++c : --c, ++r;
		cout << l + 1 << ' ' << r << '\n';
		l = r;
	}
	cout << l + 1 << ' ' << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
