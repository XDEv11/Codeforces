#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (v[0] == 1) {
		cout << n + 1 << ' ';
		for (int i{0}; i < n; ++i) cout << i + 1 << " \n"s[i == n - 1];
	} else if (v[n - 1] == 0) {
		for (int i{0}; i < n; ++i) cout << i + 1 << ' ';
		cout << n + 1 << '\n';
	} else {
		for (int k{0}; k + 1 < n; ++k)
			if (v[k] == 0 && v[k + 1] == 1) {
				for (int i{0}; i < n; ++i) {
					cout << i + 1 << ' ';
					if (i == k) cout << n + 1 << ' ';
				}
				return cout << '\n', []{}();
			}
		cout << "-1\n"s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
