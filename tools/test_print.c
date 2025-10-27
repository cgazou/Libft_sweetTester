/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgazen <cgazen@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:34:52 by cgazen            #+#    #+#             */
/*   Updated: 2025/10/24 21:16:20 by cgazen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"
#include <unistd.h>
#include <stdlib.h>

void	animate_robot_from_left(void)
{
	int	position;
	int	max_position = 20; // Position finale
	char	spaces[22];
		
	usleep(200000);
	system ("clear");
	position = 0;
	while (position <= max_position)
	{
		printf("\033[H");	
		// Génère les espaces pour la position courante
		memset(spaces, ' ', position);
		spaces[position] = '\0';
		
		printf("\n\n\n");
		printf("%s%s ||     |||  |||||  |||||| ||||||||                 \n", spaces, TXT_WHITE);
		printf("%s ||     |||  || ||  ||        ||                   \n", spaces);
		printf("%s ||     |||  |||||| ||||      ||                                         \n", spaces);
		printf("%s ||     |||  ||  || ||        ||                                         \n", spaces);
		printf("%s |||||| |||  |||||| ||  " TXT_RED "by cgazen" TXT_YELLOW "         \n", spaces);
		printf("%s  \\'''-/                                    \n", spaces);
		printf("%s   \\__/      o                              \n", spaces);
		printf("%s    |         )                             \n", spaces);
		printf("%s    |         |                             \n", spaces);
		printf("%s    |     ____|_____                        \n", spaces);
		printf("%s    o    |----------|                       \n", spaces);
		printf("%s     `\\  | [:I] (@) |                      \n", spaces);
		printf("%s       `\\|----------|                       \n", spaces);
		printf("%s         |()()()()()|\\                      \n", spaces);
		printf("%s         | .------. | \\       /|__          \n", spaces);
		printf("%s         | |  --  | |  o-----[  ---         \n", spaces);
		printf("%s         | '------' |         `\\\"\"`        \n", spaces);
		printf("%s         |----------|                       \n", spaces);
		printf("%s          \\_ _.._ _/                        \n", spaces);
		printf("%s          (_)(  )(_)                        \n", spaces);
		
		printf("%s____________________________________________/|\n\n%s",TXT_WHITE, TXT_RESET);
		fflush(stdout);
		usleep(40000); // Vitesse du déplacement
		position++;

	}
	
	// Pause à la position finale
	usleep(1000000);
}

void	print_welcome(void)
{
	animate_robot_from_left();
	system("clear");
}

void	run_selected_tests(int	*select)
{
	int	fail;
	int	tests;

	system("clear");
	printf("\n%sRunning selected tests...%s\n", TXT_YELLOW, TXT_RESET);
	fail = 0;
	tests = 0;	
	if (select[1])
	{
		printf("Testing isalpha...\n");
		fail = fail + test_isalpha("isalpha");
		tests++;
	}
	if (select[2])
	{
		printf("Testing isdigit...\n");
		fail = fail + test_isdigit("isdigit");
		tests++;
	}
	if (select[3])
	{
		printf("Testing isalnum...\n");
		fail = fail + test_isalnum("isalnum");
		tests++;
	}
	if (select[4])
	{
		printf("Testing isascii...\n");
		fail = fail + test_isascii("isascii");
		tests++;
	}
	if (select[5])
	{
		printf("Testing isprint...\n");
		fail = fail + test_isprint("isprint");
		tests++;
	}
	if (select[20])
	{
		printf("Testing atoi...\n");
		fail = fail + test_atoi("atoi");
		tests++;
	}		
	print_summary(tests - fail, tests);
	

}
void	print_test_menu(void)
{
	int		choice;
	int		selected[50] = {0};
	char	input[100];

	while (1)
	{
		system("clear");
		printf("%s%s", BGD_BLUE, TXT_WHITE); // Fond bleu + texte blanc pour tout le tableau
		
		printf("┌─────────────────────────────────────────────────────────────┐\n");
		printf("│                   %sLIBFT TEST SELECTOR (cgazen)%s              │\n", TXT_YELLOW, TXT_WHITE);
		printf("├─────────────────────────────────────────────────────────────┤\n");
		printf("│%s                     PART 1 - MANDATORY                      %s│\n", BGD_GREEN TXT_WHITE, BGD_BLUE TXT_WHITE);
		printf("├─────────────────────────────────────────────────────────────┤\n");
		
		// Part 1
		printf("│  [%c 1] isalpha      [%c 7] memset      [%c13] tolower         │\n", selected[1] ? 'X' : ' ', selected[7] ? 'X' : ' ', selected[13] ? 'X' : ' ');
		printf("│  [%c 2] isdigit      [%c 8] bzero       [%c14] strchr          │\n", selected[2] ? 'X' : ' ', selected[8] ? 'X' : ' ', selected[14] ? 'X' : ' ');
		printf("│  [%c 3] isalnum      [%c 9] memcpy      [%c15] strrchr         │\n", selected[3] ? 'X' : ' ', selected[9] ? 'X' : ' ', selected[15] ? 'X' : ' ');
		printf("│  [%c 4] isascii      [%c10] memmove     [%c16] strncmp         │\n", selected[4] ? 'X' : ' ', selected[10] ? 'X' : ' ', selected[16] ? 'X' : ' ');
		printf("│  [%c 5] isprint      [%c11] strlcpy     [%c17] memchr          │\n", selected[5] ? 'X' : ' ', selected[11] ? 'X' : ' ', selected[17] ? 'X' : ' ');
		printf("│  [%c 6] strlen       [%c12] strlcat     [%c18] memcmp          │\n", selected[6] ? 'X' : ' ', selected[12] ? 'X' : ' ', selected[18] ? 'X' : ' ');
		printf("├─────────────────────────────────────────────────────────────┤\n");
		printf("│  [%c19] strnstr      [%c21] calloc                            │\n", selected[19] ? 'X' : ' ', selected[21] ? 'X' : ' ');
		printf("│  [%c20] atoi         [%c22] strdup                            │\n", selected[20] ? 'X' : ' ', selected[22] ? 'X' : ' ');
		
		printf("├─────────────────────────────────────────────────────────────┤\n");
		printf("│%s                      PART 2 - ADDITIONAL                    %s│\n", BGD_YELLOW TXT_WHITE, BGD_BLUE TXT_WHITE);
		printf("├─────────────────────────────────────────────────────────────┤\n");
		
		// Part 2
		printf("│  [%c23] substr      [%c27] itoa         [%c31] putstr_fd       │\n", selected[23] ? 'X' : ' ', selected[27] ? 'X' : ' ', selected[31] ? 'X' : ' ');
		printf("│  [%c24] strjoin     [%c28] strmapi      [%c32] putendl_fd      │\n", selected[24] ? 'X' : ' ', selected[28] ? 'X' : ' ', selected[32] ? 'X' : ' ');
		printf("│  [%c25] strtrim     [%c29] striteri     [%c33] putnbr_fd       │\n", selected[25] ? 'X' : ' ', selected[29] ? 'X' : ' ', selected[33] ? 'X' : ' ');
		printf("│  [%c26] split       [%c30] putchar_fd                         │\n", selected[26] ? 'X' : ' ', selected[30] ? 'X' : ' ');
		
		printf("├─────────────────────────────────────────────────────────────┤\n");
		printf("│%s                        BONUS - LISTS                        %s│\n", BGD_MAGENTA TXT_WHITE, BGD_BLUE TXT_WHITE);
		printf("├─────────────────────────────────────────────────────────────┤\n");
		
		// Bonus
		printf("│ [%c35] lstnew       [%c39] lstclear      [%c50] ALL TESTS      │\n", selected[35] ? 'X' : ' ', selected[39] ? 'x' : ' ', selected[50] ? 'x' : ' ');
		printf("│ [%c36] lstadd_front [%c40] lstiter       %21s│\n", selected[36] ? 'X' : ' ', selected[40] ? 'X' : ' ', "");
		printf("│ [%c37] lstsize      [%c41] lstmap        %21s│\n", selected[37] ? 'X' : ' ', selected[41] ? 'X' : ' ', "");
		printf("│ [%c38] lstlast      [%c42] lstadd_back   %21s│\n", selected[38] ? 'X' : ' ', selected[42] ? 'X' : ' ', "");
		
		printf("├─────────────────────────────────────────────────────────────┤\n");
		printf("│ %s[0] Run Selected Tests%s                %s[-1] Exit%s             │\n", TXT_GREEN, TXT_WHITE, TXT_RED, TXT_WHITE);
		printf("└─────────────────────────────────────────────────────────────┘\n%s", BGD_RESET);
		
		printf("%s%s", TXT_RESET, BGD_RESET);
		
		printf("\nEnter test(s) number(s): ");
		//Lecture 
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
		//conversion et validation
		if (sscanf(input, "%d", &choice) != 1)
		{
			printf("%sInvalid input! Press Enter...%s", TXT_RED, TXT_RESET);
			getchar();
			continue;
		}

		if (choice == -1)
			break;
		if (choice == 0)
		{
			run_selected_tests(selected);
			break;
		}
		if (choice == 50)
		{
			for (int i = 1; i <= 42; i++)
				selected[i] = !selected[i];
			selected[choice] = !selected[choice];
		}
		else if (choice >= 1 && choice <= 42)
			selected[choice] = !selected[choice];
		//Erreur
		else
		{
			printf("%sNumber must be between 1-43! (50: ALL) Press Enter...%s", TXT_RED, TXT_RESET);
			getchar();
		}
	}
}
