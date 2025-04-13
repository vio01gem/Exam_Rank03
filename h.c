#include <unistd.h>
#include <stdarg.h>


void ft_putstr(char *str, int *d)
{
    if (!str) 
        str = "(null)";  
    while (*str)
    {
        write(1, str++, 1); 
        (*d)++; 
    }
}

void ft_putnbr(int n, int *d)
{
    char c;                 // Temp char for digit
    if (n == -2147483648)   // Special case for INT_MIN
    {
        ft_putstr("-2147483648", d); // Print directly
        return;
    }
    if (n < 0)              // Handle negatives
    {
        ft_putstr("-", d);   // Print minus
        n = -n;             // Make positive
    }
    if (n > 9)              // Multi-digit
        ft_putnbr(n / 10, d); // Recurse for higher digits
    c = (n % 10) + '0';     // Convert last digit to char
    ft_putstr(&c, d);      // Print it
}

void ft_puthex(unsigned int n, int *d)
{
    char *hex = "0123456789abcdef"; // Hex lookup
    if (n >= 16)                   // Multi-digit hex
        ft_puthex(n / 16, d);  // Recurse
    write(1, &hex[n % 16], 1);     // Print last digit
    (*d)++;                    // Increment d
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int d = 0;
    va_start(ap, format);
    while (*format) 
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(ap, char *), &d);
            else if (*format == 'd')
                ft_putnbr(va_arg(ap, int), &d);
            else if (*format == 'x')
                ft_puthex(va_arg(ap, unsigned int), &d);
            else       
            {
                write(1, format, 1);
                d++;
            }
        }
        else
        {
            write(1, format, 1);
            d++;
        }
        format++; 
    }
    va_end(ap); 
    return (d);
}

int main(void)
{
    ft_printf("Hello %s, %d, %x\n", "world", -42, 255);
    return (0);
}
