/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:30:05 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/13 14:40:37 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_diese(char *flag, char *ret)
{
	int		i;
	char	flag_letter;

	i = -1;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == '#')
		{
			if (flag_letter == 'x')
				ret = add_begin(ft_strtolower(ret), "0x");
			else if (flag_letter == 'X')
				ret = add_begin(ret, "0X");
			else if (flag_letter == 'o')
				ret = add_begin(ret, "0");
			while (ft_strchr(flag, '#'))
				flag = replacestr(flag, "#", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}

char	*handle_neg(char *flag, char *ret)
{
	int		i;
	int		nb;
	int		j;

	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
		{
			nb = ft_atoi(&flag[i + 1]);
			j = -1;
			while (flag[++j])
			{
				if (ft_isdigit(flag[j]) && flag[j] != 0)
				{
					if (nb == 0)
						nb = ft_atoi(&flag[j]);
					flag = replacestr(flag, ft_itoa(ft_atoi(&flag[j])), "");
					break;
				}
			}
			while (ft_strlen(ret) < (size_t)(nb))
				ret = add_end(ret, " ");	
			if (ft_isdigit(flag[i + 1]) && flag[i + 1] != '0')
				flag = replacestr(flag, ft_itoa(ft_atoi(&flag[i])), "");
			else if (flag[i + 1] == '0')
				flag = replacestr(flag, add_end("-", "0"), "");
			else
				flag = replacestr(flag, "-", "");
			//remove 0
			i = -1;
			while (flag[++i])
			{
				if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
					flag = replacestr(flag, get_0_param(&flag[i]), "");
			}
			//remove num
			return (handle_conversion(flag, ret));
		}
	return (0);
}

char	*handle_zero(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	*temp;

	i = -1;
	temp = 0;
	while (flag[++i])	
		if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
		{
			if ((!ft_strchr(flag, '-')) && !ft_strchr(flag, '.')) //&& !ft_strchr(deleted, '-')))
			{
				nb = ft_atoi(&flag[i + 1]);
				if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
				{
					temp = "0x";
					ret = &ret[2];
				}
				else if (ft_strchr(ret, '-'))
				{
					temp = "-";
					ret = &ret[1];
				}
				else if (ft_strchr(ret, '+'))
				{
					temp = "+";
					ret = &ret[1];
				}
				while (ft_strlen(ret) + ft_strlen(temp) < (size_t)nb)
					ret = add_begin(ret, "0");
				if (temp)
					ret = add_begin(ret, temp);
			}
			flag = replacestr(flag, get_0_param(&flag[i]), "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}

char	*handle_digit(char *flag, char *ret)
{
	int		i;
	int		nb;

	i = -1;
	while (flag[++i])
		if (ft_isdigit(flag[i]) && flag[i] != '0' && flag[i - 1] != '.')
		{
			if (!ft_strchr(flag, '-')) //&& !ft_strchr(deleted, '-'))
			{
				nb = ft_atoi(&flag[i]);
				while (ft_strlen(ret) < (size_t)nb)
					ret = add_begin(ret, " ");
			}
			flag = replacestr(flag, ft_itoa(ft_atoi(&flag[i])), "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}

char	*handle_plus(char *flag, char *ret)
{
	int		i;
	char	flag_letter;

	i = -1;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == '+')
		{
			if (ft_strchr("id", flag_letter) && ft_atoi(ret) >= 0)
				ret = add_begin(ret, "+");
			while (ft_strchr(flag, '+'))
				flag = replacestr(flag, "+", "");
			while (ft_strchr(flag, ' '))
				flag = replacestr(flag, " ", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}

char	*handle_space(char *flag, char *ret)
{
	int		i;
	char	flag_letter;

	i = -1;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == ' ')
		{
			if (ft_strchr("id", flag_letter) && !ft_strchr(flag, '+') && /*!ft_strchr(deleted, '+') &&*/ ft_atoi(ret) >= 0)
				ret = add_begin(ret, " ");
			while (ft_strchr(flag, ' '))
				flag = replacestr(flag, " ", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}
