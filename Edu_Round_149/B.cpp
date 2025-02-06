//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans{1}, c{0};
	for (int i{0}; i < n; ++i) {
		if (i && v[i] == v[i - 1]) ++c;
		else c = 1;
		ans = max(ans, c + 1);
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
