//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x, --x;

	vector<int> idx(n);
	for (int i{0}; i < n; ++i) idx[p[i]] = i;

	int ans1, ans2;
	if ((idx[0] < idx[n - 1]) == (idx[n - 1] < idx[1])) ans1 = ans2 = 0;
	else if (idx[0] < idx[n - 1]) ans1 = idx[n - 1], ans2 = max(idx[0], idx[1]);
	else ans1 = idx[n - 1], ans2 = min(idx[0], idx[1]);

	cout << (ans1 + 1) << ' ' << (ans2 + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
