/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_absent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:09:53 by sayi              #+#    #+#             */
/*   Updated: 2021/02/27 12:52:17 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	is_absent(t_philo *phi)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	sem_wait(phi->info->last_eat);
	while (i < (*phi).info->rules[SUM_PH])
	{
		if (phi[i].t_start < 0)
		{
			ret = 1;
			break ;
		}
		i++;
	}
	sem_post(phi->info->last_eat);
	return (ret);
}
