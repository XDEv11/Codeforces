#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve1() {
	int n, len;
	cin >> n >> len;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int r{1};
	for (int i{1}; i < n; ++i) {
		if (v[i] < v[i % r]) r = i + 1;
		else if (v[i] > v[i % r]) break;
	}

	int i{0};
	while (len--) cout << v[i], i = (i + 1) % r;
	cout << '\n';
}

vector<int> z_func(const vector<char>& v) {
	int n{v.size()};
	vector<int> z(n);
	int l{0}, r{0};
	for(int i{1}; i < n; i++) {
		if(i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && v[z[i]] == v[i + z[i]]) ++z[i];
		if (r < i + z[i]) l = i, r = i + z[i];
	}
	return z;
}

void solve2() {
	int n, len;
	cin >> n >> len;
	vector<char> v(2 * n);
	for (int i{0}; i < n; ++i) cin >> v[i], v[n + i] = v[i];

	auto z{z_func(v)};

	int r{1};
	while (r < n) {
		if (z[r] >= r) r *= 2;
		else if (v[r + z[r]] < v[z[r]]) r = r + z[r] + 1;
		else break;
	}

	int i{0};
	while (len--) cout << v[i], i = (i + 1) % r;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve2();
}
