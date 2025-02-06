//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	set<int> st{};
	for (int i{0}; i <= n; ++i) st.insert(i);

	vector<int> ans(n);
	for (int i{0}; i < n; ++i) {
		int x{*st.begin()};
		st.erase(ans[i] = v[i] > 0 ? x : (x - v[i]));
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
