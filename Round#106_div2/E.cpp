//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

#include <cassert>

using namespace std;

template<typename T>
vector<int> z_func(const vector<T>& v) {
    int n{v.size()};
    vector<int> z(n);
    int l{0}, r{0};
    for(int i{1}; i < n; i++) {
        if(i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && v[z[i]] == v[i + z[i]]) ++z[i];
        if (r < i + z[i]) l = i, r = i + z[i];
    }
    return z;
}

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};
	int m;
	cin >> m;
	vector<string> ss(m);
	for (auto& x : ss) cin >> x;

	int ans{};
	for (auto& x : ss) {
		m = x.size();
		vector<char> v(m + 1 + n);
		for (int i{0}; i < m; ++i) v[i] = x[i];
		for (int i{0}; i < n; ++i) v[m + 1 + i] = s[i];
		auto z1{z_func(v)};

		reverse(v.begin(), v.begin() + m);
		reverse(v.begin() + m + 1, v.end());
		auto z2{z_func(v)};

		vector<int> mn(m + 1, n), mx(m + 1, -1);
		for (int i{n - 1}; i >= 0; --i) mn[z1[m + 1 + i]] = i;
		for (int i{m - 1}; i >= 0; --i) mn[i] = min(mn[i], mn[i + 1]);
		for (int i{n - 1}; i >= 0; --i) mx[z2[m + 1 + i]] = n - 1 - i;
		for (int i{m - 1}; i >= 0; --i) mx[i] = max(mx[i], mx[i + 1]);

		for (int k{1}; k < m; ++k) {
			if (mx[m - k] - mn[k] + 1 >= m) {
				++ans;
				break;
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
