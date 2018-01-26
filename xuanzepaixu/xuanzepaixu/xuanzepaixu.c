#include<stdio.h>
void sort(int*a, int len)
{
	int i, j, min, t;
	for (i = 0; i < len - 1; i++)
	{
		for (min = i, j = i + 1; j < len; j++)
		{
			if (a[min]>a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
}
int main()
{
	int a[6] = { 4, 0, 3, 2, 5, 1 };
	sort(a, 6);
	for (int i = 0; i < 6; i++)
		printf("%d\n", a[i]);
	return 0;
}