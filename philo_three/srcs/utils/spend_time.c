/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spend_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:17:05 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 10:58:39 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		spend_time(int wait)
{
	ssize_t	start;

	start = cur_time();
	while (cur_time() - start < wait)
		usleep(1);
}
