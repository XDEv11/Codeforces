//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x;
	vector<char> b(n);
	for (auto& x : b) cin >> x;

	vector<tuple<char, int, int>> v(n);
	for (int i{0}; i < n; ++i) v[i] = {b[i], p[i], i};
	sort(v.begin(), v.end());

	vector<int> ans(n);
	for (int i{0}; i < n; ++i) {
		ans[get<2>(v[i])] = i + 1;
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

	return 0;
}
