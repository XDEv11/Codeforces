#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i{0}; i < n; ++i) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	vector<vector<long long>> t{};

	t.emplace_back();
	t.back().push_back(v[0].second);
	for (int i{1}; i < n; ++i) {
		if (v[i].first != v[i - 1].first) t.emplace_back();
		t.back().push_back(v[i].second);
	}

	long long ans{0};

	for (auto& vt : t) {
		sort(vt.begin(), vt.end());

		auto ps{vt};
		auto m{ps.size()};
		for (int i{m - 1}; i >= 0; --i) {
			ps[i] = n - ps[i];
			if (i != m - 1) ps[i] += ps[i + 1];
		}

		for (int i{0}; i + 1 < m; ++i)
			ans += (vt[i] + 1) * ps[i + 1];
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
