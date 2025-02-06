#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

bool solve() {
	int n, k;
	if (!(cin >> n >> k)) return false;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	map<int, int> id{};
	for (auto& [x, y] : v) {
		if (y - x + 1 >= k) continue;
		id[x % k] = id[y % k] = 0;
	}
	int lb{0};
	for (auto& [k, v] : id) v = lb++;

	int a{};
	vector<int> ans(lb + 1);
	for (auto& [x, y] : v) {
		if (y - x + 1 < k) {
			int xi{id[x % k]}, yi{id[y % k]};
			if (xi <= yi) ++ans[xi], --ans[yi + 1];
			else ++ans[0], --ans[yi + 1], ++ans[xi], --ans[lb];
		} else ++a;
	}
	for (int i{1}; i <= lb; ++i) ans[i] += ans[i - 1];

	cout << (a + *max_element(ans.begin(), ans.end())) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}

