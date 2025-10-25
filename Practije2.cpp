#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru_RU .utf8"); 
    system("chcp 1251 > nul");
    printf("Автор: Абалова В. Д., группа ЗРС2402, вариант 1\n\n");
    
    char choice;
    do {
        unsigned int num;
        printf("Введите число типа int в шестнадцатеричной системе: ");
        scanf_s("%x", &num);
        printf("Исходное число: 0x%08X\n\n", num);
        
        unsigned char byte1 = num & 0xFF;           // Младший байт
        unsigned char byte2 = (num >> 8) & 0xFF;    // Второй байт  
        unsigned char byte3 = (num >> 16) & 0xFF;   // Третий байт
        unsigned char byte4 = (num >> 24) & 0xFF;   // Старший байт
        
        printf("Выделенные байты исходного числа:\n");
        printf("Младший байт: 0x%02X\n", byte1);
        printf("Второй байт:  0x%02X\n", byte2);
        printf("Третий байт:  0x%02X\n", byte3);
        printf("Старший байт: 0x%02X\n\n", byte4);
        
        unsigned short* dynamicShort = new unsigned short;
        *dynamicShort = (byte4 << 8) | byte1;  
        
        printf("Динамическая переменная типа short:\n");
        printf("Значение: 0x%04X\n", *dynamicShort);
        printf("Адрес: %p\n\n", dynamicShort);
        
        // Перевод в двочику
        printf("Двоичное представление динамической переменной:\n");
        for (int i = 15; i >= 0; i--) {
            printf("%d", (*dynamicShort >> i) & 1);
            if (i % 4 == 0 && i != 0) printf(" ");  // Чтобы читать было удобнее
        }
        printf("\n\n");
        
        int bitNum;
        int validInput = 0;
        do {
            printf("Введите номер бита для проверки (0-15): ");
            scanf_s("%d", &bitNum);
            if (bitNum < 0 || bitNum > 15) {
                printf("Ошибка! Номер бита должен быть от 0 до 15.\n");
            } else {
                validInput = 1;
            }
        } while (!validInput);

        if (*dynamicShort & (unsigned short)pow(2, bitNum)) {
            printf("Искомый бит №%d равен 1\n", bitNum);

            printf("Меняем местами старший и младший байты в исходном числе\n");

            unsigned int originalNum = num;

            unsigned char* numPtr = (unsigned char*)&num;
            unsigned char temp = numPtr[0];  // Сохраняем младший байт и теперь будем менять их местами (как требуется по заданию ай гесс)
            numPtr[0] = numPtr[3];           // Младший = старший
            numPtr[3] = temp;                // Старший = младший
            
            printf("Исходное число до замены: 0x%08X\n", originalNum);
            printf("Исходное число после замены: 0x%08X\n", num);
        } else {
            printf("Искомый бит №%d равен 0\n", bitNum);
            printf("Замена байтов не выполняется\n");
        }
        
        printf("\nФинальные результаты:\n");
        printf("Динамическая переменная short: 0x%04X\n", *dynamicShort);
        printf("Адрес динамической переменной: %p\n", dynamicShort);
        printf("Исходное число (после возможных изменений): 0x%08X\n\n", num);
        
        // Освобождаем память, чтобы мой старенький ноутбук acer не взорвался
        delete dynamicShort;
        
        // Запрос по желанию пользователя :) 
        printf("Для выхода из программы введите 0, для продолжения - любую другую клавишу: ");
        scanf_s(" %c", &choice, 1);
        printf("\n");
        
    } while (choice != '0');
    
    return 0;
}