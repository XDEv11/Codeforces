//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
pair<vector<int>, vector<int>> Manacher(const vector<T>& _v, T s = T{}) {
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
    vector<int> ro{}, re{};
    for (int i{1}; i <= 2 * n - 1; i += 2) ro.push_back(r[i] - 1);
    for (int i{2}; i <= 2 * n - 2; i += 2) re.push_back(r[i] - 1);
    return {ro, re};
}

void solve() {
	using ll = long long;

	int n, q;
	cin >> n >> q;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	auto [ro, re]{Manacher(v)};

	vector<int> nx1(n);
	nx1[n - 1] = n;
	for (int i{n - 2}; i >= 0; --i) nx1[i] = (v[i] != v[i + 1] ? i + 1 : nx1[i + 1]);

	vector<int> nx2(n);
	nx2[n - 1] = n + 1, nx2[n - 2] = n;
	for (int i{n - 3}; i >= 0; --i) nx2[i] = (v[i] != v[i + 2] ? i + 2 : nx2[i + 2]);

	auto as{[](ll a, ll b, ll g) {
		if (a > b) return 0ll;
		return (1 + (b - a) / g) * (a + b) / 2;
	}};
	while (q--) {
		int i, j;
		cin >> i >> j, --i;
		int len{j - i};

		ll ans{};
		if (nx1[i] >= j) ans = 0;
		else if (len % 2) {
			int mx{len};
			if (ro[(i + j) / 2] >= len) mx -= 2;
			if (!(nx2[i] >= j && nx2[i + 1] >= j)) ans = as(3, mx, 2);
			ans += as(2, len - 1, 2);
		} else {
			int mx{len};
			if (re[(i + j) / 2 - 1] >= len) mx -= 2;
			ans = as(2, mx, 2);
			if (!(nx2[i] >= j && nx2[i + 1] >= j)) ans += as(3, len - 1, 2);
		}
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
