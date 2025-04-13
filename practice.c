# include <unistd.h>
# include <stdarg.h>

void put_str(char *str, int *d)
{
    if (!str)
    str = "(null)";
    while (*str)
        write (1, str++, 1);
    (*d)++;
}

void put_nbr(int num, int *d)
{
    char c;

    if (num == -2147483648)
        put_str("-2147483648", d);
        return;
    if (num < 0)
    {
        put_str("-", d);
        num = -num;
    }
    if (num > 9)
        put_nbr(num / 10, d);
    c = (num % 10) + '0';
    put_str(&c, d);
}

void put_hex(unsigned int hex, int *d)
{
    char *c = "0123456789abcdef";
    if (hex >= 16)
        put_hex(hex / 16, d);
    write(1, &c[hex % 16], 1);
    (*d)++;
}

int ft_printf(const char * fmt, ... )
{
    va_list ap;
    int d = 0;
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt == '%' && (fmt + 1))
        {
            fmt++;
            if (*fmt == 's')
                put_str(va_arg(ap, char *), &d);
            else if (*fmt ==  'd')
                put_nbr(va_arg(ap, int), &d);
            else if (*fmt ==  'x')
                put_hex(va_arg(ap, unsigned int), &d);
        }
        else 
        {
            write(1, fmt, 1);
            d++;
        }
        fmt++;
    }
    va_end(ap);
    return (d);
}

int main ()
{
    ft_printf("hello, %s, %d, %x", "world", -42, 255);
}