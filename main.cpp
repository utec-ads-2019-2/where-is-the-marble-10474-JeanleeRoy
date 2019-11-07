#include <algorithm>
#include <cstdio>
using namespace std;

int bsearch(int *A, int x, int y, int v) {
    int m;
    while(x < y) {
        m = x + (y-x)/2;
        if(A[m] >= v) y = m;
        else x = m+1;
    }
    return x;
}

int a[10100], b[10100];

int main() {
    int n, q;
    int cas = 0;
    while(scanf("%d%d", &n, &q) != EOF) {
        if(n==0 && q==0)
            break;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < q; i++) {
            scanf("%d", &b[i]);
        }
        sort(a, a+n);
        printf("CASE# %d:\n", ++cas);
        for(int i = 0; i < q; i++) {
            printf("%d ", b[i]);
            int t = bsearch(a, 0, n-1, b[i]);
            if(a[t] == b[i])
                printf("found at %d\n", t+1);
            else
                printf("not found\n");
        }
    }
}
