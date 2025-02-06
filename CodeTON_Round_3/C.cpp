//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) {
		char c;
		cin >> c;
		x = (c == '1');
	}
	for (auto& x : b) {
		char c;
		cin >> c;
		x = (c == '1');
	}

	for (int i{0}; i + 1 < n; ++i) {
		if ((a[i] ^ a[i + 1]) != (b[i] ^ b[i + 1])) return cout << "NO\n", []{}();
	}

	vector<pair<int, int>> ans{};
	int c{0};
	for (int i{0}; i + 1 < n; ++i) {
		if (a[i] ^ a[i + 1]) {
			a[i + 1] ^= 1, b[i + 1] ^= 1, c ^= 1;
			ans.emplace_back(i + 1, i + 1);
		}
	}
	for (auto& x : b) x ^= c;
	if (a[0]) ans.emplace_back(0, n - 1);
	if (b[0]) {
		ans.emplace_back(0, 0);
		ans.emplace_back(1, n - 1);
		ans.emplace_back(0, n - 1);
	}

	cout << "YES\n";
	cout << ans.size() << '\n';
	for (auto& [l, r] : ans) cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
