/*
1000원으로 330원의 음료를 구입하고 최소의 동전 개수로 거스름돈을 반환하려면?
- 동전의 유형 : 500원, 100원, 50원, 10원, 1원
*/


#include <cstdio>
#include <cstdlib>

void Refund(int moneyType[], int ch){
    int change = ch;
    int count = 0;
    while( change / moneyType[0] ){
        ++count;
        printf("%d원 : %d\n",  moneyType[0], count);
        change -= moneyType[0];
        printf("남은 돈 : %d\n",  change);
    }
    count = 0;
    while( change / moneyType[1] ){
        ++count;
        printf("%d원 : %d\n",  moneyType[1], count);
        change -= moneyType[1];
        printf("남은 돈 : %d\n",  change);
    }
    count = 0;
    while( change / moneyType[2] ){
        ++count;
        printf("%d원 : %d\n",  moneyType[2], count);
        change -= moneyType[2];
        printf("남은 돈 : %d\n",  change);
    }
    count = 0;
    while( change / moneyType[3] ){
        ++count;
        printf("%d원 : %d\n",  moneyType[3], count);
        change -= moneyType[3];
        printf("남은 돈 : %d\n",  change);
    }
    count = 0;
    while( change / moneyType[4] ){
        ++count;
        printf("%d원 : %d개\n",  moneyType[4], count);
        change -= moneyType[4];
        printf("남은 돈 : %d\n",  change);
    }
}


int main(){
    int moneyType[5] = {500, 100, 50, 10, 1};
    int change = 670;
    Refund(moneyType, change); 
    system("pause");
}