//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	set<int> ans{};
	priority_queue<int> pq{};
	for (int i{0}; i < n; ++i) pq.push(v[i] + (i + 1));
	while (!pq.empty()) {
		auto x{pq.top()}; pq.pop();
		if (!ans.empty() && x >= *ans.begin()) ans.insert(*ans.begin() - 1);
		else ans.insert(x);
	}

	for (auto it{ans.rbegin()}; it != ans.rend(); ++it) cout << *it << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
