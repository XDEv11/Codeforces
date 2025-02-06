#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace F {
	int nx, ny;
	vector<vector<int>> adjx{};
    vector<bool> vis{};
    vector<int> mx{}, my{};
    bool dfs(int x) {
        for (auto& y : adjx[x]) {
            if (vis[y]) continue;
            vis[y] = true;
            if (my[y] == -1 || dfs(my[y])) {
                mx[x] = y, my[y] = x;
                return true;
            }
        }
        return false;
    }
	bool solve() {
		int m;
		if (!(cin >> nx >> ny >> m)) return false;
		adjx.assign(nx + 2, {});
		while (m--) {
			int x, y;
			cin >> x >> y, --x, --y;
			adjx[x].push_back(y);
		}

		vis.resize(ny), mx.assign(nx + 2, -1), my.assign(ny, -1);

		int ans1{0};
		for (int x{0}; x < nx; ++x) {
			fill(vis.begin(), vis.end(), false);
			if (dfs(x)) ++ans1;
		}

		int ans2{0};
		for (int x{0}; x < nx; ++x) {
			adjx[nx] = adjx[nx + 1] = adjx[x];
			fill(vis.begin(), vis.end(), false);
			auto _mx{mx}, _my{my};
			ans2 = max(ans2, dfs(nx) + dfs(nx + 1));
			mx = _mx, my = _my;
		}

		return cout << (ans1 + ans2) << '\n', true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (F::solve()) ;
}
