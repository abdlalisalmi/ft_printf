/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:59:31 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/16 15:20:25 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		right_print(char *str, int sign, int intlen, t_struct *list)
{
	if (sign != 0)
		list->nprint += write(1, "-", 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, str, intlen);
	while (list->width-- > 0)
		list->nprint += write(1, " ", 1);
}

static void		left_print(char *str, int sign, int intlen, t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1 && list->precision == -1)
		c = '0';
	if (sign != 0 && c == '0')
	{
		list->nprint += write(1, "-", 1);
		sign = 0;
	}
	while (list->width-- > 0)
		list->nprint += write(1, &c, 1);
	if (sign != 0)
		list->nprint += write(1, "-", 1);
	while (list->precision-- > 0)
		list->nprint += write(1, "0", 1);
	list->nprint += write(1, str, intlen);
}

static void		arg_handle(char *str, int sign, t_struct *list)
{
	int intlen;
	int pre;

	pre = 0;
	intlen = ft_strlen(str);
	if (list->precision == 0 && str[0] == '0')
		intlen = 0;
	if (list->precision == -1)
		pre = 1;
	if (list->precision >= intlen)
		list->precision -= intlen;
	else
		list->precision = 0;
	if (sign != 0)
		list->width -= (list->precision + intlen + 1);
	else
		list->width -= (list->precision + intlen);
	if (pre == 1)
		list->precision = -1;
	if (list->minus == 0)
		left_print(str, sign, intlen, list);
	if (list->minus == 1)
		right_print(str, sign, intlen, list);
}

void			is_int(t_struct *list, va_list ap)
{
	int		nb;
	int		sign;
	char	*nb_str;

	sign = 0;
	nb = (int)va_arg(ap, int);
	nb_str = ft_itoa(nb);
	if (list->width == 0 && list->precision == -1)
		list->nprint += write(1, nb_str, ft_strlen(nb_str));
	else
	{
		if (nb == -2147483648)
		{
			nb_str = ft_itoa(2147483648);
			sign = 1;
		}
		else if (nb < 0)
		{
			sign = 1;
			nb = nb * (-1);
			nb_str = ft_itoa(nb);
		}
		arg_handle(nb_str, sign, list);
	}
	free(nb_str);
}
