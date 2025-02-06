#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	auto sorted{v};
	sort(sorted.begin(), sorted.end());

	int ans{0};
	for (int i{0}; i < n; ++i) if (v[i] != sorted[i]) ++ans;

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
