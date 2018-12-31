#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
typedef struct value {
	float q;
	float i;
} value;
int CountValue(int error);
int CountMassif(int error);
void ReadValue(value massif[], int *error);
void PrintValue(value a, FILE *print);
value Amount(value a, value b);
float RelativeError(value a);
float ReadMassif(float massif[], int error);
value CountMedium(float massif[], int size_m);
int main()
{
	int size = 0; // ������ ������� �������� � ������������
	int error = 0;
	size = CountValue(error);
	value *C; // ������ �������� � ������������
	C = (value*)calloc(size, sizeof(value));
	if (C == NULL)
	{
		printf("No memory\n");
		exit(1);
	}
	ReadValue(C, error);
	value x;
	x = Amount(C[0], C[5]);
	FILE *print = fopen("result.txt", "a");
	PrintValue(x, print);
	int size_m = 0; // ������ ������� � �����������
	size_m = CountMassif(error);
	float *M; // ������ � �����������
	M = (float*)calloc(size_m, sizeof(float));
	if (M == NULL)
	{
		printf("No memory\n");
		exit(1);
	}
	ReadMassif(M, error);
	value Medium; // ������� �������� �� ������� � ������������
	Medium = CountMedium(M, size_m);
	PrintValue(Medium, print);
	fclose(print);
	return 0;
}
int CountValue(int error) // ������� ���������� �������� � ������������ � �����
{
	int size = 0;
	FILE *laba = fopen("data.txt", "r");
	float a;
	if (laba == NULL) error = 1;
	else
	{
		for (int i = 0;; i++)
		{
			if (fscanf(laba, "%f", &a) == EOF) break;
			size++;
		}
		fclose(laba);
	}
	return size / 2;
}
int CountMassif(int error) // ������� ���������� ������ � �����
{
	int size_m = 0;
	FILE *laba = fopen("massif.txt", "r");
	float a;
	if (laba == NULL) error = 1;
	else
	{
		for (int i = 0;; i++)
		{
			if (fscanf(laba, "%f", &a) == EOF) break;
			size_m++;
		}
		fclose(laba);
	}
	return size_m;
}
void ReadValue(value massif[], int *error) // ��������� ��������� � ������������ � ������
{
	FILE *laba = fopen("data.txt", "r");
	if (laba == NULL) error = 1;
	else
	{
		for (int i = 0;; i++)
		{
			if (fscanf(laba, "%f", &massif[i].q) == EOF) break;
			fscanf(laba, "%f", &massif[i].i);
		}
		fclose(laba);
	}
	return;
}
void PrintValue(value a, FILE *print) // �������� ���� ��������� � ������������
{
	fprintf(print, "%f %f\n", a.q, a.i);
}
value Amount(value a, value b) // ������� ����� �������� � ����������� �����
{
	value sum;
	sum.q = a.q + b.q;
	sum.i = sqrt(pow(a.i, 2) + pow(b.i, 2));
	return sum;
}
float RelativeError(value a) // ������� ������������� ����������� ���������
{
	return pow(a.i / a.q, 2);
}
float ReadMassif(float massif[], int error) // ��������� ������ ���������
{
	FILE *data = fopen("massif.txt", "r");
	if (data == NULL) error = 1;
	else
	{
		for (int i = 0;; i++)
		{
			if (fscanf(data, "%f", &massif[i]) == EOF) break;
		}
		fclose(data);
	}
}
value CountMedium(float massif[], int size_m) // ������� ������� �������� � ������� � ����������� ��������
{
	value a;
	float sum1 = 0, sum2 = 0, n1 = 0, n2 = 0;
	for (int i = 0; i < size_m; i++)
	{
		sum1 += massif[i];
		n1++;
	}
	a.q = sum1 / n1;
	for (int j = 0; j < size_m; j++)
	{
		sum2 += pow(massif[j] - sum1 / n1, 2);
		n2++;
	}
	a.i = sqrt(sum2 / (n2*(n2 - 1)));
	return a;
}

