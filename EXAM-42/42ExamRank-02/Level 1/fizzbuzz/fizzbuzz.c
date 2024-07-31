#include <unistd.h>

void    ft_number(int i)
{
    char num[10] = "0123456789";
    if (i > 9)
        ft_number(i / 10);
    write(1, &num[i % 10], 1);
}

int main ()
{
    int i = 1;
    while (i <= 100)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz", 9);
        if (i % 3 == 0)
            write(1, "fizz", 5);
        else if (i % 5 == 0)
            write(1, "buzz", 5);
        else
            ft_number(i);
        write(1, "\n", 1);
        i++;
    }
}