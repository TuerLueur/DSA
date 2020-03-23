#include <iostream>
#include <cstdio>

int inversion_cnt = 0;  // 统计逆序对数目

void merge(int* S, int lo, int mi, int hi){
    int* A = S + lo;
    int lb = mi - lo;
    int* B = new int[lb];
    for (int i = 0; i < lb; i++)    B[i] = A[i];
    int lc = hi - mi;
    int *C = S + mi;
    for (int i = 0, j = 0, k = 0; j < lb; ){
        if ((C[k] < B[j]) && k < lc) A[i++] = C[k++];
        if ((B[j] <= C[k]) || k >= lc){
            A[i++] = B[j++];
            inversion_cnt += (lc - k);
        }
    }
}

void mergeSort(int* S, int lo, int hi){
    if (hi - lo < 2) return;
    int mi = (lo + hi) >> 1;
    mergeSort(S, lo, mi);
    mergeSort(S, mi, hi);
    merge(S, lo, mi, hi);
}

void printList(int* S, int len){
    for (int i = 0; i < len; i++){
        printf("%d ", S[i]);
    }
    printf("\n");
}

int main()
{
    int S[] = {2, 9, 3, 5, 7, 3, 1};
    printf("before: ");
    printList(S, 7);
    mergeSort(S, 0, 7);
    printf("after: ");
    printList(S, 7);
    printf("inversion pair amount is: %d\n", inversion_cnt);
    return 0;
}