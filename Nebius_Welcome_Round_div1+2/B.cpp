//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k, d, w;
	cin >> n >> k >> d >> w;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	for (int i{0}; i < n; ) {
		int j{i + 1};
		while (j < n && j - i < k && v[j] <= v[i] + w + d) ++j;
		++ans;
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
