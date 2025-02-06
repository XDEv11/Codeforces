#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> box(n), pos(m);
	for (auto& x : box) cin >> x;
	for (auto& x : pos) cin >> x;

	auto push_one_side = [](vector<pair<int, int>> obj) {
		int n{static_cast<int>(obj.size())}, cnt{0};
		for (int i{0}; i + 1 < n; ++i)
			if (obj[i].first == obj[i + 1].first) ++cnt; // must be a box and a special position

		int res{cnt};
		int i{0}, nb{0}, cnt2{0};
		for (int j{0}; j < n; ++j) {
			auto& [p, t]{obj[j]};
			if (t == 0) ++nb; // box
			else { // special position
				if (j - 1 >= 0 && obj[j - 1].first == p) --cnt; // substract from cnt
				++cnt2; // add to cnt2
				while (i <= j && obj[i].first <= p - nb) { // update position i
					if (obj[i].second == 1) --cnt2; // substract from cnt2
					++i;
				}
				res = max(res, cnt + cnt2);
			}
		}

		return res;
	};

	int ans{0};

	vector<pair<int, int>> v{};
	int i{0}, j{0};
	while ((i < n && box[i] < 0) || (j < m && pos[j] < 0)) {
		if (!(j < m && pos[j] < 0) || ((i < n && box[i] < 0) && box[i] < pos[j])) v.emplace_back(-box[i++], 0);
		else v.emplace_back(-pos[j++], 1);
	}
	reverse(v.begin(), v.end()); // process from 0
	ans += push_one_side(move(v));

	while (i < n || j < m) {
		if (!(j < m) || (i < n && box[i] <= pos[j])) v.emplace_back(box[i++], 0);
		else v.emplace_back(pos[j++], 1);
	}
	ans += push_one_side(move(v));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
