//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt(n);
	for (auto& x : v) ++cnt[x];

	int l{0}, r{n + 1};
	while (r - l > 1) {
		int m{(l + r) / 2};
		bool f{true};
		priority_queue<int> pq{};
		for (int i{0}; i < m; ++i) {
			if (cnt[i] == 0) f = false;
			pq.push(-cnt[i]);
		}
		for (int i{0}; i < m - 1; ++i) {
			auto x{pq.top()}; pq.pop();
			x = pq.top(), pq.pop();
			if (-x == 1) f = false;
			pq.push(-(-x - 1));
		}
		(f ? l : r) = m;
	}

	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
