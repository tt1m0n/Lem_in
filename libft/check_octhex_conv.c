/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_octhex_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:16:01 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:50:48 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_percent(void)
{
	char *p;

	if (!(p = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	p[0] = '%';
	p[1] = '\0';
	return (p);
}

static void	read_if_nosize(char *str, char **rez, va_list ap)
{
	if (*rez == NULL && str[ft_strlen(str) - 1] == 'o')
		*rez = ft_prnt_itoaui_octhex((unsigned int)va_arg(ap, void*), 8, 0);
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'x')
		*rez = ft_prnt_itoaui_octhex((unsigned int)va_arg(ap, void*), 16, 0);
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'O')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
									va_arg(ap, void*), 8, 1);
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'X')
		*rez = ft_prnt_itoaui_octhex((unsigned int)va_arg(ap, void*), 16, 1);
	else if (*rez == NULL && str[ft_strlen(str) - 1] == '%')
		*rez = add_percent();
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'p')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
									va_arg(ap, void*), 16, 0);
}

static char	conv_ox(char *str, char **rez, va_list ap)
{
	char c;

	c = '\0';
	check_size_spec(str, rez, ap);
	read_if_nosize(str, rez, ap);
	if (*rez == NULL && (str[ft_strlen(str) - 1] == 'c' ||
		str[ft_strlen(str) - 1] == 'C'))
	{
		check_c_conv(str, rez, ap);
		if (*rez == NULL)
		{
			c = 1;
			return (c);
		}
		c = (*rez)[0];
	}
	check_precision(str, rez);
	check_min_width(str, rez);
	check_flags(str, rez);
	if (str[ft_strlen(str) - 1] == 'p')
		make_sharp_flag(str, rez);
	return (c);
}

static int	print_flag_c(char *rez, char c)
{
	int i;

	i = 0;
	if (c == 1)
		return (-1000000);
	while (rez[i] != '\0')
	{
		if ((rez[i] != ' ' && rez[i] != '0') || c != 0)
		{
			write(1, rez, ft_strlen(rez));
			return (0);
			break ;
		}
		i++;
	}
	if (rez[i] == '\0' || rez[i] == '0')
	{
		write(1, rez, ft_strlen(rez) + 1);
		return (1);
	}
	return (0);
}

int			check_octhex_conv(char *str, va_list ap, int *n)
{
	int		i;
	int		len;
	char	*rez;
	char	c;

	rez = NULL;
	len = 0;
	*n = 0;
	i = ft_strlen(str) - 1;
	if (str[i] == 'o' || str[i] == 'O' || str[i] == 'x' || str[i] == 'p' ||
		str[i] == 'X' || str[i] == '%' || str[i] == 'c' || str[i] == 'C')
		c = conv_ox(str, &rez, ap);
	if (str[i] == 'c' || str[i] == 'C')
		len = print_flag_c(rez, c);
	else
		write(1, rez, ft_strlen(rez));
	if (rez != NULL)
	{
		len = len + ft_strlen(rez);
		ft_strclr(rez, ft_strlen(rez));
		free(rez);
	}
	return (len);
}
