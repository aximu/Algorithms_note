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
 
      printf("������������Ԫ��������������100������");
      scanf("%d", &n);
 
      for (; n < 1 || n>100;) {
          printf("Ԫ������������Χ�����������룺");
          scanf("%d", &n);
      
      }
      printf("\n");
 
      for (i = 0; i < n; i++) {
          printf("������Ԫ��a[%d]��", i);
          scanf("%d", &a[i]);
      }
      printf("\n");
 
      printf("������������Ԫ�أ�\n");
      for (i = 0; i < n; i++) {
          printf("%d ", a[i]);
      }
      printf("\n");
 
      bubble(a, n);
 
      printf("��������Ϊ��\n");
      for (i = 0; i < n; i++) {
          printf("%d ", a[i]);
      }
      printf("\n");
 
      system("pause");
      return 0;
   }
 
