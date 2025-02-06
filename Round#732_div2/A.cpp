#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0))
		return cout << "-1\n"s, []{}();

	vector<pair<int, int>> ans{};
	for (int i{0}; i < n - 1; ++i)
		if (a[i] >= b[i]) {
			int d{a[i] - b[i]};
			while (d--) {
				int j{i + 1};
				while (a[j] >= b[j]) ++j;
				a[i] -= 1, a[j] += 1;
				ans.emplace_back(i, j);
			}
		} else {
			int d{b[i] - a[i]};
			while (d--) {
				int j{i + 1};
				while (a[j] <= b[j]) ++j;
				a[i] += 1, a[j] -= 1;
				ans.emplace_back(j, i);
			}
		}

	cout << ans.size() << '\n';
	for (auto& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
