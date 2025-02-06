//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	deque<array<int, 2>> dq(n);
	for (int i{0}; i < n; ++i) dq[i] = {v[i], i};

	vector<int> ans(n);
	sort(dq.begin(), dq.end());
	for (int k{n}, c{}; k >= 1; --k) {
		if (dq.front()[0] - c == 0) ans[dq.front()[1]] = -k, dq.pop_front();
		else if (dq.back()[0] - c == k) ans[dq.back()[1]] = k, dq.pop_back(), ++c;
		else return cout << "NO\n", []{}();
	}

	cout << "YES\n";
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
