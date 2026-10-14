/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:04:23 by omajarad          #+#    #+#             */
/*   Updated: 2026/10/14 15:01:34 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Simple algorithm (O(n2 ))
#include <stdio.h>
void	insert_sort(int	*arr, int size)
{
	int	index;
	int	index2;
	int	key;

	index = 1; // because index 0 have no elements before it 
	while (index < size)
	{
		key = arr[index];
		index2 = index - 1;
		while (index2 >= 0 && arr[index2] > key)// you compare element to the ones before it
		{
			arr[index2 + 1] = arr[index2]; //arr[n] -> arr[n+1] you push elements right
			index2--;
		}
		arr[index2 + 1] = key; // to insert the element into the corrent position
		index++;
	}
}

int main()
{
	int	arr[] = {16,1,9,0,-8};
	int	size;
	int	index;

	size = 5;
	insert_sort(arr,size);
	index = 0;
	while (index < size)
	{
		printf("%d ",arr[index]);
		index++;
	}
	
}


