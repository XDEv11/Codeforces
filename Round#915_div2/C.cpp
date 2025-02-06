//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	char mx{};
	vector<int> t{};
	for (int i{n - 1}; i >= 0; --i) {
		if (v[i] >= mx) t.push_back(i), mx = v[i];
	}
	reverse(t.begin(), t.end());

	vector<char> u{v};
	for (int i{0}; i < t.size(); ++i) {
		u[t[t.size() - 1 - i]] = v[t[i]];
	}
	if (!is_sorted(u.begin(), u.end())) return cout << "-1\n", []{}();

	int j{0};
	while (j < t.size() && v[t[j]] == mx) ++j;
	cout << (t.size() - j) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
