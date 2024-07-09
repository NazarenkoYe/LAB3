#include <stdio.h>

int countnumbers(int p) {
    int dp[2][p + 1];
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= p; i++) {
        dp[0][i] = dp[1][i-1];
        if (i > 2) {
                dp[0][i] += dp[1][i-2];
        }
        dp[1][i] = dp[0][i-1];
        if (i > 2) {
            dp[1][i] += dp[0][i-2];
        }
    }
    return dp[0][p] + dp[1][p];
}

int main() {
    int p;
    printf("Enter the number of digits p: ");
    scanf("%d", &p);
    if (p < 1 || p > 30) {
        printf("Invalid value for p. It should be in the range of 1 to 30.\n");
        return 1;
    }
    int result = countnumbers(p);
    printf("The number of %d-digit numbers: %d\n", p, result);
    return 0;
}
