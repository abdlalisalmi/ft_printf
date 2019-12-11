/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:15:49 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/10 20:24:54 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void right_print(char *hexa_str, int strlen, t_struct *list)
{
	while (list->precision > 0)
	{
		list->nprint += write(1, "0", 1);
		list->precision--;
	}
	list->nprint += write(1, hexa_str, strlen);
	while (list->width > 0)
	{
		list->nprint += write(1, " ", 1);
		list->width--;
	}
}

static void left_print(char *hexa_str, int strlen, t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1)
		c = '0';
	while (list->width-- > 0)
		list->nprint += write(1, &c, 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, hexa_str, strlen);
}

static void arg_handle(char *hexa_str, t_struct *list)
{
	int strlen;

	if (hexa_str[0] == '0')
		strlen = 0;
	else
		strlen = ft_strlen(hexa_str);
	if (list->precision > strlen)
		list->precision -= strlen;
	else
		list->precision = 0;
    if (list->width > 0)
        list->width -= list->precision + strlen;
	if (list->minus == 0)
		left_print(hexa_str, strlen, list);
	if (list->minus == 1)
		right_print(hexa_str, strlen, list);
	if (*hexa_str)
		free(hexa_str);
}

void    is_hexa(char c, t_struct *list, va_list ap)
{
    long decimal;
    char *hexa_str;

	hexa_str = NULL;
    decimal = va_arg(ap, long);
    if (c == 'x')
        hexa_str = convert_to_hexa(decimal, c);
    else if (c == 'X')
        hexa_str = convert_to_hexa(decimal, c);
    arg_handle(hexa_str, list);
}
