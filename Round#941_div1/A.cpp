//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<bool> ans(v.size());
	ans[v.size() - 1] = true;
	for (int i{v.size() - 2}; i >= 0; --i) ans[i] = (v[i] - (i ? v[i - 1] : 0) > 1 ? true : !ans[i + 1]);

	cout << (ans[0] ? "Alice\n" : "Bob\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
