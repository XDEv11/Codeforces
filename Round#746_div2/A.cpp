#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, h;
	cin >> n >> h;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.rbegin(), v.rend());

	int ans{h / (v[0] + v[1]) * 2};
	h %= (v[0] + v[1]);
	if (h) ++ans, h -= v[0];
	if (h > 0) ++ans;

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
