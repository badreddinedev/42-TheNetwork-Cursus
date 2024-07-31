#include <stdio.h>
#include <stdlib.h>
char    *ft_strdup(char *src)
{
    int i = -1;
    int len = 0;
    char *ptr;
    while(src[len++])
    ptr = malloc(sizeof(char) * len + 1);
    if (!ptr)
        return (NULL);
    while (src[++i])
        ptr[i] = src[i];
    ptr[i] = '\0';
    return (ptr);
}
