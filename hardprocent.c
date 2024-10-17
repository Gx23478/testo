#include <stdio.h>
#include <string.h>

void SumDeposit(long double *deposit, int time, float percent){ //вычисляет доход с учётом реинвестирования
    percent = 1 + percent / 100;
    for(int i = 0; i < time; i++){
        *deposit = *deposit * percent;
    }
    
}

void ProcentDeposit(long double *deposit, int time, float percent, long double *deposit1, long double *sumdeposit){ //вычисляет доход без реинвестирования
    percent = 1 + percent / 100;
    *deposit1 = *deposit;
    *deposit = *deposit * percent;
    *sumdeposit  = time * (*deposit - *deposit1);
    
}

int main(){
    long double deposit, deposit1, sumdeposit; 
    int time;
    float percent;
    char answer[10];

    printf("Введите сумму вклада:");
    scanf("%Lf", &deposit);
    printf("\nВведите процентную ставку:");
    scanf("%f", &percent);
    printf("\nВведите продолжительность вклада:");
    scanf("%d", &time);
    printf("Реинвестировать счёт?(да/нет)\n");
    scanf("%s", answer);
    
    if(strcmp(answer, "да") == 0){
        SumDeposit(&deposit, time, percent);
        
        printf("%.3Lf  ", deposit);
    }
    else{
        ProcentDeposit(&deposit, time, percent, &deposit1, &sumdeposit);
        
        printf("\nДоход процентами:%.1Lf", sumdeposit);
        printf("\nОбщий доход:%.1Lf", sumdeposit + deposit1);
    }
    

    return 0;
}