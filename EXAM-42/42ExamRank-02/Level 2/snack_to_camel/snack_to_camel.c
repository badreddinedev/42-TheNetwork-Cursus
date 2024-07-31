#include <unistd.h>

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int i = -1;
        while (av[1][++i])
        {
            if (!(av[1][i] >= 'a' && av[1][i] <= 'z'))
            {
                i++;
                av[1][i] = av[1][i] - 32;
                write(1, &av[1][i], 1);
            }
            else
                write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
}