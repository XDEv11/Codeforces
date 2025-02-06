#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> v(n * m);
	for (int i{0}; i < n * m; ++i) {
		auto& [fi, se, th]{v[i]};
		cin >> fi, se = i;
	}
	sort(v.begin(), v.end());

	for (int i{0}; i < n * m; ++i) {
		auto& [fi, se, th]{v[i]};
		th = i;
	}

	for (int i{0}; i < n * m; ++i) {
		auto& [fi, se, th]{v[i]};

		int j{i + 1};
		while (j < n * m) {
			auto& [fi2, se2, th2]{v[j]};
			if (fi2 != fi || th2 / m != th / m) break;
			++j;
		}
		for (int k{i}; k < i + j - 1 - k; ++k) swap(get<2>(v[k]), get<2>(v[i + j - 1 - k]));
		i = j - 1;
	}
	for (int i{0}; i < n * m; ++i) {
		auto& [fi, se, th]{v[i]};
		fi = se, se = th, th = 0;
	}
	sort(v.begin(), v.end());

	int ans{0};
	vector<vector<bool>> s(n, vector<bool>(m, false));
	for (auto& [_1, p, _2] : v) {
		int pr{p / m}, pc{p % m};
		for (int j{0}; j < pc; ++j) ans += s[pr][j];
		s[pr][pc] = true;
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
