/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:47:45 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/15 21:45:53 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		right_print(char *str, int intlen, t_struct *list)
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

static void		left_print(char *str, int intlen, t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1 && list->precision == -1)
		c = '0';
	while (list->width-- > 0)
		list->nprint += write(1, &c, 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, str, intlen);
}

static void		arg_handle(char *str, t_struct *list)
{
	int intlen;
	int pre;

	pre = 0;
	if (list->precision == 0 && str[0] == '0')
		intlen = 0;
	else
		intlen = ft_strlen(str);
	if (list->precision == -1)
		pre = 1;
	if (list->precision >= intlen)
		list->precision -= intlen;
	else
		list->precision = 0;
	if (list->width >= (intlen + list->precision))
		list->width -= (intlen + list->precision);
	else
		list->width = 0;
	if (pre == 1)
		list->precision = -1;
	if (list->minus == 0)
		left_print(str, intlen, list);
	if (list->minus == 1)
		right_print(str, intlen, list);
}

void			is_unsigned(t_struct *list, va_list ap)
{
	unsigned int	nb;
	char			*str;

	nb = (unsigned int)va_arg(ap, unsigned int);
	str = ft_itoa(nb);
	if (list->precision == -1 && list->width == 0)
		list->nprint += write(1, str, ft_strlen(str));
	else
		arg_handle(str, list);
	free(str);
}
