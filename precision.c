/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/03 15:41:28 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*remove_0(char *flag)
{
	int		i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
			flag = replacestr(flag, "0", "");
		i++;
	}
	return (flag);
}

char	*handle_precision(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	flag_letter;
	char	*temp;

	i = -1;
	temp = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == '.')
		{
			nb = ft_atoi(&flag[i + 1]);
		//	if (flag_letter != 'c')
		//		flag = remove_0(flag);
			if (ft_strchr("diuopOxX", flag_letter) && nb > 0)
			{
				if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
				{
					if (!ft_strncmp(ret, "0x", 2))
						temp = "0x";
					else
						temp = "0X";
					ret = &ret[2];
				}
				else if (ft_strchr(ret, '-'))
				{
					temp = "-";
					ret = &ret[1];
				}	
				//ret = ft_itoa(ft_atoi(ret));
				while (ft_strlen(ret) < (size_t)nb)
					ret = add_begin(ret, "0");
				if (temp)
					ret = add_begin(ret, temp);
			}
			else if (ft_strchr("cCsS", flag_letter))
			{
				if (nb == 0 && ret[0] == '@')
					nb = 1;
				ret = ft_strndup(ret, nb);
			}
			else if (ft_strchr("oO", flag_letter) && nb == 0 && ft_strequ(ret, "0") && ft_strchr(flag, '#'))
				ret = "0";
			else if (ft_strchr("xXudioO", flag_letter) && nb == 0 && ft_strequ(ret, "0"))
				ret = "";
			else if (flag_letter == 'p' && nb == 0 
					&& ft_strequ(ft_strtolower(ret), "0x0"))
				ret = ft_strndup(ret, 2);
			//flag = replacestr(flag, ft_itoa(nb), "");
			flag = replacestr(flag, get_0_param(&flag[i + 1]), "");
			if (ft_strchr("diuopOxX", flag_letter))
				flag = remove_0(flag);
			flag = replacestr(flag, ".", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}
