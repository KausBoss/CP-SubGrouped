#include <bits/stdc++.h>

using namespace std;

const int MX = 5000;

char a[MX + 1], b[MX + 1];
int f[MX + 1][MX + 1], g[MX + 1][MX + 1];

int main() {
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, m;
		ignore = scanf("%d %d %s %s", &n, &m, a, b);
		for (int i = 0; i <= n; i++) {
			fill(f[i], f[i] + m + 1, 3 * MX);
			fill(g[i], g[i] + m + 1, 3 * MX);
		}
		
		g[0][1] = f[1][0] = 1;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				if (i < n) {
					if (i > 0) f[i + 1][j] = min(f[i + 1][j], f[i][j] + (a[i - 1] != a[i]));
					if (j > 0) f[i + 1][j] = min(f[i + 1][j], g[i][j] + (b[j - 1] != a[i]));
				}
				
				if (j < m) {
					if (i > 0) g[i][j + 1] = min(g[i][j + 1], f[i][j] + (a[i - 1] != b[j]));
					if (j > 0) g[i][j + 1] = min(g[i][j + 1], g[i][j] + (b[j - 1] != b[j]));
				}
			}
		
		printf("%d\n", min(f[n][m], g[n][m]));
	}
	
	return 0;
}