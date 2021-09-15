/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:49:35 by hmin              #+#    #+#             */
/*   Updated: 2021/02/23 09:17:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_putnbr_light(unsigned int n)
{
	char			num;
	unsigned int	i;
	unsigned int	j;

	i = n;
	j = 10;
	while (i /= 10)
		j *= 10;
	while (j /= 10)
	{
		num = (n / j) + '0';
		write(1, &num, 1);
		n %= j;
	}
}
