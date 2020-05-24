/*
6리터의 가방에 최대한 과일을 많이 담으려면?
- 과일 질량, 과일 가격
(1) 배 : 5L / 2,500원
(2) 바나나 : 3L / 1,500원
(3) 사과 : 2L / 1,500원
(4) 딸기 : 1L / 2,000원
*/

#include <cstdio>
#include <cstdlib>

struct Fruit{
    const char* name;
    int size;
    int price;

};

void PrintFruits(Fruit fruit[], int countFruits){
    for (int i = 0; i < countFruits; ++i){
        printf("%s, %d, %d\n", fruit[i].name, fruit[i].size, fruit[i].price);
    }
}

int main(){
    Fruit fruits[4] = {{"배", 5, 2500},
                      {"바나나", 3, 1500},
                      {"사과", 2, 1500},
                      {"딸기", 1, 2000}};
    
    PrintFruits(fruits, 4);
    system("pause");
}