//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	long long ans{v[0] - 1};
	v[0] = 1;
	for (int i{1}; i < n; ++i) {
		if (v[i] == v[i - 1]) continue;
		ans += v[i] - (v[i - 1] + 1);
		v[i] = v[i - 1] + 1;
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
