/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:42:43 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 17:18:14 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	check_action(char *action)
{
	if (!ft_strcmp(action, "sa\n")
		|| !ft_strcmp(action, "sb\n")
		|| !ft_strcmp(action, "ss\n")
		|| !ft_strcmp(action, "pa\n")
		|| !ft_strcmp(action, "pb\n")
		|| !ft_strcmp(action, "ra\n")
		|| !ft_strcmp(action, "rb\n")
		|| !ft_strcmp(action, "rr\n")
		|| !ft_strcmp(action, "rra\n")
		|| !ft_strcmp(action, "rrb\n")
		|| !ft_strcmp(action, "rrr\n"))
		return (true);
	ft_putendl_fd("Unknowm action.", 1);
	return (false);
}

void	listen_actions(t_pile **pile_a, t_pile **pile_b)
{
	char	*line;

	line = ft_gnl(0);
	while (line)
	{
		if (check_action(line))
			do_action(line, pile_a, pile_b, false);
		free(line);
		line = ft_gnl(0);
	}
	if (pile_is_sort(*pile_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int narg, char **vargs)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = parse_input(narg, vargs);
	pile_b = NULL;
	if (pile_a)
		listen_actions(&pile_a, &pile_b);
	pile_clear(pile_a);
	pile_clear(pile_b);
	return (0);
}
