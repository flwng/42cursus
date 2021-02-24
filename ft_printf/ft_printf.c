void	init_info(t_struct *info)
{
	info->width = 0;
	info->prec = 0;
	info->zero = 0;
	info->minus = 0;
}

void	read_info(const char **s, va_list ap, t_info info)
{
	if (*(*s)++ == '-')
		info->minus = 1;
	if (*(*s)++ == '0')
		info->zero = 1;
	if (*(*s)++ == '*')
		info->width = va_arg(ap, int);
	if (ft_isdigit(**s))
		info->width = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			info->prec = va_arg(ap, int);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			info->prec = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

void	read_str(const char *s, size_t *r, va_list ap)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			init_info(info);
			read_info(&s, ap, info);
		}
	}
	else
	{
		write(1, *s, 1);
		s++;
		r++;
	}

int	ft_printf(const char *s, ...)
{
	size_t	res;
	va_list	ap;

`	res = 0;
	va_start(ap, s);
	read_str(s, &res, ap);
