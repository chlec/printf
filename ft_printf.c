/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/24 14:57:03 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	exec_flag(char **str, va_list *args, int *i)
{
	char	*flag;
	char	*t;

	t = *str;
	flag = get_flag(&t[*i]);
	t = apply_flag(flag, *str, i, args);
	ft_strdel(str);
	*str = t;
	if (*str && ft_strequ(*str, "-1") &&
			ft_strchr("CS", flag[ft_strlen(flag) - 1]))
	{
		ft_strdel(&flag);
		return (-1);
	}
	ft_strdel(&flag);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	char			*str;
	int				len;

	str = ft_strdup((char*)format);
	if (!format)
		return (0);
	i = -1;
	va_start(args, format);
	while (str && str[++i])
		if (str[i] == '%')
		{
			if (exec_flag(&str, &args, &i) == -1)
				return (-1);
		}
		else
			ft_putchar(str[i]);
	va_end(args);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
