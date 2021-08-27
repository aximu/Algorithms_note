//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define max(a,b) (a>b?a:b)
//
//int findLongestCommonSubSequence(char* X, char* Y, int X_len, int Y_len)
//{
//    int dp[10][10];
//    int i, j;
//    for (i = 0; i < X_len; i++)
//        for (j = 0; j < Y_len; j++)
//            dp[i][j] = 0;
//
//    for (i = 1; i <= X_len; i++)
//    {
//        for (j = 1; j <= Y_len; j++)
//        {
//            if (X[i] == Y[j])
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            else
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    return dp[X_len][Y_len];
//}
//
//int main() {
//    char strA[10];
//    char strB[10];    
//    int x, y;
//    int result;
//
//    printf("Input char A:");
//    scanf("%s", strA);
//    printf("Input char B:");
//    scanf("%s", strB);
//
//    x = strlen(strA);
//    y = strlen(strB);
//
//    result =  findLongestCommonSubSequence(strA, strB, x, y);
//    printf("Output = %d\n", result);
//}


#include <stdio.h>
#include <string.h>
#define MAXLEN 50

//dynamic programming
void LCSLength(char* x, char* y, int m, int n, int c[][MAXLEN]) {
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 1; j <= n; j++)
        c[0][j] = 0;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {                          //仅仅去掉了对b数组的使用，其它都没变
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            }
            else {
                c[i][j] = c[i][j - 1];

            }
        }
    }
    printf("Lenth: %d\n", c[m][n]);

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
      
}
/*
void PrintLCS(int c[][MAXLEN], char *x, int i, int j) {         //非递归版PrintLCS
    static char s[MAXLEN];
    int k=c[i][j];
    s[k]='\0';
    while(k>0){
        if(c[i][j]==c[i-1][j]) i--;
        else if(c[i][j]==c[i][j-1]) j--;
        else{
            s[--k]=x[i-1];
            i--;j--;
        }
    }
    printf("%s",s);
}
*/
void PrintLCS(int c[][MAXLEN], char* x, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (c[i][j] == c[i - 1][j]) {
        PrintLCS(c, x, i - 1, j);
    }
    else if (c[i][j] == c[i][j - 1])
        PrintLCS(c, x, i, j - 1);
    else {
        PrintLCS(c, x, i - 1, j - 1);
        printf("%c ", x[i - 1]);
    }
}

int main() {
    char x[MAXLEN] = { "ABCBDAB" };         //最长子序列为：BCBA 
    char y[MAXLEN] = { "BDCABA" };
    //char x[MAXLEN] = {"ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"}; //算法导论上222页的DNA的碱基序列匹配
    //char y[MAXLEN] = {"GTCGTTCGGAATGCCGTTGCTCTGTAAA"};

    int  c[MAXLEN][MAXLEN];     //仅仅使用一个c表

    int m, n;

    m = strlen(x);
    n = strlen(y);

    LCSLength(x, y, m, n, c);
    PrintLCS(c, x, m, n);

    return 0;
}