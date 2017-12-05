/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/05 14:12:13 by clecalie         ###   ########.fr       */
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
		ret = add_0x(ft_strtolower(ft_itoa_base(va_arg(*args, long int), 16)));
	return (ret);
}

char			*handle_conversion(char *flag, va_list *args)
{
	int		i;
	char	flag_letter;
//	char	*temp;

	i = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[i])
	{
		if (flag[i] == '#')
		{
			if (flag_letter == 'x')
			{
				/*
					On ne peut pas modifier le flags directement dans la string.
					L'astuce serait d'ajouter les espaces/modif au debut du ret de retour ci dessous
					On peut le faire ici et on strcat le retour de la fonction de dessous après, a voir...
				*/
			}
		}
		i++;
	}
	return (handle_flags(flag, args));	
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
