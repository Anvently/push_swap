/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:10:36 by npirard           #+#    #+#             */
/*   Updated: 2023/12/05 16:59:54 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_pile
{
	int				n;
	struct s_pile	*prev;
	int				rotate_from;
	int				rotate_to;
	int				cost;
}					t_pile;

/* -------------------------------------------------------------------------- */
/*                                    PILE                                    */
/* -------------------------------------------------------------------------- */

t_pile	*pile_new(int n);
t_pile	*pile_add_top(t_pile *pile, t_pile *node);
t_pile	*pile_add_back(t_pile *pile, t_pile *node);
t_pile	*pile_last(t_pile *pile);
void	*pile_clear(t_pile *pile);
bool	pile_is_sort(t_pile *pile);
int		pile_size(t_pile *pile);

/* -------------------------------------------------------------------------- */
/*                                   PARSING                                  */
/* -------------------------------------------------------------------------- */

t_pile	*parse_input(int narg, char **vargs);
t_pile	*parse_arg(t_pile *pile_a, char *str);

/* -------------------------------------------------------------------------- */
/*                                   ERRORS                                   */
/* -------------------------------------------------------------------------- */

bool	check_narg(int narg);
bool	check_input_str(char *str);
bool	check_double(t_pile *pile, int n);
bool	error_input(int error);

/* -------------------------------------------------------------------------- */
/*                                    PRINT                                   */
/* -------------------------------------------------------------------------- */

void	pile_print(t_pile *pile);
void	piles_print(t_pile *pile_a, t_pile *pile_b);

/* -------------------------------------------------------------------------- */
/*                                   ACTIONS                                  */
/* -------------------------------------------------------------------------- */

void	listen_actions(t_pile **pile_a, t_pile **pile_b);
void	do_action(char *action, t_pile **pile_a, t_pile **pile_b);
void	do_swap(t_pile **pile);
void	do_swap_swap(t_pile **pile_a, t_pile **pile_b);
void	do_push(t_pile **pile_src, t_pile **pile_dest);
void	do_rotate(t_pile **pile);
void	do_rev_rotate(t_pile **pile);
void	do_rotate_rotate(t_pile **pile_a, t_pile **pile_b);
void	do_rev_rotate_rotate(t_pile **pile_a, t_pile **pile_b);

/* -------------------------------------------------------------------------- */
/*                                  SOLUTION                                  */
/* -------------------------------------------------------------------------- */

void	sort_pile(t_pile **pile_a, t_pile **pile_b);
t_pile	*find_cheapest(t_pile **pile_from, t_pile **pile_to);
void	push_to_a(t_pile **pile_a, t_pile **pile_b);
void	push_to_b(t_pile **pile_a, t_pile **pile_b);
void	exec_rotate_to_b(char *action, t_pile **pile_from,
			t_pile **pile_to, t_pile *cheapest);
void	exec_rotate_to_a(char *action, t_pile **pile_a,
			t_pile **pile_b, t_pile *cheapest);
void	calc_costs(t_pile *pile_from, t_pile *pile_to);
int		get_cost(t_pile *pile, int n);
int		get_true_cost(t_pile *pile, int offset);
int		calc_final_cost(int rotate_from, int rotate_to);
void	optimize_cost(t_pile *node, int size_from, int size_to);
int		pile_max_offset(t_pile *pile);
int		pile_closest_offset(t_pile *pile, int n);

#endif
