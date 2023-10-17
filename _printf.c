#include "main.h"
#include <stdio.h>
#include "stdarg.h"
#include "unistd.h"

/**
  *switchchar - char case
  *@args: argument1
  *
  *Return: 1
  */

int switchchar(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
  *switchstr - string case
  *@args: argument1
  *
  *Return: length
  */

int switchstr(va_list args)
{
	const char *str = va_arg(args,  const char *);
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	write(1, str, length);
	return (length);
}

/**
  *_printf - produces output according to a format
  *@format: format string
  *
  *Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*++format)
			{
				case 'c':	{
						count += switchchar(args);	}
					break;
				case 's':	{
						count += switchstr(args);	}
					break;
				case '%':	{
						putchar('%');
						count++;	}
					break;
				default:	{
						putchar('%');
						putchar(*format);
						count += 2;	}
						break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
