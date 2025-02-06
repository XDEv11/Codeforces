//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

static void solve() {
	using ll = long long;

	string s{};
	cin >> s;
	int n{s.size()};

	int pc{0};
	while (pc < n && s[pc] == 'a') ++pc;
	if (pc == n) return cout << n - 1 << '\n', []{}();
	s = s.substr(pc), n = s.size();

	vector<int> pv(n); // the last non-'a'
	pv[0] = 0;
	for (int i{1}; i < n; ++i) {
		if (s[i] == 'a') pv[i] = pv[i - 1];
		else pv[i] = i;
	}
	int sc{(n - 1) - pv[n - 1]};

	ll ans{ll(pc + 1) * (sc + 1)};

	auto z{z_func(vector<char>{s.begin(), s.end()})};

	vector<int> t{};
	for (int i{0}; i < n; ++i) {
		if (s[i] == s[0]) t.push_back(i);
	}
	int m{t.size()};

	for (int d{1}; d < m; ++d) {
		if (m % d) continue;
		bool f{true};
		int len{pv[t[d] - 1] + 1}, mc{(t[d] - 1) - pv[t[d] - 1]};
		for (int i{d}; i < m; i += d) {
			if (z[t[i]] < len) {
				f = false;
				break;
			}
			if (i + d < m) {
				if (t[i] + z[t[i]] - 1 < pv[t[i + d] - 1]) {
					f = false;
					break;
				}
				mc = min(mc, (t[i + d] - 1) - pv[t[i + d] - 1]);
			} else {
				if (t[i] + z[t[i]] - 1 < pv[n - 1]) {
					f = false;
					break;
				}
			}
		}
		if (f) { // can be formulated
			for (int i{0}; i <= min(mc, pc); ++i) ans += min(mc - i, sc) + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
