// FISH와 FINISH 두 문자열에는 몇 개의 문자가 순서대로 같은가?

#include <cstdio>
#include <cstdlib>
#include <cstring>

void PrintArray(int** arr, int row, int col){
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
}

int Subsequence(const char* str1, const char* str2){
    int row = strlen(str1)+1;
    int col = strlen(str2)+1;
    int** arr = new int*[row];
    for (int i=0; i<row; ++i)
        arr[i] = new int[col];
    for (int i=0; i<row; ++i)
        for (int j=0; j<col; ++i)
            arr[i][j] = 0;

    PrintArray(arr, row, col);

    for (int i=0; i<row; ++i)
        delete[] arr[i];
    delete[] arr;
    return 0;
}

int main(){
    printf("Subsequence : %d\n", Subsequence("FINISH", "FISH"));
    system("pause");
}
