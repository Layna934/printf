#include "main.h"
#include <stdio.h>
#include "stdarg.h"
#include "unistd.h"

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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1);
						count++;
					}
					break;
				case 's':
					{
						const char *str = va_arg(args, char *);
						int length = 0;
						while (str[length] != '\0')
						{
							length++;
						}
						write(1, str, length);
						count += length;
					}
					break;
				case '%':
					{
						write(1, "%", 1);
						count++;
					}
					break;
				default:
					{
						write(1, "%", 1);
						write(1, format, 1);
						count++;
					}
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}			
