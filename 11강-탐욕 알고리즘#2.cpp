/*
1000원으로 330원의 음료를 구입하고 최소의 동전 개수로 거스름돈을 반환하려면?
- 동전의 유형 : 500원, 100원, 50원, 10원, 1원
*/


#include <cstdio>
#include <cstdlib>

void Refund(int moneyType[], int ch, int countMoneyType[]){
    int change = ch;
    int count;
    for (int i = 0; i < 5; ++i){
        count = 0;
        while( change / moneyType[i] ){
            ++count;
            printf("%d원 : %d\n",  moneyType[i], count);
            change -= moneyType[i];
            printf("남은 돈 : %d\n",  change);
        }
        countMoneyType[i] = count;
    }
    for (int i = 0; i < 5; ++i){
            printf("%d원 : %d개\n",  moneyType[i], countMoneyType[i]);
    }
}


int main(){
    int moneyType[5] = {500, 100, 50, 10, 1};
    int countMontyType[5] = {0};
    int change = 670;
    Refund(moneyType, change, countMontyType); 
    system("pause");
}