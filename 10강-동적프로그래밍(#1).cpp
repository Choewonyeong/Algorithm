// 피보나치 수 동적 계획법 알고리즘 분석
#include <cstdio>
#include <cstdlib>

int Fibonacci(int n, int c1, int c2){
    int* arr = new int[n+1];
    arr[0] = c1;
    arr[1] = c2;
    for (int i=2; i<=n; ++i){
        arr[i] = arr[i-1] + arr[i-2];
    }
    int retValue = arr[n];
    delete[] arr;

    return retValue;
}

int main(){
    printf("fibonacci : %d\n", Fibonacci(4, 1, 2));
    printf("fibonacci : %d\n", Fibonacci(4, 2, 3));
    printf("fibonacci : %d\n", Fibonacci(10, 1, 2));
    system("pause");
}