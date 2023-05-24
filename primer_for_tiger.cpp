#include<iostream>
#include<ctime>
#include<Windows.h>

#define red SetConsoleTextAttribute(color, 4)
#define green SetConsoleTextAttribute(color, 2)
#define white SetConsoleTextAttribute(color, 15)
#define void_col SetConsoleTextAttribute(color, 0)
#define size_primer 5  //максимальное количесво чисел с верху и снизу
#define size_number 100 //максимальное возможное число которое можео встретить в примере
#define ansver_limitStart 10//самое большое число которым может быть ответ
#define ansver_limitEnd 10//самое малое число которым может быть ответ(без знака -)
//Я бы предпочел что бы ты считал(а) все примеры устно
using namespace std;

void main()
{
	srand(time(NULL));
	HANDLE color{ GetStdHandle(STD_OUTPUT_HANDLE) };

	int access{ 10 }, first_error{};

	for (int i{}; i < 10; i++)
	{
		system("cls");
		white;

		cout << "primer:\t" << i + 1 << "/10\nyour access:\t"<<access<<"\n\n";
		int sizeA{ rand() % (size_primer-1) + 2 }, sizeB{ rand() % (size_primer-1) + 2 }, * A, * B, size_char{ sizeA - 1 };
		int top{}, ansver{}, piple_ansver{};
		double bott{};

		string simble{};

		A = new int[sizeA];
		B = new int[sizeB];

		for (int i = 0; i < sizeA; i++)
			A[i] = rand() % size_number + 1;

		for (int i = 0; i < size_char; i++)
		{
			int help{};
			help = rand() % 2;

			if (help)
				simble += '+';
			else
				simble += '-';
		}

		top = A[0];

		for (int i = 0; i < sizeA - 1; i++)
			if (simble[i] == '+')
				top += A[i + 1];
			else
				top -= A[i + 1];

		do
		{
			ansver = rand() % (ansver_limitEnd+1) - ansver_limitStart;
			bott = (double)((double)top / (double)ansver);
		} while (bott != (int)bott && bott != 0);

		for (int i{}; i < sizeB - 1; i++)
		{
			B[i]= rand() % size_number + 1;

			if (bott < 0)
			{
				bott += B[i];
				B[i] *= -1;
			}
			else
				bott -= B[i];
		}
		B[sizeB - 1] = bott;

		cout << '(';
		for (int i = 0; i < sizeA - 1; i++)
		{
			cout << A[i] << simble[i];
		}
		cout << A[sizeA - 1] << ") / (" << B[0];
		for (int i{ 1 }; i < sizeB; i++)
		{
			B[i] < 0 ? cout << B[i] : cout << '+' << B[i];
		}
		cout << ") =\t";
		cin >> piple_ansver;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			red;
			cout << "error ansver is:\t" << ansver << '\n';
			if (!first_error)
			{
				first_error++;
				access -= 2;
			}
			access--;

			void_col;
			system("pause");

			if (!(access - 1))
				break;
			
			continue;
		}

		green;
		if (piple_ansver == ansver)
			cout << "you right\n";
		else
		{
			red;
			cout << "error ansver is:\t"<<ansver<<'\n';
			if(!first_error)
			{
				first_error++;
				access -= 2;
			}
			access--;
		}

		void_col;
		system("pause");

		if (!(access-1))
			break;
	}

	system("cls");
	SetConsoleTextAttribute(color, 6);
	if (access <= 4)
		red;
	else if (access > 7)
		green;

	cout << "your access is " << access;

	void_col;
}
