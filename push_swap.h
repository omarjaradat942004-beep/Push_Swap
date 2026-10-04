/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:03:45 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/04 14:32:33 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H



#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

typedef struct list
{
        int     top;
        int     arr[MAX_SIZE];
}Stack;

#endif
