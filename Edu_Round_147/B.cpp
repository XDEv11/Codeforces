//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v1(n), v2(n);
	for (auto& x : v1) cin >> x;
	for (auto& x : v2) cin >> x;

	int l{0}, r{n - 1};
	while (l < n && v1[l] == v2[l]) ++l;
	if (l == n) {
		int c{0}, mx{0}, al, ar;
		for (int i{1}; i < n; ++i) {
			if (v1[i - 1] <= v1[i]) ++c;
			else c = 0;
			if (c > mx) mx = c, al = i - c, ar = i;
		}
		return cout << al + 1 << ' ' << ar + 1 << '\n', []{}();
	}
	while (v1[r] == v2[r]) --r;

	while (l - 1 >= 0 && v2[l - 1] <= v2[l]) --l;
	while (r + 1 < n && v2[r] <= v2[r + 1]) ++r;

	cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
