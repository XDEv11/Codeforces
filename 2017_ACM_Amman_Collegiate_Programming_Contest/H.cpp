#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;

	if (n == 1) return cout << (s <= 9 ? s : -1) << '\n', []{}();
	else if (s == 1) return cout << "-1\n", []{}();

	vector<int> ans(n);
	for (int i{0}; i < n - 1 - i; ++i) {
		int d{min(9, s / 2)};
		ans[i] = ans[n - 1 - i] = d, s -= 2 * d;
	}
	if (n & 1) {
		int d{min(9, s)};
		ans[n / 2] = d, s -= d;
	}
	if (s) return cout << "-1\n", []{}();

	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
