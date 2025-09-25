#include <stdio.h>

int Batasatas(int T[], int N, int X) {
    int low = 0, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (T[mid] > X) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    int T[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }
    
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int kiri = Batasatas(T, N, x);
        int kanan = Batasatas(T, N, y);
        int cnt = kanan - kiri;
        printf("%d\n", cnt);
    }
    return 0;
}
