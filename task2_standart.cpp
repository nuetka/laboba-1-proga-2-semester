#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define m 255  // Длина массива для исходной строки 
int main() {
	setlocale(LC_ALL, "Rus");
	puts("Дан  текст.  Определить,  сколько  в  тексте  слов,  запись  которых  соответствует\n представлению вещественной или целой константы. \nНайти сумму всех таких чисел текста.");
	puts("Программа написана с использованием стандартных функций обработки строк");
	do {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		char* s,                // s - исходная строка
			* str[m];       // str - массив указателей на отдельные слова в строке s ; 
		int n, i,k,count, zahlen = 0, sum=0;// n - количество слов, i,j - индексы 
		double sum1 = 0;
			
		s = (char*)calloc(m, sizeof(char));

		do {
			do {
				puts("Введите текст (символы-разделители слов: ?!;.:):");
				scanf("%[^\n]", s);
				while (getchar() != '\n');
			} while (s[0] == NULL); //Зациклить ввод, чтобы не ввели пустую строку 
			puts("Вы ввели текст:");
			puts(s);
			str[0] = strtok(s, " ?!;.:");
		} while (str[0] == NULL); //Зациклить ввод строки, чтобы не была введена строка из одних разделителей

		//Формирование массива указателей слов
		for (i = 1; str[i] = strtok(NULL, " ?!;.:"); i++);
		n = i;    // n – количество слов
		puts("Слова из текста, которые попали в массив указателей:");
		for (i = 0; i < n; i++) printf("%s ", str[i]); //вместо str[i] можно писать *(str+i) 
		printf("\n");	

		for (i = 0; i < n; i++) {
			k = 0, count = 0;
			while ((*(str + i))[k] != '\0') {
				if (((((*(str + i))[k]) == ','))) count += 1;
				k++;
			}
			if (count == 1) {
	      if ((((strspn((*(str + i)), ",-0123456789"))))==strlen(((*(str + i))))) {
					if ((strspn((*(str + i)), "-") == 1) || (strspn((*(str + i)), "-") == 0)) {
						if (((*(str + i))[0] != ',') && ((*(str + i))[strlen(*(str + i)) - 1] != ',')) {
							zahlen += 1;
							sum1 += atof((*(str + i)));		
						}
					}
				}
			}
		   else if ((atoi(*(str + i))&&((strlen(*(str + i))) == (strlen(_itoa(atoi(*(str + i)), (*(str + i)), 10)))))) {					zahlen += 1;
					sum += atoi(*(str + i));
				}			
		}
		sum1 += (double)sum;
		printf("Слов-чисел: %d\n", zahlen);
		printf("Сумма: %lf \n", sum1);

		free(s);
		puts("\nНажмите любую клавишу для продолжения и Esc для окончания работы программы\n");
	} while (_getch() != '27');
}