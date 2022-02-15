#include <unistd.h>
#include <stdlib.h>

int check(char *s, char c, int pos)
{
    int i;

    i = -1;
    while (++i < pos)
        if (s[i] == c)
            return (0);
    return (1);
}

int main(int ac, char **av)
{
    int i;
    int j;

    i = -1;
    if (ac == 3)
    {
        while (av[1][++i])
        {
            j = -1;
            while (av[2][++j])
            {
                if (av[1][i] == av[2][j])
                {
                    if (check(av[1], av[1][i] , i))
                    {
                        write(1,&av[1][i],1);
                        break;
                    }
                }
            }
        }
    }
    write(1,"\n",1);
    return (0);
}