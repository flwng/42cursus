/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:05:32 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:30:24 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_width(const char **s, va_list ap, t_info *info)
{
	if (**s == '*')
	{
		info->width = va_arg(ap, int);
		width_neg_star(info);
		(*s)++;
		return (1);
	}
	if (ft_isdigit(**s))
	{
		info->width = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
		return (1);
	}
	return (0);
}

int		read_prec(const char **s, va_list ap, t_info *info)
{
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			prec_star(info, ap);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			info->prec = ft_atoi(*s);
		else
			info->prec = 0;
		while (ft_isdigit(**s))
			(*s)++;
		return (1);
	}
	return (0);
}

int		read_type(const char s, t_info *info, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += print_char(info, ap);
	else if (s == 's')
		count += print_s(info, ap);
	else if (s == 'p')
		count += print_p(info, ap);
	else if (s == 'd')
		count += print_d(info, ap);
	else if (s == 'i')
		count += print_d(info, ap);
	else if (s == '%')
		count += print_perc(info);
	else if (s == 'x')
		count += print_x(info, ap);
	else if (s == 'X')
		count += print_upx(info, ap);
	else if (s == 'u')
		count += print_u(info, ap);
	else
		return (-1);
	return (count);
}

void	read_str(const char **s, va_list ap, int *res)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	while (**s)
	{
		if (**s == '%')
		{
			(*s)++;
			init_info(info);
			while (read_flags(s, info) || read_width(s, ap, info) ||
					read_prec(s, ap, info))
				;
			*res += read_type(**s, info, ap);
			if (*res == -1)
				break ;
			(*s)++;
		}
		else
		{
			write(1, *s, 1);
			(*s)++;
			(*res)++;
		}
	}
	free(info);
}

int		ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, s);
	read_str(&s, ap, &res);
	va_end(ap);
	return (res);
}
