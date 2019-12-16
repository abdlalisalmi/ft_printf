/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:28:44 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/15 22:47:04 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_print(t_struct *list)
{
	list->nprint += write(1, "%", 1);
	while (list->width > 0)
	{
		list->nprint += write(1, " ", 1);
		list->width--;
	}
}

void	left_print(t_struct *list)
{
	char c;

	c = ' ';
	if (list->zero == 1)
		c = '0';
	while (list->width > 0)
	{
		list->nprint += write(1, &c, 1);
		list->width--;
	}
	list->nprint += write(1, "%", 1);
}

void	is_percent(t_struct *list)
{
	if (list->width > 0)
		list->width--;
	if (list->minus == 0)
		left_print(list);
	else if (list->minus == 1)
		right_print(list);
}
