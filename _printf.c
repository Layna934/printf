#include "main.h"
#include <stdio.h>
#include "stdarg.h"
#include "unistd.h"
#include <stdlib.h>
#include <string.h>

/**
  *switchint - prints integers
  *@args: unknown arguments
  *
  *Return: 1
  */

int switchint(va_list args)
{
	int d = va_arg(args, int);
	int len = 0;
	int intcount = 0, l;
	int buffer[BUFF_SIZE];

	if (d < 0)
	{
		write(1, "-", 1);
		d = -d;
		len++;
	}
	else if (d == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		while (d > 0)
		{
			buffer[len++] = '0' + (d % 10);
			d /= 10;
		}
	}
	for (l = len -1; l >= 0; l--)
	{
		write(1, &buffer[l], 1);
		intcount++;
	}
	return (intcount);
}

/**
* general - prints %
* Return: Nothing
*/

int general(void)
{
	write(1, "(null)\n", 6);
	return (strlen("(null"));
}

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
	int i, length = 0;
	char *str_copy = NULL;

	if (str == NULL)
		str = "(null)";
	while (str[length] != '\0')
	{
		length++;
	}
	str_copy = (char *)malloc(length + 1);
	if (str_copy == NULL)
	{
		return (-1);
	}
	for (i = 0; i < length; i++)
	{
		str_copy[i] = str[i];
	}
	str_copy[length] = '\0';
	write(1, str_copy, length);
	free(str_copy);
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
			if (*format == '\0')
			{	count += general();
			
			}
			else
			{
			switch (*format)
			{
				case 'c':	{
						count += switchchar(args);	}
					break;
				case 's':	{
						count += switchstr(args);	}
					break;
				case '%':	{
						write(1, "%", 1);
						count++;	}
					break;
				case 'd':	{
						count += switchint(args);	}
					break;
				case 'i':	{
						count += switchint(args);	}
					break;	
				default:	{
						write(1, "%", 1);
						write(1, format, 1);
						count += 2;	}
					break;
			}
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
