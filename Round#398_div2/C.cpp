//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> p(n), w(n);
	for (int v{0}; v < n; ++v) cin >> p[v] >> w[v], --p[v];

	vector<int> c(n);
	int s{};
	for (int v{0}; v < n; ++v) {
		if (p[v] != -1) ++c[p[v]];
		s += w[v];
	}
	if (s % 3) return cout << "-1\n", true;

	int ans1{-1}, ans2{-1};
	queue<int> qu{};
	for (int v{0}; v < n; ++v) {
		if (!c[v]) qu.push(v);
	}
	while (!qu.empty()) {
		auto v{qu.front()}, u{p[v]}; qu.pop();
		if (u == -1) continue;
		if (w[v] == s / 3) (ans1 == -1 ? ans1 : ans2) = v, w[v] = 0;
		if (ans2 != -1) break;
		w[u] += w[v];
		if (!--c[u]) qu.push(u);
	}

	if (ans1 == -1 || ans2 == -1) cout << "-1\n";
	else cout << (ans1 + 1) << ' ' << (ans2 + 1) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
