#include <stdio.h>
int main(void)
{
	int p = 0, k = 0, i;
	char c[100];
	scanf_s("%s", c);
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '_')
		{
			p = 1;
			if (c[i + 1] == '\0' || c[i + 1] == '_' || i == 0)
				k = 1;
		}
		if (c[i] >= 'A'&&c[i] <= 'Z')
		{
			k = 1;
			if (i == 0)
				p = 1;
		}
	}
	if (p == 1 && k == 1)
		printf("Error!");
	else
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= 'a'&&c[i] <= 'z')
			printf("%c", c[i]);
		if (c[i] == '_')
			printf("%c", c[++i] - 32);
		if (c[i] >= 'A'&&c[i] <= 'Z')
			printf("_%c", c[i] + 32);
	}
	return 0;
}