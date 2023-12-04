/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:08:14 by npirard           #+#    #+#             */
/*   Updated: 2023/12/04 16:15:39 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/// @brief Take src's top element and put it on top on dest.
/// @param pile_src
/// @param pile_dest
void	do_push(t_pile **pile_src, t_pile **pile_dest)
{
	t_pile	*temp;

	if (!*pile_src)
		return ;
	temp = (*pile_src)->prev;
	(*pile_src)->prev = (*pile_dest);
	*pile_dest = *pile_src;
	*pile_src = temp;
}
