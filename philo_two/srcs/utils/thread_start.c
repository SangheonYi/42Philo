/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:34:51 by hmin              #+#    #+#             */
/*   Updated: 2021/02/23 09:17:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		thread_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		if (pthread_create(&(*philo)[i].th,
					NULL, (void *)life_cycle, &(*philo)[i]))
			return (ERR_THREAD_CREATE);
		i++;
	}
	if (!info->dead_phi)
		if (pthread_create(&info->monitor, NULL, (void *)life_check, philo))
			return (ERR_THREAD_CREATE);
	pthread_join(info->monitor, NULL);
	while (i-- >= 0)
		pthread_join((*philo)[i].th, NULL);
	return (OK);
}
