/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_chngs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:27:30 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:13:09 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	mutex_wrap_chng(t_philo *phi, pthread_mutex_t *type, void f_chng())
{
	pthread_mutex_lock(type);
	f_chng(phi);
	pthread_mutex_unlock(type);
}
