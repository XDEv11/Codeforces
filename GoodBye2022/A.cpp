//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	priority_queue<int> pq{};
	for (auto& x : a) pq.emplace(-x);
	for (auto& x : b) {
		auto mn{pq.top()}; pq.pop();
		pq.emplace(-x);
	}

	long long ans{0};
	while (!pq.empty()) {
		auto mn{pq.top()}; pq.pop();
		ans -= mn;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
