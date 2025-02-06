#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int x{-1}, y{-1}, ans{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] != x && !(i + 1 < n && v[i + 1] == y)) x = v[i], ++ans;
		else if (v[i] != y) y = v[i], ++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
