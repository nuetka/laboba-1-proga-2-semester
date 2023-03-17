#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>   
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <cmath>
#include <Windows.h>
#define m 255  // Длина массива для исходной строки 
// функция для ввода строки
void input(char a[]) {
	int s, flag,
		zeichen;// знаки
	do {
		s = flag = zeichen = 0;
		for (int i = 0; (i < m) && (flag == 0); i++)
		{
			a[i] = _getch();
			if (a[i] == 13) {   //проверяем код символа 13 -> Enter
				flag = 1;
			}
			else if (flag == 0)
			{
				s++;
				putchar(a[i]);  //выводим символ на экран

				if ( a[i] == '.' || a[i] == ' ' || a[i] == '!' || a[i] == '?' || a[i] == '-' || a[i] == ';' || a[i] == ':') {
					zeichen += 1;
				}
			}
			if ((flag == 1) && (zeichen == (s))) {
				puts("\nОшибка! Попробуйте снова!");
			}
		}
	} while (zeichen == s);
	a[s] = '\0';

}
// вывод строки
void print(char a[]) {
	int i = 0;
	while (a[i] != '\0') {
		putchar(a[i]);
		i++;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	puts("Дан  текст.  Определить,  сколько  в  тексте  слов,  запись  которых  соответствует\n представлению вещественной или целой константы. \nНайти сумму всех таких чисел текста.");
	puts("Работа с основными строками происходит без использования стандартных функций");
	do {
		char text[m];
		puts("введите текст (символы-разделители слов:. ?!-;:):");
		input(text);
		puts("\nвведённый массив: ");
		print(text);

		int i = 0,
			num,// кол-во цифр в слове
			comma,// кол-во запятых
			sign,// положительное или отрицательное число
			k,// всего символов с слове
			zahlen=0,sum=0,kkk,
			bevorc,// кол-во чисел в слове до запятой
			flag;
		double sum1=0;
		while (text[i] != '\0') {
			sign = 1, comma = 0,num=0,bevorc=0, flag=0;
			// подсчёт в отдельном слове кол-ва цифр, запятых и есть ли перед ним - или нет
			if (text[i] == '-') sign = 0;
			k = 0;
			
			while ((text[i+k] != '\0') && (text[i+k] != 32) && (text[i+k] != '.' && text[i+k] != ' ' && text[i+k] != '!' && text[i+k] != '?' && text[i+k] != ';' && text[i+k] != ':')) {
				if (text[i + k] >= '0' && text[i + k] <= '9') {
					num += 1;
					if (flag == 0) {
						bevorc += 1;
					}
				}
				if (text[i + k] == ',') {
					comma += 1; flag = 1;
				}
				k++;
			}
			// чтобы запятая не была в слове на первом и последнем месте
			if (text[i] == ',') comma -= 1;
			if (text[i + k - 1] == ',') comma -= 1;
			//подсчёт суммы для целого положитеьного числа
			if (k == num&& num!=0) {
				kkk = 0;
				zahlen += 1;
				num = k - 1;
					do {
						switch (text[i + kkk])
						{
						case '0':sum += 0 * pow(10,num);break;
						case '1':sum += 1 * pow(10,num);break;
						case '2':sum += 2 * pow(10,num);break;
						case '3':sum += 3 * pow(10,num);break;
						case '4':sum += 4 * pow(10,num);break;
						case '5':sum += 5 * pow(10,num);break;
						case '6':sum += 6 * pow(10,num);break;
						case '7':sum += 7 * pow(10,num);break;
						case '8':sum += 8 * pow(10,num);break;
						case '9':sum += 9 * pow(10,num);break;
							
						}
						kkk += 1;
						num -= 1;
					} while (kkk < k);			
						
			}
			// подсчёт сцммы для цеолого отрицательного числа
			else if (sign == 0 && k == (num + 1)&&num!=0) {
				kkk = 1;
				zahlen += 1;
				num = num - 1;
				do {
					switch (text[i + kkk])
					{
					case '0':sum -= 0 * pow(10, num); break;
					case '1':sum -= 1 * pow(10, num); break;
					case '2':sum -= 2 * pow(10, num); break;
					case '3':sum -= 3 * pow(10, num); break;
					case '4':sum -= 4 * pow(10, num); break;
					case '5':sum -= 5 * pow(10, num); break;
					case '6':sum -= 6 * pow(10, num); break;
					case '7':sum -= 7 * pow(10, num); break;
					case '8':sum -= 8 * pow(10, num); break;
					case '9':sum -= 9 * pow(10, num); break;

					}

					kkk += 1;
					num -= 1;
				} while (kkk < k);

				
			}
		// подсчёт суммы для вещественного положительного числа
			else if((comma==1)&&(k == (num + 1))&&num!=0) {
				zahlen += 1;
				kkk = 0;
				bevorc -= 1;
				
				do {
					switch (text[i + kkk])
					{
					case '0':sum1 += 0 * pow(10, bevorc); break;
					case '1':sum1 += 1 * pow(10, bevorc); break;
					case '2':sum1 += 2 * pow(10, bevorc); break;
					case '3':sum1 += 3 * pow(10, bevorc); break;
					case '4':sum1 += 4 * pow(10, bevorc); break;
					case '5':sum1 += 5 * pow(10, bevorc); break;
					case '6':sum1 += 6 * pow(10, bevorc); break;
					case '7':sum1 += 7 * pow(10, bevorc); break;
					case '8':sum1 += 8 * pow(10, bevorc); break;
					case '9':sum1 += 9 * pow(10, bevorc); break;

					}
					bevorc -= 1;
					kkk += 1;
				} while (text[i + kkk] != ',');
				kkk += 1;
				do{
					
					switch (text[i + kkk])
					{
					case '0':sum1 += 0 * pow(10, bevorc); break;
					case '1':sum1 += 1 * pow(10, bevorc); break;
					case '2':sum1 += 2 * pow(10, bevorc); break;
					case '3':sum1 += 3 * pow(10, bevorc); break;
					case '4':sum1 += 4 * pow(10, bevorc); break;
					case '5':sum1 += 5 * pow(10, bevorc); break;
					case '6':sum1 += 6 * pow(10, bevorc); break;
					case '7':sum1 += 7 * pow(10, bevorc); break;
					case '8':sum1 += 8 * pow(10, bevorc); break;
					case '9':sum1 += 9 * pow(10, bevorc); break;

					}
					bevorc -= 1;
					kkk += 1;
				} while (kkk < k);

			}
			// подсчёт суммы для отрицательного вещественного числа
			else if ((comma == 1)&&(sign==0) && (k == (num + 2))&&num!=0) {
			zahlen += 1;
			kkk = 1;
			bevorc -= 1;

			do {
				switch (text[i + kkk])
				{
				case '0':sum1 -= 0 * pow(10, bevorc); break;
				case '1':sum1 -= 1 * pow(10, bevorc); break;
				case '2':sum1 -= 2 * pow(10, bevorc); break;
				case '3':sum1 -= 3 * pow(10, bevorc); break;
				case '4':sum1 -= 4 * pow(10, bevorc); break;
				case '5':sum1 -= 5 * pow(10, bevorc); break;
				case '6':sum1 -= 6 * pow(10, bevorc); break;
				case '7':sum1 -= 7 * pow(10, bevorc); break;
				case '8':sum1 -= 8 * pow(10, bevorc); break;
				case '9':sum1 -= 9 * pow(10, bevorc); break;

				}
				bevorc -= 1;
				kkk += 1;
			} while (text[i + kkk] != ',');
			kkk += 1;
			do {
				switch (text[i + kkk])
				{
				case '0':sum1 -= 0 * pow(10, bevorc); break;
				case '1':sum1 -= 1 * pow(10, bevorc); break;
				case '2':sum1 -= 2 * pow(10, bevorc); break;
				case '3':sum1 -= 3 * pow(10, bevorc); break;
				case '4':sum1 -= 4 * pow(10, bevorc); break;
				case '5':sum1 -= 5 * pow(10, bevorc); break;
				case '6':sum1 -= 6 * pow(10, bevorc); break;
				case '7':sum1 -= 7 * pow(10, bevorc); break;
				case '8':sum1 -= 8 * pow(10, bevorc); break;
				case '9':sum1 -= 9 * pow(10, bevorc); break;
				}

				bevorc -= 1;
				kkk += 1;
			} while (kkk < k);		

			}
			if (k>0) {
				i = i + k;
			}
			else i += 1;
		}	
		sum1 += (double)sum;	
		printf("\nСумма чисел: %lf", sum1);
		printf("\nКол-во чисел: %d", zahlen);
		puts("\n\nНажмите любую клавишу для продолжения и Esc для окончания работы программы\n");
	} while (_getch() != '27');

}