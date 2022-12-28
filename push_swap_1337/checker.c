/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <imaaitat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:57:08 by imaaitat          #+#    #+#             */
/*   Updated: 2022/12/26 14:50:40 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
	{
		reverserotate(stack_a);
		return (0);
	}
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
	{
		reverserotate(stack_b);
		return (0);
	}
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
	{
		reverserotate(stack_a);
		reverserotate(stack_b);
		return (0);
	}
	if (line[0] == 'r' && line[1] == 'r'
		&& line[2] != 'r' && line[2] != 'a' && line[2] != 'b')
	{
		rotate(stack_a);
		rotate(stack_b);
		return (0);
	}
	return (1);
}

int	s_s(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 's' && line[1] == 'a')
	{
		swap(stack_a);
		return (0);
	}
	if (line[0] == 's' && line[1] == 'b')
	{
		swap(stack_b);
		return (0);
	}
	if (line[0] == 's' && line[1] == 's')
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	return (1);
}

int	p_p(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 'p' && line[1] == 'a')
	{
		push(stack_a, stack_b);
		return (0);
	}
	if (line[0] == 'p' && line[1] == 'b')
	{
		push(stack_b, stack_a);
		return (0);
	}
	if (line[0] == 'r' && line[1] == 'a')
	{
		rotate(stack_a);
		return (0);
	}
	if (line[0] == 'r' && line[1] == 'b')
	{
		rotate(stack_b);
		return (0);
	}
	return (1);
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a) && ft_lstsize(*stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	initstack(stack_a, argc, argv);
	line = get_next_line(0);
	while (line)
	{
		if (do_commands(line, stack_a, stack_b) && s_s(line, stack_a, stack_b)
			&& p_p(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (0);
		}
		line = get_next_line(0);
	}
	return (free(line), print_checker_res(stack_a, stack_b),
		free_stack(stack_a), free_stack(stack_b), 0);
}
