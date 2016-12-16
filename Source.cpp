#include <iostream> 
#include <fstream> 
#include <vector>
#include <string.h>
#include <cstring>
typedef unsigned long long ull;

using namespace std;

#define fori(n) for(int i = 0; i < n; i++)
#define forj(m) for(int j = 0; j < m; j++)
#define forri(a,b) for(int i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const ll INF = 1e18;
ll d[16][13][4097];
int main()
{
    int n, m;
    cin >> m >> n;

    if (n > m) swap(n, m);

    fori(m + 1)
        forj(n + 1)
            for (int k = 0; k < (1 << n); k++) d[i][j][k] = 0;

    d[0][0][0] = 1;
    fori(m) {
        forj(n + 1) {
            for (ll k = 0; k < (1 << n); k++) {
                if (j == n) {
                    d[i + 1][0][k] += d[i][j][k];
                    continue;
                }
                if ((k & (1 << (n - j - 1))) == 0) {
                    if (i != m - 1) d[i][j + 1][k + (1 << (n - j - 1))] += d[i][j][k];
                    if (j != n - 1 && (k & (1 << (n - j - 2))) == 0) {
                        d[i][j + 1][k + (1 << (n - j - 2))] += d[i][j][k];
                    }
                }
                else {
                    d[i][j + 1][k - (1 << (n - j - 1))] += d[i][j][k];
                }

            }
        }
    }

    ll sum = 0;
    for (int k = 0; k < (1 << n); k++) {
        sum += d[m][0][k];
    }
    cout << sum;
}