//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto& x : p) cin >> x;

	int p1{};
	for (int i{0}; i < n; ++i) {
		if (p[i] == 1) p1 = i;
	}
	if (p1 & 1) reverse(p.begin(), p.end());

	vector<int> q(n); {
		vector<pair<int, int>> t0{}, t1{};
		for (int i{0}; i < n; i += 2) {
			t0.emplace_back(p[i], i);
			t1.emplace_back(p[i + 1], i + 1);
		}
		sort(t0.rbegin(), t0.rend());
		sort(t1.begin(), t1.end());

		int t{1};
		for (auto& [_, i] : t0) q[i] = t++; // at most n + 1
		t = n;
		for (auto& [_, i] : t1) q[i] = t--; // at least 2 + n
	}

	if (p1 & 1) reverse(q.begin(), q.end());

	for (auto& x : q) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
