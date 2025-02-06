//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<vector<int>> idx(n);
	for (int i{0}; i < n; ++i) {
		idx[v[i]].push_back(i);
		if (idx[v[i]].size() > 2) return cout << "NO\n", []{}();
	}

	vector<int> p(n), q(n);
	queue<int> pp{}, qp{};
	for (int i{n - 1}; i >= 0; --i) {
		if (idx[i].size() == 2) {
			p[idx[i][0]] = i;
			qp.push(idx[i][0]);
			q[idx[i][1]] = i;
			pp.push(idx[i][1]);
		} else if (idx[i].size() == 1) {
			p[idx[i][0]] = q[idx[i][0]] = i;
		} else {
			if (pp.empty() || qp.empty()) return cout << "NO\n", []{}();
			auto idx{pp.front()}; pp.pop();
			p[idx] = i;
			idx = qp.front(); qp.pop();
			q[idx] = i;
		}
	}
	cout << "YES\n";
	for (auto& x : p) cout << x + 1 << ' ';
	cout << '\n';
	for (auto& x : q) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
