/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:08:54 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/16 15:41:26 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		bzero_struct(t_struct *list)
{
	list->i = 0;
	list->nprint = 0;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->precision = -1;
}

static void		conversions(const char *format, t_struct *list, va_list ap)
{
	if (format[list->i] == 'd' || format[list->i] == 'i')
		is_int(list, ap);
	else if (format[list->i] == 's')
		is_string(list, ap);
	else if (format[list->i] == 'c')
		is_char(list, ap);
	else if (format[list->i] == 'x' || format[list->i] == 'X')
		is_hexa(format[list->i], list, ap);
	else if (format[list->i] == 'p')
		is_pointer(list, ap);
	else if (format[list->i] == 'u')
		is_unsigned(list, ap);
	else
		is_percent(list);
}

static void		flags_handle(const char *format, t_struct *list, va_list ap)
{
	if (ft_strchr(FLAGS, format[list->i]))
	{
		flags_fill_in(format, list, ap);
	}
	if (ft_strchr(CONVERSIONS, format[list->i]))
	{
		conversions(format, list, ap);
		list->i++;
	}
}

static void		format_handle(const char *format, t_struct *list, va_list ap)
{
	while (format[list->i] != '\0')
	{
		list->minus = 0;
		list->zero = 0;
		list->precision = -1;
		list->width = 0;
		if (format[list->i] != '%')
			list->nprint += write(1, &format[list->i], 1);
		else if (format[list->i] == '%')
		{
			list->i++;
			if (!ft_strchr(ALLSYMBOLS, format[list->i]))
				break ;
			else
			{
				flags_handle(format, list, ap);
				list->i--;
			}
		}
		list->i++;
	}
}

int				ft_printf(char *format, ...)
{
	int			format_len;
	t_struct	*list;
	va_list		ap;

	format_len = ft_strlen(format);
	if (!(list = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bzero_struct(list);
	va_start(ap, format);
	if (!format[0] || (format_len == 1 && format[0] == '%'))
		return (0);
	else
		format_handle(format, list, ap);
	va_end(ap);
	free(list);
	return (list->nprint);
}
