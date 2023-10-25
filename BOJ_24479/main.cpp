#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m, r;
map<int, vi> adj;
vb visit;
int now;
vi ans;

void dfs(int x) {
	visit[x] = true;
	ans[x] = now;
	++now;

	for (const auto& y : adj[x]) {
		if (visit[y]) {
			continue;
		}

		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m >> r;
	for (auto i = 1; i <= n; ++i) {
		adj[i] = vi{};
	}

	ans = vi(n + 1, 0);

	while (0 < (m--)) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (auto&& [k, y] : adj) {
		sort(y.begin(), y.end());
	}

	visit = vb(n + 1, false);
	now = 1;
	dfs(r);

	for (auto i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}