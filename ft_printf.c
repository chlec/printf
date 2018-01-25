/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/25 12:32:51 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	update_big_sc(char **flag, char **str, char *got_flag)
{
	char	*temp;
	char	*t;

	temp = *flag;
	temp[ft_strlen(temp) - 1] = ft_toupper(temp[ft_strlen(temp) - 1]);
	temp = replace_chars(temp, ft_strdup("l"), ft_strdup(""));
	t = replacestr(*str, got_flag, ft_strdup(temp));
	ft_strdel(str);
	*str = t;
}

static int	exec_flag(char **str, va_list *args, int *i)
{
	char	*flag;
	char	*t;
	char	*length_f;

	t = *str;
	flag = get_flag(&t[*i]);
	length_f = get_length_flag(flag);
	if (ft_strchr("cs", flag[ft_strlen(flag) - 1]) && ft_strchr(length_f, 'l'))
		update_big_sc(&flag, str, get_flag(&t[*i]));
	ft_strdel(&length_f);
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
