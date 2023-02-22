#include "minishell.h"

void	handle_signals(int signo)
{
	// if (g_pid)
	// 	return ;
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_data.exit_status = 130;
	}
	else if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
	}
}
