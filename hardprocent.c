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

void SumProcentDeposit(long double *deposit, int time, float percent, long double *dopdeposit, long double *deposit1, long double *sumdeposit){ //вычиляет без реинвестирования с доп.вложениями
    percent = 1 + percent / 100;
    *deposit1 = *deposit;
    for(int i = 0; i < time; i++){
        *deposit = *deposit + *dopdeposit;
        *deposit1 = *deposit1 + *dopdeposit;

        *deposit = *deposit * percent;
        *deposit = *deposit - (*deposit - *deposit1);
    }
    *sumdeposit = time * (*deposit - *deposit1);
}

void MaxSumDeposit(long double *deposit, int time, float percent, long double *dopdeposit){ //реинвестирование с доп.платежами
    percent = 1 + percent / 100;
    for(int i = 0; i <  time; i++){
        *deposit = *deposit + *dopdeposit;
        *deposit = *deposit * percent;
    }
}

int main(){
    long double deposit, deposit1, sumdeposit, dopdeposit; 
    int time;
    float percent;
    char answer[10];

    printf("Введите сумму вклада:");
    scanf("%Lf", &deposit);
   
    printf("\nВведите процентную ставку:");
    scanf("%f", &percent);
   
    printf("\nВведите продолжительность вклада:");
    scanf("%d", &time);
  
    printf("\nРеинвестировать счёт?(да/нет)\n");
    scanf("%s", answer);
   
    printf("\nСумма дополнительных вложений:");
    scanf("%Lf", &dopdeposit);
    
    
    
    if(strcmp(answer, "да") == 0){ //блок с реинвестированием
        if(dopdeposit == 0){//реинвестирование без доп.вложений
        SumDeposit(&deposit, time, percent);
        
        printf("%.3Lf  ", deposit);
        }
        else{//реинвестирование с вложениями
            MaxSumDeposit(&deposit, time, percent, &dopdeposit);

            printf("Доход:%3.Lf", deposit);
        }
    }
    else{ //блок без реинвестирования
        if(dopdeposit == 0){//без реинвестирования без.доп вложений
        ProcentDeposit(&deposit, time, percent, &deposit1, &sumdeposit);
        
        printf("\nДоход процентами:%.1Lf", sumdeposit);
        printf("\nОбщий доход:%.1Lf", sumdeposit + deposit1);
        }
        else{//без реинвестирования с доп.вложениями
            SumProcentDeposit(&deposit, time, percent, &dopdeposit, &deposit1, &sumdeposit);

            printf("\nДоход процентами:%.1Lf", sumdeposit);
            printf("\nОбщий доход:%.1Lf", sumdeposit + deposit1);
        }
    }
    return 0;
}