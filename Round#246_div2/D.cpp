//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

// longest prefix which is also suffix
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

void solve1() {
	string s{};
	cin >> s;
	int n{s.size()};

	vector<char> v(n);
	for (int i{0}; i < n; ++i) v[i] = s[i];
	auto lps{prefix_func(v)};

	vector<int> cnt(n + 1);
	cnt[n] = 1;
	for (int i{0}; i < n; ++i) ++cnt[lps[i]];
	for (int i{n - 1}; i >= 1; --i) cnt[lps[i - 1]] += cnt[i];

	vector<pair<int, int>> ans{};
	for (int i{n}; i; i = lps[i - 1]) ans.emplace_back(i, cnt[i]);
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto& [l, c] : ans) cout << l << ' ' << c << '\n';
}

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

void solve2() {
	string s{};
	cin >> s;
	int n{s.size()};

	vector<char> v(n);
	for (int i{0}; i < n; ++i) v[i] = s[i];
	auto z{z_func(v)};
	z[0] = n;

	vector<int> cnt(n + 1);
	for (int i{0}; i < n; ++i) ++cnt[z[i]];
	for (int i{n - 1}; i >= 0; --i) cnt[i] += cnt[i + 1];

	vector<pair<int, int>> ans{};
	for (int i{n - 1}; i >= 0; --i) {
		if (i + z[i] < n) continue;
		ans.emplace_back(z[i], cnt[z[i]]);
	}

	cout << ans.size() << '\n';
	for (auto& [l, c] : ans) cout << l << ' ' << c << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve2();
}
