/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:38:32 by cgazen            #+#    #+#             */
/*   Updated: 2025/10/24 19:19:34 by cgazen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* COULEURS DE TXT */
# define TXT_RED "\x1b[91m"
# define TXT_GREEN "\x1b[92m"
# define TXT_YELLOW "\x1b[93m"
# define TXT_BLUE "\x1b[94m"
# define TXT_RESET "\x1b[0m"
# define TXT_BOLD "\x1b[1m"
# define TXT_MAGENTA "\x1b[95m"
# define TXT_BLACK   "\x1b[30m"
# define TXT_WHITE   "\x1b[97m"  // Version bright pour meilleure visibilité

/* COULEURS DE FOND */
#define BGD_BLACK   "\x1b[40m"
#define BGD_RED     "\x1b[41m"
#define BGD_GREEN   "\x1b[42m"
#define BGD_YELLOW  "\x1b[43m"
#define BGD_BLUE    "\x1b[44m"
#define BGD_MAGENTA "\x1b[45m"
#define BGD_CYAN    "\x1b[46m"
#define BGD_WHITE   "\x1b[47m"
#define BGD_RESET   "\x1b[49m"

// Affichage
void	print_welcome(void);
void	print_header(const char *test_name);
void	print_test_menu(void);
void	print_test_case(const char *description, int official, int ft, const char *input);
void	print_summary(int passed, int total);

// Comparaisons
int		cmp_res_integer(int official, int ft, const char *test_name);
int		cmp_res_string(char *official, char *ft, const char *test_name);
int		cmp_res_pointer(void *official, void *ft, const char *test_name);
int		cmp_res_bool(int official, int ft, int c, const char *test_name);

// Utilitaires
void	print_divider(void);
void	print_success(const char *name, int nb_tests);
void	print_failure(const char *name, int fail, int nb_tests);

// Tests
int	test_isalpha(const char *name);
int	test_isdigit(const char *name);
int	test_isalnum(const char *name);
int	test_isascii(const char *name);

#endif
