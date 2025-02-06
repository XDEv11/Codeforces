//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<int> Manacher(const vector<T>& _v, T s = T{}) {
	int n{_v.size()};
	vector<T> v(2 * n + 1, s);
	for (int i{0}; i < n; ++i) v[2 * i + 1] = _v[i];

	vector<int> r(2 * n + 1, 1);
	int c{0}, b{1};
	for (int i{1}; i < 2 * n; ++i) {
		if (i < b) r[i] = min(b - i, r[c - (i - c)]);
		while (i - r[i] >= 0 && i + r[i] < 2 * n + 1
			&& v[i - r[i]] == v[i + r[i]]) ++r[i];
		if (i + r[i] > b) c = i, b = i + r[i];
	}
	return r;
}

void solve() {
	string s{};
	cin >> s;

	int n{s.size()};
	vector<char> v(n);
	for (int i{0}; i < n; ++i) v[i] = s[i];

	int len{};
	while (len < n - 1 - len && v[len] == v[n - 1 - len]) ++len;
	if (len == n / 2) return cout << s << '\n', []{}();

	int ans1{len - 1}, ans2{n - len};
	auto r{Manacher(v)};
	for (int i{n / 2 - 1}, j{n - 1 - i}; i >= len; --i, ++j) {
		if (i - r[2 * (i + 1)] / 2 < len) {
			ans1 = i + (i + 1 - len);
			break;
		}
		if (j + r[2 * j] / 2 >= n - len) {
			ans2 = j - (n - len - j);
			break;
		}
		if (i - r[2 * i + 1] / 2 < len) {
			ans1 = i + (i - len);
			break;
		}
		if (j + r[2 * j + 1] / 2 >= n - len) {
			ans2 = j - (n - len - 1 - j);
			break;
		}
	}

	for (int i{0}; i <= ans1; ++i) cout << v[i];
	for (int i{ans2}; i < n; ++i) cout << v[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
