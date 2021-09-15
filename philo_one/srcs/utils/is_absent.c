/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_absent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:09:53 by sayi              #+#    #+#             */
/*   Updated: 2021/02/27 12:52:06 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	is_absent(t_philo *phi)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	pthread_mutex_lock(&phi->info->last_eat);
	while (i < (*phi).info->rules[SUM_PH])
	{
		if (phi[i].t_start < 0)
		{
			ret = 1;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&phi->info->last_eat);
	return (ret);
}
