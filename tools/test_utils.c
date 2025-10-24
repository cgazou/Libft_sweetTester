/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:44:11 by cgazen            #+#    #+#             */
/*   Updated: 2025/10/24 19:11:02 by cgazen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <unistd.h>

void	print_header(const char *test_name)
{
	char	input[100];

	printf("\n" TXT_YELLOW "============================================" TXT_RESET "\n");
	printf(TXT_YELLOW "| %-40s |" TXT_RESET "\n", test_name);
	printf(TXT_YELLOW "============================================" TXT_RESET "\n");
	printf("%sTo continue...Press Enter...%s", TXT_YELLOW, TXT_RESET);
	fgets(input, sizeof(input), stdin);
	usleep(580000);
}

void	print_test_case(const char *description, int official, int ft, const char *input)
{
	printf("  -> %-18s: \"%s\"\n", description, input);
	printf("     Original:    %11d\n", official);
	printf("        Libft:     %11d\n", ft);
}

int	cmp_res_integer(int official, int ft, const char *test_name)
{
	(void)test_name;
	printf("  Result: ");

	if (official == ft)
	{
	printf(TXT_GREEN "[OK]" TXT_RESET "\n");
	return (1);
	}
	printf(TXT_RED "[KO]" TXT_RESET "\n");
	printf("  Note: " TXT_YELLOW "Check for undefined behavior" TXT_RESET "\n");
	return (0);
}

int	cmp_res_bool(int official, int ft, int c, const char *test_name)
{
	(void)test_name;
	
	if ((official && ft) || (!official && !ft))
	{
		printf("testing %s with c=%d\t%sok%s\n",test_name, c, TXT_GREEN, TXT_RESET);
		fflush(stdout);
		usleep(1000);
		return (1);
	}
	printf(TXT_RED "[KO]" TXT_RESET "\n");
	printf("    Expected: %s%sfor c=%d%s - ", TXT_GREEN, official ? "TRUE" : "FALSE", c, TXT_RESET);
	printf("got:      %s%s%s\n", TXT_RED, ft ? "TRUE" : "FALSE", TXT_RESET);
	return (0);
}

int	cmp_res_string(char *official, char *ft, const char *test_name)
{
	(void)test_name;
	printf("  Result: ");

	if ((official == NULL && ft == NULL) || 
	(official && ft && strcmp(official, ft) == 0))
	{			
	printf(TXT_GREEN "[OK]" TXT_RESET "\n");
	return (1);
	}
	printf(TXT_RED "[KO]" TXT_RESET "\n");
	printf("  Note: " TXT_YELLOW "Check for undefined behavior" TXT_RESET "\n");
	return (0);
}

int	cmp_res_pointer(void *official, void *ft, const char *test_name)
{
	(void)test_name;
	printf("  Result: ");
	if (official == ft)
	{
	printf(TXT_GREEN "[OK]" TXT_RESET "\n");
	return (1);
	}
	printf(TXT_RED "[KO]" TXT_RESET "\n");
	printf("  Note: " TXT_YELLOW "Check for undefined behavior" TXT_RESET "\n");
	return (0);
}

void	print_summary(int passed, int total)
{
	printf("\n" TXT_BOLD "=================================================" TXT_RESET "\n");
	if (passed == total)
	printf("  RESULT: " TXT_GREEN "ALL TESTS PASSED (%d/%d)" TXT_RESET "\n", passed, total);
	else
	printf("  RESULT: " TXT_RED "%d/%d TESTS PASSED" TXT_RESET "\n", passed, total);
	printf(TXT_BOLD "=================================================" TXT_RESET "\n");
}

void	print_divider(void)
{
	printf(TXT_WHITE "-------------------------------------------------" TXT_RESET "\n");
}

void	print_success(const char *name, int nb_tests)
{
		printf("\n%s[ PASS ] %s: TESTS [OK] %d/%d TESTS DONE%s", TXT_GREEN, name, nb_tests, nb_tests, TXT_RESET "\n");
}
void	print_failure(const char *name, int fail, int nb_tests)
{
		printf("\n%s[ FAIL ] %s: TESTS [KO] %d/ %d TESTS DONE%s", TXT_RED, name, nb_tests - fail, nb_tests, TXT_RESET "\n");
}
