//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int mx{};
	for (int i{0}, c{}; i < n; ++i) {
		if (v[i] == '.') mx = max(mx, ++c);
		else if (v[i] == '#') c = 0;
	}

	if (mx >= 3) cout << "2\n";
	else cout << count(v.begin(), v.end(), '.') << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
