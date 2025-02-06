//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve1() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(k);
	for (auto& x : v) cin >> x, --x;

	priority_queue<int> pq{};
	int t{k - 1};
	for (int i{0}; i < k; ++i) {
		pq.push(v[i]);
		if (pq.size() > n * m - 3) return cout << "TIDAK\n", []{}();
		while (!pq.empty() && pq.top() == t) pq.pop(), --t;
	}
	cout << "YA\n";
}

void solve2() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(k);
	for (auto& x : v) cin >> x, --x;

	vector<int> p(k);
	for (int i{0}; i < k; ++i) p[v[i]] = i;

	for (int i{k - 1}; i >= 0; --i) {
		if (p[i] + 1 - (k - 1 - i) > n * m - 3) return cout << "TIDAK\n", []{}();
	}
	cout << "YA\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
