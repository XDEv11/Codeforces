//#pragma GCC optimize ("O3")

#include <iostream>
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
    vector<char> v{};

	int q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == '-') v.pop_back();
		else v.push_back(c);

		int ans{};
		auto r{Manacher(v)};
		for (int i{0}; i <= 2 * v.size(); ++i) ans += r[i] / 2;

		cout << ans << " \n"[!q];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
