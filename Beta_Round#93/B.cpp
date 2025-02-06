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

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	vector<char> v(n);
	for (int i{0}; i < n; ++i) v[i] = s[i];
	auto z{z_func(v)};

	int mx{};
	for (int i{1}; i < n; ++i) mx = max(mx, z[i] - (i + z[i] == n));

	int ans1{}, ans2{};
	for (int i{1}; i < n; ++i) {
		if (i + z[i] < n) continue; // no suffix
		if (z[i] > mx) continue; // no middle
		if (z[i] > ans1) ans1 = z[i], ans2 = i;
	}

	if (ans1) {
		for (int i{ans2}; i < ans2 + ans1; ++i) cout << v[i];
		cout << '\n';
	} else cout << "Just a legend\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
