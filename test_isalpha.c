/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:05:21 by cgazen            #+#    #+#             */
/*   Updated: 2025/10/24 18:46:44 by cgazen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ctype.h>

int	test_isalpha(const char *name)
{	
	int c;
	int fail;
	int	nb_tests;
	int	cmp;

	print_header(name);
	fail = 0;
	c = -1;
	nb_tests = 0;
	while(c <= 255)
	{
		cmp = cmp_res_bool(isalpha(c), ft_isalpha(c), c, name);
		if (!cmp)
			fail++;
		c++;
		nb_tests++;
	}
	if (!fail)
		print_success(name, nb_tests);
	else 
		print_failure(name, fail, nb_tests);
	print_divider();
	return (fail);
	
}
