#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str != '\0')
    {
        i++;
        str++;
    }
    return (i);
}

char    *ft_strdup(char *str)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    while (str[i])
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char    *get_next_line(int fd)
{
    int     n;
    char    buff[1];
    char    line[1000000];
    int     i;

    line[0] = 0;
    i = 0;
    if ( fd < 0)
        return (NULL);
    while ((n = read(fd,buff,1)) && (n > 0))
    {
        line[i++] = buff[0];
        line[i] = '\0';
        if (buff[0] == '\n')
            return (ft_strdup(line));
    }
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}

int main()
{
    char *str;
    int i = 0;
    int fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("line %d == %s", i,str);
    // printf("line 2 == %s", get_next_line(fd));

        
    
}