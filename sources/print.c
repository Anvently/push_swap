/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:25 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 16:18:18 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pile_print(t_pile *pile)
{
	while (pile)
	{
		ft_printf("---- %+3d | r_from = %d | r_to = %d ---\n",
			pile->n, pile->rotate_a, pile->rotate_b);
		pile = pile->prev;
	}
}

void	piles_print(t_pile *pile_a, t_pile *pile_b)
{
	ft_printf("--- PILE_A --- || --- PILE_B ---\n");
	while (pile_a || pile_b)
	{
		if (pile_a)
		{
			ft_printf("---- %+4d ---- || ", pile_a->n);
			pile_a = pile_a->prev;
		}
		else
			ft_printf("-------------- || ");
		if (pile_b)
		{
			ft_printf("---- %+4d ----\n", pile_b->n);
			pile_b = pile_b->prev;
		}
		else
			ft_printf("--------------\n");
	}
}
