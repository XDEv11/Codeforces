//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i{1}; i < n; ++i) cin >> p[i], --p[i];

	vector<int> c(n);
	for (int i{1}; i < n; ++i) ++c[p[i]];

	priority_queue<int> pq1{}, pq2{};
	pq1.push(1);
	for (auto& x : c)
		if (x) pq1.push(x);

	int i{0};
	while (true) {
		if (!pq1.empty()) {
			auto x{pq1.top()}; pq1.pop();
			pq2.push(x + i);
		} else {
			auto x{pq2.top()}; pq2.pop();
			pq2.push(x - 1);
		}
		++i;
		if (pq1.empty() && pq2.top() <= i) break;
	}

	cout << i << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
