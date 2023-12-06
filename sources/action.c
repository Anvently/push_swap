/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:36 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 17:18:19 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_action(char *action, t_pile **pile_a, t_pile **pile_b, bool print)
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
	if (print)
		ft_printf("%s", action);
}

void	rotate_piles(t_pile **pile_a, t_pile **pile_b, t_pile *cheapest)
{
	if (cheapest->swap_a)
		exec_rotate("sa\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_a > 0 && cheapest->rotate_b > 0)
		exec_rotate("rr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_a < 0 && cheapest->rotate_b < 0)
		exec_rotate("rrr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_a > 0)
		exec_rotate("ra\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_b > 0)
		exec_rotate("rb\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_a < 0)
		exec_rotate("rra\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_b < 0)
		exec_rotate("rrb\n", pile_a, pile_b, cheapest);
}

void	exec_rotate(char *action, t_pile **pile_a,
		t_pile **pile_b, t_pile *cheapest)
{
	do_action(action, pile_a, pile_b, true);
	if (!ft_strcmp(action, "rr\n"))
	{
		cheapest->rotate_a--;
		cheapest->rotate_b--;
	}
	else if (!ft_strcmp(action, "rrr\n"))
	{
		cheapest->rotate_a++;
		cheapest->rotate_b++;
	}
	else if (!ft_strcmp(action, "ra\n"))
		cheapest->rotate_a--;
	else if (!ft_strcmp(action, "rb\n"))
		cheapest->rotate_b--;
	else if (!ft_strcmp(action, "rra\n"))
		cheapest->rotate_a++;
	else if (!ft_strcmp(action, "rrb\n"))
		cheapest->rotate_b++;
	else if (!ft_strcmp(action, "sa\n"))
		cheapest->swap_a = 0;
}
