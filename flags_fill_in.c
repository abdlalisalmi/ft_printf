/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_fill_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:12:33 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/08 21:54:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    flags(const char *format, t_struct *list)
{
    if (ft_strchr("-0", format[list->i]))
    {
        if (format[list->i] == '-')
            list->minus = 1;
        else if (format[list->i] == '0')
            list->zero = 1;
        list->i++;
    }
}

static void    width_is_star(const char *format, t_struct *list, va_list ap)
{
    list->width = va_arg(ap, int);
    if (list->width  < 0)
    {
        list->width = -(list->width);
        list->minus = 1;
    }
    while (format[list->i] == '*')
        list->i++;
}

static void    width(const char *format, t_struct *list, va_list ap)
{
    if (format[list->i] == '*')
        width_is_star(format, list, ap);
    if (format[list->i] >= '0' && format[list->i] <= '9')
    {
        list->width = ft_atoi(&format[list->i]);
        while (format[list->i] >= '0' && format[list->i] <= '9')
        {
            list->i++;
            if (format[list->i] == '*')
            {
                if (list->width < 0)
                {
                    list->minus = 1;
                    list->width = -list->width;
                }
                while (format[list->i] == '*')
                    list->i++;
            }            
        }
    }
}

static void    precision(const char *format, t_struct *list, va_list ap)
{
    if (format[list->i] == '.')
    {
        list->precision = 0;
        list->i++;
        if (format[list->i] >= '0' && format[list->i] <= '9')
        {
            list->precision = ft_atoi(&format[list->i]);
            while (format[list->i] >= '0' && format[list->i] <= '9')
                list->i++;
        }
        else if (format[list->i] == '*')
        {
            list->precision = va_arg(ap, int);
            if (list->precision < 0)
                list->precision = list->precision;
            while (format[list->i] == '*')
                list->i++;
        }
    }  
}

void flags_fill_in(const char *format, t_struct *list, va_list ap)
{
    flags(format, list);
    width(format, list, ap);       
    precision(format, list, ap);
}
