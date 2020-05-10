// FISH와 FINISH 두 문자열에는 몇 개의 문자가 순서대로 같은가?

#include <cstdio>
#include <cstdlib>
#include <cstring>

void PrintArray(int** arr, int row, int col){
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int Max(int a, int b){
    return a > b ? a : b;
}

int Subsequence(const char* str1, const char* str2){
    int row = strlen(str1)+1;
    int col = strlen(str2)+1;
    int** arr = new int*[row];
    for (int i=0; i<row; ++i){
        arr[i] = new int[col];
    }
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            arr[i][j] = 0;
        }
    }
    for (int i=1; i<row; ++i){
        for (int j=1; j<col; ++j){
            if(str1[i-1] == str2[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = Max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    PrintArray(arr, row, col);

    int retValue = arr[row-1][col-1];

    for (int i=0; i<row; ++i){
        delete[] arr[i];
    }
    delete[] arr;
    return retValue;
}

int main(){
    printf("max : %d\n", Max(10, 20));
    printf("Subsequence : %d\n", Subsequence("FINISH", "FISH"));
    printf("Subsequence : %d\n", Subsequence("ABCDEF", "AFCDE"));
    printf("Subsequence : %d\n", Subsequence("ABCDEF", "FGDF"));
    system("pause");
}
