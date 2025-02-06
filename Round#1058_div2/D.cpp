//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	int ask(const vector<int>& v) {
		cout << "? " << v.size() << ' ';
		for (auto& x : v) cout << (x + 1) << ' ';
		cout << endl;
		int r;
		cin >> r;
		return r;
	}
	void solve() {
		int n;
		cin >> n;

		vector<int> a(2 * n);
		vector<int> t{};
		for (int i{0}; i < 2 * n; ++i) {
			t.push_back(i);
			int r{ask(t)};
			if (r) a[i] = r, t.pop_back();
		}

		t.clear();
		for (int i{2 * n - 1}; i >= 0; --i) {
			t.push_back(i);
			if (!a[i]) {
				int r{ask(t)};
				if (r) a[i] = r, t.pop_back();
			}
		}

		cout << "! ";
		for (auto& x : a) cout << x << ' ';
		cout << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
