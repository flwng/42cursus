/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:46:21 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:46:23 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	s_info
{
	int			width;
	int			prec;
	int			zero;
	int			minus;
	int			negnum;
}				t_info;

int				ft_printf(const char *s, ...);
int				print_char(t_info *info, va_list ap);
int				print_s(t_info *info, va_list ap);
int				print_p(t_info *info, va_list ap);
int				print_d(t_info *info, va_list ap);
int				print_x(t_info *info, va_list ap);
int				print_upx(t_info *info, va_list ap);
int				print_u(t_info *info, va_list ap);
int				print_perc(t_info *info);
void			zero_with_prec(t_info *info, int *count);
void			zero_noprec(t_info *info, int *count);
int				neg_int(int tmp, char **tmp2, int *len, t_info *info);
void			num_nominus(t_info *info, int *count, int len, char **tmp2);
void			num_minus(t_info *info, int *count, int len, char *tmp2);
char			*ft_utoa(size_t n, char *base);
void			putstr(char *tmp2, int *count);
void			ft_negnum(t_info *info, int *count, int *len, char **tmp2);
int				len(size_t nb, char *base);
void			init_info(t_info *info);
void			width_neg_star(t_info *info);
void			prec_star(t_info *info, va_list ap);
int				ft_skip(char c, char *flags);
int				read_flags(const char **s, t_info *info);
#endif
