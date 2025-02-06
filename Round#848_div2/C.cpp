//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<char> ch{a};
	sort(ch.begin(), ch.end());
	ch.resize(distance(ch.begin(), unique(ch.begin(), ch.end())));
	int m{ch.size()};

	array<int, 26> idx;
	for (int i{0}; i < m; ++i) idx[ch[i] - 'a'] = i;

	long long ans{0};
	vector<int> p(m, 0);
	for (int i{0}; i < k && i < m; ++i) p[m - 1 - i] = 1;
	do {
		int c{0};
		long long cnt{0};
		for (int i{0}; i < n; ++i) {
			if (a[i] == b[i] || p[idx[a[i] - 'a']]) ++c, cnt += c;
			else c = 0;
		}
		ans = max(ans, cnt);
	} while (next_permutation(p.begin(), p.end()));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
