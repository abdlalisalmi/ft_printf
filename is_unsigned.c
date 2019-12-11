/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:47:45 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/11 18:03:53 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void right_print(char *str, int intlen, t_struct *list)
{
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

static void left_print(char *str, int intlen, t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1)
		c = '0';
	while (list->width-- > 0)
		list->nprint += write(1, &c, 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, str, intlen);
}

static void arg_handle(unsigned int nb, t_struct *list)
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
    else
        list->precision = 0;
    if (list->width >= (intlen + list->precision))
        list->width -= (intlen + list->precision);
	if (list->minus == 0)
		left_print(str, intlen, list);
	if (list->minus == 1)
		right_print(str, intlen, list);
	if (*str)
		free(str);
}

void is_unsigned(t_struct *list, va_list ap)
{
    unsigned int nb;

    nb = (unsigned int) va_arg(ap, unsigned int);
	arg_handle(nb, list);
}
