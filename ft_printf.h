/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:09:13 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/15 23:43:58 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define CONVERSIONS 	"cspdiuxX%"
# define FLAGS			"-.*0123456789"
# define ALLSYMBOLS 	"cspdiuxX%-.*0123456789"

typedef struct	s_struct
{
	int		nprint;
	int		i;

	int		minus;
	int		zero;
	int		width;
	int		precision;
}				t_struct;

int				ft_printf(char *format, ...);
void			flags_fill_in(const char *format, t_struct *list, va_list ap);
void			is_int(t_struct *list, va_list ap);
void			is_string(t_struct *list, va_list ap);
void			is_char(t_struct *list, va_list ap);
void			is_hexa(char c, t_struct *list, va_list ap);
char			*convert_to_hexa(unsigned long decimal, char c);
void			is_pointer(t_struct *list, va_list ap);
void			is_unsigned(t_struct *list, va_list ap);
void			is_percent(t_struct *list);

size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
int				ft_atoi(const char *str);
int				ft_putchar(char c);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_putnbr(int n);
char			*ft_itoa(long nb);
char			*ft_strrev(char *str);
char			*ft_strdup(const char *str);

#endif
