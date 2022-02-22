#include <unistd.h>
#include <stdarg.h>

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

int ft_puthex(unsigned int nbr)
{
    int len;
    char *hex;

    len = 0;
    hex = "0123456789abcdef";
    if (nbr > 16)
        len += ft_puthex(nbr / 16);
    len += ft_putchar(hex[nbr % 16]);
    return (len);
}

int    ft_if(va_list ap, const char *s)
{
    int len;

    len = 0;
    if (*s == 's')
        len += ft_putstr(va_arg(ap, char *));
    else if (*s == 'd')
        len += ft_putnbr(va_arg(ap, int));
    else if (*s == 'x')
        len += ft_puthex(va_arg(ap, unsigned int));
    return (len);
}

int ft_printf(const char *fmt, ...)
{
    va_list args;
    int len;

    len = 0;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            len += ft_if(args, fmt);
        }
        else
        {
               len += ft_putchar(*fmt);
        }
        fmt++;
    }
    va_end(args);
    return (len);
}

#include <stdio.h>

int main()
{
    ft_printf("%x",42);
    ft_printf("\nSYSTEM\n");
    printf("%x",42);
}