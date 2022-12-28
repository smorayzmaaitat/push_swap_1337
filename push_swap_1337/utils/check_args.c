/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <imaaitat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:57:08 by imaaitat          #+#    #+#             */
/*   Updated: 2022/12/26 16:55:02 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_chekstr(const char *s)
{
	size_t	i;
	size_t	t;
	size_t	o;

	i = 0;
	t = 0;
	while (s[t] == '0')
		t++;
	o = t;
	while (s[o])
	{
		o++;
		i++;
	}
	if (i > 9 && ft_atoi(&s[t + 9]) > 7)
		return (1);
	else
		return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		if (ft_chekstr(args[i]))
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
