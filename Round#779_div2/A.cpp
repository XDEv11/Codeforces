//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	int i{0};
	while (i < n && v[i] != '0') ++i;
	while (i < n) {
		int j{i + 1};
		while (j < n && v[j] != '0') ++j;
		if (j == n) break;
		if (j == i + 1) ans += 2;
		else if (j == i + 2) ans += 1;
		i = j;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
