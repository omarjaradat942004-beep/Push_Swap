/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-sale <yal-sale@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:03:45 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/23 16:47:50 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
/*---------------Node's Structure--------------*/
typedef struct s_snode
{
	int				value;
	int				index;
	struct s_snode	*next;
	struct s_snode	*prev;
}t_snode;

/*---------------operations Structure--------------*/
typedef struct s_op
{
        int counters[11];
}t_op;
/*---------------counter/bench Structure--------------*/
typedef struct s_count
{
        int	counter;
	int	bench_count;
	float	disorder;
	char	**arg;
}t_count;
/*---------------------------------------------*/
/*---------------Parser's Tools----------------*/
int		ft_atoi(const char *nptr, int *error);
int		ft_isdigit(int c);
int		ft_printf_str(char *str);
int		ft_printf_decimal(int num);
int		parser(int argc, char **argv, t_snode **stack_a, int *flag_num);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
/*---------------------------------------------*/
/*-------------------Util----------------------*/
t_snode	*new_node(int value);
int		is_empty(t_snode **stack);
void	push_node(t_snode **stack, t_snode *node);
t_snode	*pop_node(t_snode **stack);
int		peak(t_snode **stack);
/*---------------------------------------------*/
/*-------------------Swap----------------------*/
void	do_sa(t_snode **st_a);
void	do_sb(t_snode **st_b);
void	do_ss(t_snode **st_a, t_snode **st_b);
/*---------------------------------------------*/
/*-------------------Push----------------------*/
void	do_pa(t_snode **st_a, t_snode **st_b);
void	do_pb(t_snode **st_b, t_snode **st_a);
/*---------------------------------------------*/
/*------------------Rotate---------------------*/
void	do_ra(t_snode **st_a);
void	do_rb(t_snode **st_b);
void	do_rr(t_snode **st_a, t_snode **st_b);
/*---------------------------------------------*/
/*--------------Reverse Rotate-----------------*/
void	do_rra(t_snode **st_a);
void	do_rrb(t_snode **st_b);
void	do_rrr(t_snode **st_a, t_snode **st_b);
/*---------------------------------------------*/
float	compute_disorder(t_snode *stack_a, int size);
void	ft_printf_float(double num);
void	init(t_op **operations);
void	benchmark(char **argv, t_count *counters, t_op *operation);
void	adapter(t_snode **stack_a, t_snode **stack_b, t_count *counters, t_op *operation);
void	selection_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation);
void	chunk_based_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation);
void	radix_sort(t_snode **stack_a, t_snode **stack_b, t_op *operation);
void	print_op(t_op *operation);
char	**argvs(char **argv);

#endif
