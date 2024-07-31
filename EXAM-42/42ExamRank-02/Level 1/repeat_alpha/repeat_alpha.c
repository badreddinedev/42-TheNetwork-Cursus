#include <unistd.h>
int     letter_count(char c)
{
    int	repeat;

	if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else
		repeat = 1;
	return (repeat);
}

int main (int ac, char **av)
{
    int count;
    int i = -1;
    if (ac == 2)
    {
        while (av[1][++i])
        {
            count = letter_count(av[1][i]);
            while(count--)
                write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
}