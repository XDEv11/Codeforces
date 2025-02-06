//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int i{0};
	while (i < n && v[i] == 0) ++i;
	int j{n - 1};
	while (j > i && v[j] == 0) --j;

	int ans{0};
	for (int k{i}; k <= j; ++k) ans += (v[k] == 0);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
