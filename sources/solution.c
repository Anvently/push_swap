/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 15:48:08 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	pile_is_sort(t_pile *pile)
{
	while (pile)
	{
		if (pile->prev && pile->prev-> n < pile->n)
			return (false);
		pile = pile->prev;
	}
	return (true);
}

void	do_action(char *action, t_pile **pile_a, t_pile **pile_b)
{
	if (!ft_strcmp(action, "sa\n"))
		do_swap(pile_a);
	else if (!ft_strcmp(action, "sb\n"))
		do_swap(pile_b);
	else if (!ft_strcmp(action, "ss\n"))
		do_swap_swap(pile_a, pile_b);
	else if (!ft_strcmp(action, "pa\n"))
		do_push(pile_b, pile_a);
	else if (!ft_strcmp(action, "pb\n"))
		do_push(pile_a, pile_b);
	else if (!ft_strcmp(action, "ra\n"))
		do_rotate(pile_a);
	else if (!ft_strcmp(action, "rb\n"))
		do_rotate(pile_b);
	else if (!ft_strcmp(action, "rr\n"))
		do_rotate_rotate(pile_a, pile_b);
	else if (!ft_strcmp(action, "rra\n"))
		do_rev_rotate(pile_a);
	else if (!ft_strcmp(action, "rrb\n"))
		do_rev_rotate(pile_b);
	else if (!ft_strcmp(action, "rrr\n"))
		do_rev_rotate_rotate(pile_a, pile_b);
	else
		ft_putendl_fd("Unknowm action.", 1);
}

void	algo_sort(t_pile **pile_a, t_pile **pile_b)
{
	char	*action;

	action = "";
	while (*pile_b || !pile_is_sort(*pile_a))
	{
		if (pile_last(*pile_a)->n < (*pile_a)->n)
			action = "rra\n";
		else if ((*pile_a)->prev && (*pile_a)->n > (*pile_a)->prev->n)
			action = "sa\n";
		else if (!*pile_a || pile_is_sort(*pile_a))
			action = "pa\n";
		else if ((*pile_a)->prev && (*pile_a)->n < (*pile_a)->prev->n)
			action = "pb\n";
		do_action(action, pile_a, pile_b);
		ft_putstr_fd(action, 1);
	}
}
