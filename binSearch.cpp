#include <iostream>
#include <cstdio>

int binSearch(int* S, int e, int lo, int hi){
    // 返回不大于e的最大pos
    while (lo < hi){    // 切记while终止条件
        int mi = (lo + hi) >> 1;
        (e < S[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

int main()
{
    int S[] = {1, 2, 3, 4, 5, 6, 9};
    printf("The pos of 7 is: %d \n", binSearch(S, 7, 0, 7));
    printf("The pos of 0 is: %d \n", binSearch(S, 0, 0, 7));
    printf("The pos of 6 is: %d \n", binSearch(S, 6, 0, 7));
    return 0;
}