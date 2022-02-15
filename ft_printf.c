#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int len;

    len = 0;
    if (!s)
        len += write(1, "(null)", 6);
    while (*s != '\0')
    {
        len += write(1, s, 1);
        s++;
    }
    return (len);
}

int ft_putnbr(int nbr)
{
    long n;
    int len;

    len = 0;
    n = nbr;
    if (n < 0)
    {
        len += ft_putchar('-');
        n *= -1;
    } 
    if (n > 9)
        len += ft_putnbr(n / 10);
    len += ft_putchar(n % 10 + 48);
    return (len);
}

#include <stdio.h>

int main()
{
    printf("\nlen == %d\n", ft_putstr("testsd"));
    printf("\nlen == %d", ft_putnbr(415));
}