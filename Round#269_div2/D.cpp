//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template<typename T>
vector<int> prefix_func(const vector<T>& v) {
	vector<int> len(v.size());
	for (int i{1}; i < v.size(); ++i) {
		int j{len[i - 1]};
		while (j > 0 && v[i] != v[j]) j = len[j - 1];
		len[i] = j + (v[i] == v[j]);
	}
	return len;
}

template<typename T>
vector<int> KMP(const vector<T> &s, const vector<T> &p) {
	vector<int> lps{prefix_func(p)}, v{};
	for (int i{0}, j{0}; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = lps[j - 1];
		if (s[i] == p[j] && ++j == p.size()) v.push_back(i), j = lps[j - 1];
	}
	return v;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	if (m > n) return cout << "0\n", []{}();
	if (m == 1) return cout << n << '\n', []{}();

	for (int i{0}; i + 1 < n; ++i) a[i] = a[i + 1] - a[i];
	a.resize(--n);
	for (int i{0}; i + 1 < m; ++i) b[i] = b[i + 1] - b[i];
	b.resize(--m);

	cout << KMP(a, b).size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
