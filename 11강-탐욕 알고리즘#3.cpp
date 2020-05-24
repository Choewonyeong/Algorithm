/*
1000원으로 330원의 음료를 구입하고 최소의 동전 개수로 거스름돈을 반환하려면?
- 동전의 유형 : 500원, 100원, 50원, 10원, 1원
*/


#include <cstdio>
#include <cstdlib>

void Refund(int moneyType[], int ch, int countMoneyType[]){
    int change = ch;
    for (int i = 0; i < 5; ++i){
        int count = 0;
        for (count = 0; change/moneyType[i]; ++count){
            change -= moneyType[i];
        }
        countMoneyType[i] = count;
    }
}


int main(){
    int moneyType[5] = {500, 100, 50, 10, 1};
    int countMoneyType[5] = {0};
    int money = 0;
    printf("입력 : ");
    scanf("%d", &money);
    int change = 1000-money;
    Refund(moneyType, change, countMoneyType); 
    for (int i = 0; i < 5; ++i){
        printf("%d원 : %d개\n",  moneyType[i], countMoneyType[i]);
    }
    int cmpChange = 0;
    for (int i = 0; i < 5; ++i){
        cmpChange += moneyType[i] * countMoneyType[i];
    }
    printf("%d = %d\n", change, cmpChange);
    system("pause");
}