//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {b[i], i};
	sort(t.begin(), t.end());

	for (int i{0}; i < n; ++i) {
		auto& [x, idx]{t[i]};
		if (x > a[idx]) {
			bool f{false};
			for (int j{idx - 1}; j >= 0 && a[j] <= x && b[j] >= x; --j) {
				if (a[j] == x) {
					f = true;
					break;
				}
			}
			for (int j{idx + 1}; j < n && a[j] <= x && b[j] >= x; ++j) {
				if (a[j] == x) {
					f = true;
					break;
				}
			}
			if (!f) return cout << "NO\n", []{}();
			a[idx] = x;
		} else if (x < a[idx]) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
