#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		int Min = numeric_limits<int>::max();
		for (auto& e : vec) {
			cin >> e;
			if (e < Min) Min = e;
		}

		bool ans = true;
		vector<int> sorted(vec);
		sort(sorted.begin(), sorted.end());
		for (int i = 0; i < n; ++i) {
			if (vec[i] % Min && vec[i] != sorted[i]) {
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
