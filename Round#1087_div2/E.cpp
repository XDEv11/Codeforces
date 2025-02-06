//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<int> z_func(const vector<T>& v) {
    int n{v.size()};
    vector<int> z(n); z[0] = n;
    int l{0}, r{0};
    for(int i{1}; i < n; i++) {
        if(i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && v[z[i]] == v[i + z[i]]) ++z[i];
        if (r < i + z[i]) l = i, r = i + z[i];
    }
    return z;
}

namespace {
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		while (q--) {
			int l, r;
			cin >> l >> r, --l;

			vector<char> t{v.begin() + l, v.begin() + r};
			auto z{z_func(t)};

			long long ans{};
			vector<int> c{};
			for (int i{0}; i < r - l; ++i) {
				c.push_back(i);
				while (c.back() + z[c.back()] <= i) c.pop_back();
				ans += c.size();
			}
			cout << ans << '\n';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
