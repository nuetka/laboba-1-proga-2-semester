#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>   
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define m 255  // Длина массива для исходной строки 
// функция для ввода строки
void input(char a[]) {
	int s, flag, zeichen;
	do {
		s = flag =  zeichen = 0;
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
				
				 if (a[i] == ',' || a[i] == '.' || a[i] == ' ' || a[i] == '!' || a[i] == '?' || a[i] == '-' || a[i] == ';' || a[i] == ':') {
					zeichen += 1;
				}
			}
			if ((flag==1)&&(zeichen == (s))) {
				puts("\nОшибка! Попробуйте снова!");
			}
		}
	} while (zeichen == s);
		a[s] = '\0';

	
}// вывод строки
void print(char a[]) {
	int i = 0;
	while (a[i] != '\0') {
		putchar(a[i]);
		i++;
	}
}
// поиск слов из первого массива которые начинаюися на символы из второго массива
void search(char a[], char b[]) {
	int i = 0, j, flag;
	while (a[i] != '\0') {

		if ((a[i] != 32) && (a[i] != ',' && a[i] != '.' && a[i] != ' ' && a[i] != '!' && a[i] != '?' && a[i] != '-' && a[i] != ';' && a[i] != ':')) {
			j = 0, flag = 0;
				while ((b[j] != '\0') && flag == 0) {
					if (a[i] == b[j]) flag = 1;
					else j++;
				}
			if (flag == 1) {
				while ((a[i]!='\0')&&(a[i] != 32) && (a[i] != ',' && a[i] != '.' && a[i] != ' ' && a[i] != '!' && a[i] != '?' && a[i] != '-' && a[i] != ';' && a[i] != ':')) {
					putchar(a[i]);
					i++;
				}
				printf("\n");
			}
			else {
				while((a[i]!='\0')&&(a[i] != 32) && (a[i] != ',' && a[i] != '.' && a[i] != ' ' && a[i] != '!' && a[i] != '?' && a[i] != '-' && a[i] != ';' && a[i] != ':')) {
				     i++;
			     }

			}
		}
		else  i++;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	puts("Поиск слов в тексте, начинающихся с символов, указанных отдельной строкой.");
	puts("Работа с основными строками происходит без использования стандартных функций");
	char text[m], str[m];
do{
	puts("введите текст (символы-разделители слов:,. ?!-;:):");
	input(text);
	puts("\nвведённый массив: ");
	print(text);
	puts("\nвведите символы, на которые должны начинаться искомые слова:");
	input(str);
	puts("\nВы ввели символы:");
	print(str);
	puts("\n\nсписок слов из текста, начинающихся на заданные символы:");
	search(text, str);
puts("\n\nНажмите любую клавишу для продолжения и Esc для окончания работы программы\n");
} while (_getch() != '27');
}