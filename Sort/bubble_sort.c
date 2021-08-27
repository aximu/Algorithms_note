 #include <stdio.h>
 #include <stdlib.h>

void bubble(int* a, int n)
{
    int i;
    if (n == 1) {
        return;
    }
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            int t = a[i]; 
            a[i] = a[i + 1]; 
            a[i + 1] = t;
        }
    }
    bubble(a, n - 1);
}

 int main()
 {
     int i, n, a[100];
 
      printf("请输入数组中元素数量（不大于100个）：");
      scanf("%d", &n);
 
      for (; n < 1 || n>100;) {
          printf("元素数量超出范围，请重新输入：");
          scanf("%d", &n);
      
      }
      printf("\n");
 
      for (i = 0; i < n; i++) {
          printf("请输入元素a[%d]：", i);
          scanf("%d", &a[i]);
      }
      printf("\n");
 
      printf("您输入了以下元素：\n");
      for (i = 0; i < n; i++) {
          printf("%d ", a[i]);
      }
      printf("\n");
 
      bubble(a, n);
 
      printf("递增排列为：\n");
      for (i = 0; i < n; i++) {
          printf("%d ", a[i]);
      }
      printf("\n");
 
      system("pause");
      return 0;
   }
 
