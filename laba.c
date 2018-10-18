#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
const size = 10;
struct value {
	float q;
	float i;
};
void ReadData(struct value massif[], int *error)
{
	FILE *laba = fopen("data.txt", "r");
	if (laba == NULL) error = 1;
	else
	{
		for (int i = 0; i < size; i++)
		{
			fscanf(laba, "%f", &massif[i].q);
			fscanf(laba, "%f", &massif[i].i);
		}
		fclose(laba);
	}
	return;
}
void PrintfData(struct value a)
{
	printf("%f %f\n", a.q, a.i);
}
int main()
{
	int error = 0;
	struct value *C; // C - const
	C = (struct value*)calloc(size, sizeof(struct value));
	if (C == NULL)
	{
		printf("No memory\n");
		exit(1);
	}
	ReadData(C, error);
	PrintfData(C[2]);
	return 0;
}