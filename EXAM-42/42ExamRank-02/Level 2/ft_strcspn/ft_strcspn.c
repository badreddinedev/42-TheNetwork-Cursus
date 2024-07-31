#include <stdio.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = -1;
    int j;
    while (s[++i])
    {
        j = -1;
        while (reject[++j])
            if (reject[j] == s[i])
                return i;
    }
    return i;
}
