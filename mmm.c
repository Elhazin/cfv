#include "minishell.h"

int	equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}
void fill_env(char **env)
{
	int i;
	char *before;
	char *after;
	i = 0;
	while (env[i])
	{
		before = ft_substr(env[i], 0, equal(env[i]) + 1);
		after = ft_substr(env[i],  equal(env[i]) - 1, ft_strlen(env[i]));
		ft_lstadd_back(&g_data.str, ft_lstnew(before, after));
		i++;
	}
}

void	ft_env()
{
	t_list	*temp;

	temp = g_data.str;
	while (temp)
	{
		if (ft_strchr(temp->name , '=') != NULL)
			printf("%s",temp->name);
		if (temp->value != NULL)
			printf("%s\n",temp->value);
		temp = temp->next;
	}
	g_data.exit_status = 0;
}

int ft_count(char **str)
{
	int i;;
	 i = 0;
	while (str[i])
		i++;
	return (i);
}

void chnage_old_pwd(char *cmd)
{
	int i;
	t_list *g;
	i = 0;

	g = g_data.str;
	while (g)
	{
		if (strcmp("OLDPWD=", g->name) == 0)
		{
			i = 1;
			free(g->value);
			g->value = cmd;
		}
		if (strcmp("PWD=", g->name) == 0)
		{
			free(g->value);
			g->value = getcwd(NULL, 0);
		}
		g = g->next;
	}
	if (i == 0)
		ft_lstadd_back(&g_data.str, ft_lstnew(ft_strdup("OLDPWD="), cmd));
}

void ft_cd(char **cmd)
{
	int	i;
	char *pwd;

	i = 0;
	pwd = getcwd(NULL, 0);
	if (ft_count(cmd) == 1)
	{
		chdir("/");
		chnage_old_pwd(pwd);
	}
	else
	{
		if (chdir(cmd[1]) == -1)
			printf("minishell: cd: %s: No such file or directory", cmd[1]);
		chnage_old_pwd(pwd);
	}
}

void print_export()
{
	char	**str;
	int		i;

	str =  malloc(sizeof(char *) * ft_lstsize(g_data.str));
}
int is_valid(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i][0]) == 1)
			return (0);
		while (str[i][j])
		{
			if (str[i][j] == '=')
				return (1);
			if (str[i][j] == '+')
			{
				if (str[i][j + 1] != '=')
					return (0);
			}
			if (ft_isalnum(str[i][j]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}
char *the_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == )
	}
}
int before_is_plus(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if (str[i + 1] == '+')
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
int update(char *str)
{
	t_list *s;
	char *value;

	s = g_data.str;
	if (before_is_plus(str) == 0)
	{
		while (s)
		{
			if (strcmp(s->name, the_name(str)) == 0)
			{
				s->value = ft_strjoin(s->value, the_value(str));
				free(str);
				return (0);
			}
			s =s->next;
		}
	}
	return (1);
}
void add_to_exp(char *str)
{
	char *name;
	char *value;
	int i;
	int j;

	if (update(str) == 0)
		return (1);
	name = the_name(str);
	value = the_value(str);
	ft_lstadd_back(&g_data.str, ft_lstnew(name, value));
	free(str);
}
void add_to_export(char **cmd)
{
	int i;

	i = 1;
	if (is_valid(cmd) == 0)
		return (1);
	while (cmd[i])
	{
		add_to_exp(cmd[1]);
		i++;
	}
}
void ft_export(char **cmd)
{
	if (ft_count(cmd) == 1)
	{
		print_export();
		g_data.exit_status = 0;
	}
	else
		add_to_export(cmd);
}
int main(int ac , char *av[], char *env[])
{
	fill_env(env);
	ft_cd(&av[1]);
	printf("\n\n\n\n");
	//system("leaks a.out");
}
