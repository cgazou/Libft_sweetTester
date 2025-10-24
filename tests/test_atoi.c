/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:14:01 by cgazen            #+#    #+#             */
/*   Updated: 2025/10/24 21:23:57 by cgazen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

static void	test_atoi_interactive(void)
{
	char	input[100];
	int		official;
	int		ft_result;
	char	response[10];

	printf("\n" TXT_YELLOW ">> Interactive mode" TXT_RESET "\n");
	printf("%sTest with custom inputs? (y/n): %s", TXT_YELLOW, TXT_RESET);
	
	if (fgets(response, sizeof(response), stdin) == NULL)
		return;
	
	if (response[0] != 'y' && response[0] != 'Y')
		return;
	
	printf("%sEnter strings to test (or 'quit' to exit):%s\n", TXT_YELLOW, TXT_RESET);
	
	while (1)
	{
		printf("\n%sInput: %s", TXT_YELLOW, TXT_RESET);
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
		
		input[strcspn(input, "\n")] = '\0';
		
		if (strcmp(input, "quit") == 0)
			break;
		if (strlen(input) == 0)
			continue;
		
		official = atoi(input);
		ft_result = ft_atoi(input);
		
		printf("  Original atoi: %s%d%s\n", TXT_GREEN, official, TXT_RESET);
		printf("  FT_atoi:       %s%d%s\n", TXT_BLUE, ft_result, TXT_RESET);
		
		if (official == ft_result)
			printf("  %s[x] MATCH%s\n", TXT_GREEN, TXT_RESET);
		else
			printf("  %s[-] DIFFERENCE%s\n", TXT_RED, TXT_RESET);
	}
}

static int	test_atoi_basic(void)
{
	int	fail = 0;
	int	total = 0;

	printf("\n" TXT_YELLOW ">> Basic tests" TXT_RESET "\n");
	
	fail += !cmp_res_integer(atoi("0"), ft_atoi("0"), "0");
	total++;
	fail += !cmp_res_integer(atoi("42"), ft_atoi("42"), "42");
	total++;
	fail += !cmp_res_integer(atoi("-42"), ft_atoi("-42"), "-42");
	total++;
	fail += !cmp_res_integer(atoi("+123"), ft_atoi("+123"), "+123");
	total++;
	fail += !cmp_res_integer(atoi("  42"), ft_atoi("  42"), "spaces before");
	total++;
	
	printf("  " TXT_YELLOW "Basic: %d/%d passed" TXT_RESET "\n", total - fail, total);
	return (fail);
}

static int	test_atoi_boundaries(void)
{
	int	fail = 0;
	int	total = 0;

	printf("\n" TXT_YELLOW ">> Boundary tests" TXT_RESET "\n");
	
	fail += !cmp_res_integer(atoi("2147483647"), ft_atoi("2147483647"), "INT_MAX");
	total++;
	fail += !cmp_res_integer(atoi("-2147483648"), ft_atoi("-2147483648"), "INT_MIN");
	total++;
	fail += !cmp_res_integer(atoi("9999999999"), ft_atoi("9999999999"), "overflow+");
	total++;
	fail += !cmp_res_integer(atoi("-9999999999"), ft_atoi("-9999999999"), "overflow-");
	total++;
	
	printf("  " TXT_YELLOW "Boundaries: %d/%d passed" TXT_RESET "\n", total - fail, total);
	return (fail);
}

static int	test_atoi_edge_cases(void)
{
	int	fail = 0;
	int	total = 0;

	printf("\n" TXT_YELLOW ">> Edge cases" TXT_RESET "\n");
	
	fail += !cmp_res_integer(atoi("\t\n\v\f\r 42"), ft_atoi("\t\n\v\f\r 42"), "whitespaces");
	total++;
	fail += !cmp_res_integer(atoi("42abc"), ft_atoi("42abc"), "letters after");
	total++;
	fail += !cmp_res_integer(atoi(""), ft_atoi(""), "empty string");
	total++;
	fail += !cmp_res_integer(atoi("--42"), ft_atoi("--42"), "double minus");
	total++;
	fail += !cmp_res_integer(atoi("++42"), ft_atoi("++42"), "double plus");
	total++;
	fail += !cmp_res_integer(atoi("-+42"), ft_atoi("-+42"), "minus plus");
	total++;
	
	printf("  " TXT_YELLOW "Edge cases: %d/%d passed" TXT_RESET "\n", total - fail, total);
	return (fail);
}

int	test_atoi(const char *name)
{
	int	fail = 0;
	int	total = 0;

	print_header(name);
	
	fail += test_atoi_basic();
	total++;
	fail += test_atoi_boundaries();
	total++;
	fail += test_atoi_edge_cases();
	total++;
	
	if (!fail)
		print_success(name, total);
	else
		print_failure(name, fail, total);
	test_atoi_interactive();
	print_divider();
	return (fail);
}
