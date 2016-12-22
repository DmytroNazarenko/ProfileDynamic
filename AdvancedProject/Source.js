

function main(n, m)
{
    // >> m >> n;
    


    for(var i = 0 ; i < m+1; i++){
        for(var j = 0; j < n+1; j++)
            for(var k = 0; k < (1 << n); k++) {
                d[i][j][k] = 0;
            }
    }
    d[0][0][0] = 1;
    for(var i = 0; i < m; i++) {
        for(var j = 0; j < n+1; j++) {
            for (var k = 0; k < (1 << n); k++) {
                if (j == n) {
                    d[i + 1][0][k] += d[i][j][k];
                    continue;
                }
                if ((k & (1 << (n - j - 1))) === 0) {
                    if (i != m - 1) d[i][j + 1][k + (1 << (n - j - 1))] += d[i][j][k];
                    if (j != n - 1 && (k & (1 << (n - j - 2))) === 0) {
                        d[i][j + 1][k + (1 << (n - j - 2))] += d[i][j][k];
                    }
                }
                else {
                    d[i][j + 1][k - (1 << (n - j - 1))] += d[i][j][k];
                }
                
            }
        }
    }

        var sum = 0;
        for (var k = 0; k < (1 << n); k++) {
            sum += d[m][0][k];
        }
        cout << sum;
}// your code goes here