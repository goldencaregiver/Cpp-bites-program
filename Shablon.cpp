#include <cstdio>
#include <cstdlib>
#include <cmath>

int main() {
	system("chcp 1251>nul");
	printf("Программа разработана \nстудентом учебной группы БББО-NN-25\
 $****** $.$. Вариант N\n\n");
	char c;
	do
	{
		// ввод четырехбайтного числа
		printf("Введите исходное число типа long\n");
		unsigned long L;
		scanf_s("%x", &L);
		printf("Исходное число %#010x\n", L);
		system("pause");
		// ввод двух двухбайтных чисел
		printf("Введите исходные числа типа short\n");
		unsigned short s1, s2;
		scanf_s("%hx%hx", &s1, &s2);
		printf("1-е исходное число %#06x, 2-е исходное число %#06x\n", s1, s2);
		system("pause");
		unsigned char b1, b2, b3, b4, * pb1, * pb2, * pb3, * pb4;
		//выделение байтов сдвигами
		b1 = (unsigned char)L;
		b2 = (unsigned char)(L >> 8);
		b3 = (unsigned char)(L >> 16);
		b4 = (unsigned char)(L >> 24);
		//выделение байтов указателями
		pb1 = (unsigned char*)&L;
		pb2 = (unsigned char*)&L + 1;
		pb3 = (unsigned char*)&L + 2;
		pb4 = (unsigned char*)&L + 3;
		printf("Байты исходного числа, выделенные сдвигами:\n");
		printf("1-й байт %#04x\n", b1);
		printf("2-й байт %#04x\n", b2);
		printf("3-й байт %#04x\n", b3);
		printf("4-й байт %#04x\n", b4);
		printf("Байты исходного числа, выделенные указателями:\n");
		printf("1-й байт %#04x\n", *pb1);
		printf("2-й байт %#04x\n", *pb2);
		printf("3-й байт %#04x\n", *pb3);
		printf("4-й байт %#04x\n", *pb4);
		system("pause");
		printf("\nСоздаю динамическую переменную типа unsigned short\n");
		printf("и помещаю туда сумму выделенных байтов\n");
		unsigned short* s = new unsigned short(*pb1 + *pb2 + *pb3 + *pb4);
		printf("\nСумма выделенных байтов %#06X, ее адрес %p\n\n", *s, s);
		system("pause");
		printf("\nДвоичное представление переменной,\n");
		printf("полученной на предыдущем этапе\n\n");
		for (int i = 15; i >= 0; i--) {
			printf("%d ", (*s >> i) & 1);
		}
		printf("\nВведите номер проверяемого бита (0 - 15)\n");
		int N, f = 1;
		do {
			printf("N = ");
			scanf_s("%u", &N);
			if (N < 0 || N > 15) {
				printf("Неверный ввод, повторите! ");
			}
			else {
				f = 0;
			}
		} while (f);
		if (*s & (unsigned short)pow(2, N))
			printf("Искомый бит равен 1\n");
		else
			printf("Искомый бит равен 0\n");
		system("pause");
		printf("\nСоздаю динамическую переменную типа unsigned long,\n");
		printf("в которой порядок байтов изменен на обратный, \n");
		printf("а каждый байт в отдельности сдвинут влево на 4 бита\n\n");
		unsigned long* pL = new unsigned long(0);
		*pb1 <<= 4;
		*pb2 <<= 4;
		*pb3 <<= 4;
		*pb4 <<= 4;
		*((unsigned char*)pL + 3) = *pb1;
		*((unsigned char*)pL + 2) = *pb2;
		*((unsigned char*)pL + 1) = *pb3;
		*(unsigned char*)pL = *pb4;
		printf("Результат %#010x\n\n", *pL);
		system("pause");
		// то же самое сдвигами
		*pL = 0;
		*pL = ((((((*pL | *pb1) << 8) | *pb2) << 8) | *pb3) << 8) | *pb4;
		printf("Результат %#010x\n\n", *pL);
		system("pause");
		printf("Для выхода из программы введите 1\n");
		int v;
		while ((v = getchar()) != '\n' && v != EOF) continue;  // очиска входного буфера после предыдущего ввода
		scanf_s("%c", &c, 1);
	} while (c != '1');
	return 0;
}