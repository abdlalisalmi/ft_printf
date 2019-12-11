/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:59:31 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/11 17:47:17 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void right_print(char *str, int sign, int intlen, t_struct *list)
{
	if (sign == 1)
		list->nprint += write(1, "-", 1);
	while (list->precision > 0)
	{
		list->nprint += write(1, "0", 1);
		list->precision--;
	}
	list->nprint += write(1, str, intlen);
	while (list->width > 0)
	{
		list->nprint += write(1, " ", 1);
		list->width--;
	}
}

static void left_print(char *str, int sign, int intlen, t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1)
		c = '0';
	while (list->width-- > 0)
		list->nprint += write(1, &c, 1);
	if (sign != 0)
		list->nprint += write(1, "-", 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, str, intlen);
}

static void arg_handle(int nb, int sign, t_struct *list)
{
	char *str;
	int intlen;

	str = ft_itoa(nb);
	if (nb == 0)
		intlen = 0;
	else
		intlen = ft_strlen(str);
	if (list->precision >= intlen)
		list->precision -= intlen;
	if (sign != 0)
		list->width -= (list->precision + intlen + 1);
	else
		list->width -= (list->precision + intlen);
	if (list->minus == 0)
		left_print(str, sign, intlen, list);
	if (list->minus == 1)
		right_print(str, sign, intlen, list);
	if (*str)
		free(str);
}

void is_int(t_struct *list, va_list ap)
{
    int nb;
	int sign;

	sign = 0;
    nb = va_arg(ap, int);
	if (nb < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	arg_handle(nb, sign, list);
}
