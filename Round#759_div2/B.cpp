//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto mx{*max_element(v.begin(), v.end())};
	int ans{0};
	int i{n - 1};
	while (i >= 0 && v[i] != mx) {
		++ans;
		auto& x{v[i]};
		while (i >= 0 && v[i] <= x) --i;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
