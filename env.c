#include "minishell.h"

void	ft_env()
{
	t_list	*temp;

	temp = g_data.str;
	while (temp)
	{
		printf("%s%s\n",temp->name, temp->value);
		temp = temp->next;
	}
	g_data.exit_status = 0;
}