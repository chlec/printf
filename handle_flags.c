/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/06 17:25:41 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_other_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	ret = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (flag_letter == 'p')
		ret = add_begin(ft_strtolower(ft_itoa_base(va_arg(*args, long int), 16)), "0x");
	return (ret);
}

char	*get_0_param(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))	
		i++;
	return (ft_strndup(str, i));
}

char			*handle_conversion(char *flag, va_list *args)
{
	int		i;
	char	flag_letter;
	char	*ret;
	int		nb;
	char	*deleted;
	char	*temp;

	i = -1;
	temp = 0;
	deleted = " ";
	ret = handle_flags(flag, args);
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
			flag = replacestr(flag, "#", "");
			deleted = add_begin(deleted, "#");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == '-')
		{
			nb = ft_atoi(&flag[i + 1]);
			while (ft_strlen(ret) < (size_t)(nb))
				ret = add_end(ret, " ");
			flag = replacestr(flag, ft_itoa(ft_atoi(&flag[i])), "");
			deleted = add_begin(deleted, "-");
		}
	i = -1;
	while (flag[++i])
		if (ft_isdigit(flag[i]) && flag[i] != '0')
		{
			if (!ft_strchr(flag, '-') && !ft_strchr(flag, '-'))
			{
				nb = ft_atoi(&flag[i]);
				while (ft_strlen(ret) < (size_t)nb)
					ret = add_begin(ret, " ");
			}
			flag = replacestr(flag, ft_itoa(ft_atoi(&flag[i])), "");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == '+')
		{
			if (ft_strchr("id", flag_letter) && ft_atoi(ret) >= 0)
				ret = add_begin(ret, "+");
			flag = replacestr(flag, "+", "");
			flag = replacestr(flag, get_0_param(&flag[i]), "");
			flag = replacestr(flag, " ", "");
			deleted = add_begin(deleted, "+");
		}
	i = -1;
	while (flag[++i])
		if (flag[i] == ' ')
		{
			if (ft_strchr("id", flag_letter) && !ft_strchr(flag, '+') && !ft_strchr(deleted, '+') && ft_atoi(ret) >= 0)
				ret = add_begin(ret, " ");	
			flag = replacestr(flag, " ", "");
		}
	i = -1;
	while (flag[++i])	
		if (flag[i] == '0')
		{
			if ((!ft_strchr(flag, '-') && !ft_strchr(deleted, '-')))
			{
				nb = ft_atoi(&flag[i + 1]);
				if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
				{
					temp = "0x";
					ret = &ret[2];
				}
				else
					temp = "";
				while (ft_strlen(ret) + ft_strlen(temp) < (size_t)nb)
					ret = add_begin(ret, "0");
				ret = add_begin(ret, temp);
			}
			flag = replacestr(flag, get_0_param(&flag[i]), "");
			deleted = add_begin(deleted, "0");
		}
	return (ret);
}

char			*handle_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	ret = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (ft_strcmp(flag, "%%") == 0)
		ret = "%";
	else if (flag_letter == 'd' || flag_letter == 'i')
		ret = ft_itoa(va_arg(*args, int));
	else if (flag_letter == 's')
		ret = va_arg(*args, char*);
	else if (flag_letter == 'c')
		ret = ft_ctos(va_arg(*args, int));
	else if (flag_letter == 'x')
		ret = ft_strtolower(ft_itoa_base(va_arg(*args, unsigned int), 16));
	else if (flag_letter == 'X')
		ret = ft_itoa_base(va_arg(*args, unsigned int), 16);
	else if (flag_letter == 'o')
		ret = ft_itoa_base(va_arg(*args, unsigned int), 8);
	else if (flag_letter == 'u')
		ret = ft_itoa(va_arg(*args, unsigned int));
	else
		ret = handle_other_flags(flag, args);
	return (ret);
}
