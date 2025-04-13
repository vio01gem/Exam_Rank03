#include <unistd.h>
#include <stdarg.h>

//sear 

void ft_putstr(char *str, int *d)
{
    if (!str)                // If string is NULL
        str = "(null)";      // Replace with "(null)"
    while (*str)            // Loop through each char
    {
        write(1, str++, 1); // Write char, move pointer
        (*d)++;         // Increment d
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
        write(1, "-", 1);   // Print minus
        (*d)++;
        n = -n;             // Make positive
    }
    if (n > 9)              // Multi-digit
        ft_putnbr(n / 10, d); // Recurse for higher digits
    c = (n % 10) + '0';     // Convert last digit to char
    write(1, &c, 1);        // Print it
    (*d)++;             // Increment d
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
    va_list ap;           // Variable ap
    int d = 0;          // Total chars printed
    va_start(ap, format); // Start ap
    while (*format)         // Loop format string
    {
        if (*format == '%' && *(format + 1)) // Specifier check
        {
            format++;       // Skip '%'
            if (*format == 's')
                ft_putstr(va_arg(ap, char *), &d);
            else if (*format == 'd')
                ft_putnbr(va_arg(ap, int), &d);
            else if (*format == 'x')
                ft_puthex(va_arg(ap, unsigned int), &d);
            else            // Unknown specifier
            {
                write(1, format, 1);
                d++;
            }
        }
        else                // Normal char
        {
            write(1, format, 1);
            d++;
        }
        format++;           // Next char
    }
    va_end(ap);           // Clean up
    return (d);         // Return total
}

int main(void)
{
    ft_printf("Hello %s, %d, %x\n", "world", -42, 255);
    return (0);
}
