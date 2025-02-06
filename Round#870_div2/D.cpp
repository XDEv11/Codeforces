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

	vector<int> t1(n);
	t1[0] = v[0] - (n - 1);
	for (int i{1}; i < n; ++i) t1[i] = max(t1[i - 1], v[i] - (n - 1 - i));
	vector<int> t2(n);
	t2[n - 1] = v[n - 1] - (n - 1);
	for (int i{n - 2}; i >= 0; --i) t2[i] = max(t2[i + 1], v[i] - (i));

	int ans{0};
	for (int i{1}; i + 1 < n; ++i) ans = max(ans, v[i] + t1[i - 1] + t2[i + 1] + n - 1);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
