//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	vector<int> mx(n + 1, numeric_limits<int>::min());
	mx[0] = 0;
	for (int i{0}; i < n; ++i) {
		int s{0};
		for (int j{i}; j < n; ++j) {
			s += v[j];
			mx[j - i + 1] = max(mx[j - i + 1], s);
		}
	}

	stack<pair<int, int>> s{};
	for (int i{n}; i >= 0; --i)
		if (s.empty() || mx[i] > s.top().fi) s.emplace(mx[i], i);

	int pmx{numeric_limits<int>::min()};
	for (int i{0}; i <= n; ++i) {
		cout << max(pmx, s.top().fi + i * x) << ' ';
		if (s.top().se <= i) s.pop();
		pmx = max(pmx, mx[i] + i * x);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
