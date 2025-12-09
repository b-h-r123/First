#include<stdio.h>
#define N 5

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void transform(int a[N][N]) {
    int *arr = &a[0][0];  // 统一用arr
    int n = N * N;
    int i;
    int j;

    // 修复选择排序：选前4最小到arr[0..3]
    for (i = 0; i < 4; i++) {
        int min_idx = i;
        for (j = i; j < n; j++) {  // 从i开始，范围到末尾
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(arr + i, arr + min_idx);
    }
    // 现在 arr[0..3] = 1,2,3,4 (顺序正确，因为每次选剩余最小)

    // 删除你那趟无用冒泡

    // 放25到中心下标12
    swap(arr + 12, arr + 24);

    // 放1,2,3,4到四角 (0,4,20,24)
    // arr[0]已是1，arr[4]已是原来21 → 换成2 (arr[1])
    swap(arr + 4, arr + 1);   // 右上:2
    swap(arr + 20, arr + 2);  // 左下:3
    swap(arr + 24, arr + 3);  // 右下:4 (此时24是原中心13，被挤走)

    // 正确打印四角+中心
    printf("%d   %d\n\n\n\n%d   %d\n  %d  \n", a[0][0], a[0][4], a[4][0], a[4][4], a[2][2]);
    // 或更紧凑：printf("%d %d\n%d %d\n  %d  \n", ...);
}

int main() {
    int a[N][N];
    int k = N*N;
    int i;
    int j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = k--;
    transform(a);
    return 0;
}
