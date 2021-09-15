/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:49:35 by hmin              #+#    #+#             */
/*   Updated: 2021/02/25 13:45:01 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
