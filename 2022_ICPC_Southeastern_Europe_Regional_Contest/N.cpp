#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define fi first
#define se second

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	priority_queue<pair<int, int>> pq{};
	vector<bool> ck(n);
	for (int i{0}; i < n; ++i) pq.emplace(v[i], i);

	for (int i{0}; i < n; ++i) {
		int k;
		do { k = pq.top().se, pq.pop(); } while (ck[k]);
		ck[k] = true;
		if (k - 1 >= 0 && v[k - 1] < v[k] - m) v[k - 1] = v[k] - m, pq.emplace(v[k - 1], k - 1);
		if (k + 1 < n && v[k + 1] < v[k] - m) v[k + 1] = v[k] - m, pq.emplace(v[k + 1], k + 1);
	}

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
