#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = abs((end - start)) + 1;
	int *res = (int *)malloc(sizeof(int) * len);

	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}
#include <stdio.h>

int main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i = 0;
	int	size;

	min = 0;
	max = -3;
	size = min < max ? max - min : min - max;
	tab = ft_range(min, max);
	while(i <= size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}