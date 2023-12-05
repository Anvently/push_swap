/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:22 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 17:10:17 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	ft_printf("%s", action);
}

/* void	algo_sort(t_pile **pile_a, t_pile **pile_b)
{
	char	*action;

	action = "";
	while (*pile_b || !pile_is_sort(*pile_a))
	{
		if ((*pile_a)->prev && (*pile_a)->n > (*pile_a)->prev->n)
			action = "sa\n";
		else if (pile_last(*pile_a)->n < (*pile_a)->n)
			action = "rra\n";
		else if (!*pile_a || pile_is_sort(*pile_a))
			action = "pa\n";
		else if ((*pile_a)->prev && (*pile_a)->n < (*pile_a)->prev->n)
			action = "pb\n";
		do_action(action, pile_a, pile_b);
		ft_putstr_fd(action, 1);
	}
} */

/**
 * Both in the same direction => action = MAX()
 * Different direction =>
 * 		from = -2
 * 		  to = 2
 * 		=> 4
 * 		from = - 2
 * 		  to = -5
 * 		=> 7
 *
*/
t_pile	*find_cheapest(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*cheapest;
	t_pile	*current;

	calc_costs(*pile_from, *pile_to);
	current = *pile_from;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->prev;
	}
	return (cheapest);
}


void	push_to_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;

	cheapest = find_cheapest(pile_a, pile_b);
	while (cheapest->rotate_from > 0 && cheapest->rotate_to > 0)
		exec_rotate_to_b("rr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from < 0 && cheapest->rotate_to < 0)
		exec_rotate_to_b("rrr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from > 0)
		exec_rotate_to_b("ra\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_to > 0)
		exec_rotate_to_b("rb\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from < 0)
		exec_rotate_to_b("rra\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_to < 0)
		exec_rotate_to_b("rrb\n", pile_a, pile_b, cheapest);
	do_action("pb\n", pile_a, pile_b);
}

void	push_to_a(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;

	cheapest = find_cheapest(pile_b, pile_a);
	while (cheapest->rotate_from > 0 && cheapest->rotate_to > 0)
		exec_rotate_to_a("rr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from < 0 && cheapest->rotate_to < 0)
		exec_rotate_to_a("rrr\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from > 0)
		exec_rotate_to_a("rb\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_to > 0)
		exec_rotate_to_a("ra\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_from < 0)
		exec_rotate_to_a("rrb\n", pile_a, pile_b, cheapest);
	while (cheapest->rotate_to < 0)
		exec_rotate_to_a("rra\n", pile_a, pile_b, cheapest);
	do_action("pa\n", pile_a, pile_b);
}

void	exec_rotate_to_b(char *action, t_pile **pile_a,
		t_pile **pile_b, t_pile *cheapest)
{
	do_action(action, pile_a, pile_b);
	if (!ft_strcmp(action, "rr\n"))
	{
		cheapest->rotate_from--;
		cheapest->rotate_to--;
	}
	else if (!ft_strcmp(action, "rrr\n"))
	{
		cheapest->rotate_from++;
		cheapest->rotate_to++;
	}
	else if (!ft_strcmp(action, "ra\n"))
		cheapest->rotate_from--;
	else if (!ft_strcmp(action, "rb\n"))
		cheapest->rotate_to--;
	else if (!ft_strcmp(action, "rra\n"))
		cheapest->rotate_from++;
	else if (!ft_strcmp(action, "rrb\n"))
		cheapest->rotate_to++;
}

void	exec_rotate_to_a(char *action, t_pile **pile_a,
		t_pile **pile_b, t_pile *cheapest)
{
	do_action(action, pile_a, pile_b);
	if (!ft_strcmp(action, "rr\n"))
	{
		cheapest->rotate_from--;
		cheapest->rotate_to--;
	}
	else if (!ft_strcmp(action, "rrr\n"))
	{
		cheapest->rotate_from++;
		cheapest->rotate_to++;
	}
	else if (!ft_strcmp(action, "ra\n"))
		cheapest->rotate_to--;
	else if (!ft_strcmp(action, "rb\n"))
		cheapest->rotate_from--;
	else if (!ft_strcmp(action, "rra\n"))
		cheapest->rotate_to++;
	else if (!ft_strcmp(action, "rrb\n"))
		cheapest->rotate_from++;
}

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_size(*pile_a) > 3)
		push_to_b(pile_a, pile_b);
	while (*pile_b)
		push_to_a(pile_a, pile_b);
	//piles_print(*pile_a, *pile_b);
}
