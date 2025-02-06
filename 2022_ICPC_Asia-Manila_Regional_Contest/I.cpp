#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<vector<int>> ig(m);
	vector<int> p{};
	for (auto& v : ig) {
		int c;
		cin >> c;
		if (c) {
			v.resize(c);
			for (auto& x : v) cin >> x, --x;
		} else {
			int x;
			cin >> x;
			p.push_back(x);
		}
	}

	const int imp{100000001};
	vector<vector<int>> r(m, vector<int>(p.size()));
	for (int i{m - 1}, j{p.size() - 1}; i >= 0; --i) {
		if (ig[i].empty()) {
			r[i][j--] = 1;
		} else {
			for (auto& x : ig[i])
				for (int k{0}; k < p.size(); ++k) {
					r[i][k] += r[x][k];
					if (r[i][k] > imp) r[i][k] = imp;
				}
		}
	} 

	int ans{};
	for (int b{0}; b < (1 << n); ++b) {
		int a{};
		vector<int> c(p.size());
		for (int i{0}; i < n; ++i) {
			if ((b >> i) & 1) continue;
			++a;
			for (int k{0}; k < p.size(); ++k) {
				c[k] += r[i][k];
				if (c[k] > imp) c[k] = imp;
			}
		}
		bool f{true};
		for (int k{0}; k < p.size(); ++k) {
			if (c[k] > p[k]) {
				f = false;
				break;
			}
		}
		if (f) ans = max(ans, a);
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}

