//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> ans(n);
	for (int i{m}; i < n; ++i) ans[i] = max(ans[i - 1], ans[i - m] + v[i]);

	return cout << ans[n - 1] << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
