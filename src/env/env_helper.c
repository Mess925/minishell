/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:09:48 by ysetiawa          #+#    #+#             */
/*   Updated: 2025/02/20 19:38:40 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_empty_env(t_minishell *mini)
{
	mini->env = malloc(3 * sizeof(t_env));
	if (!mini->env)
		return;

	mini->env[0].key = strdup("PWD");
	mini->env[0].value = strdup("/home/hthant");

	mini->env[1].key = strdup("SHLVL");
	mini->env[1].value = strdup("1");

	mini->env[2].key = strdup("_");
	mini->env[2].value = strdup("/usr/bin/env");
}


int	env_init(t_minishell *mini, char **env_array)
{
	if (!env_array || !env_array[0])
	{
		ft_putendl_fd("env_array is empty or NULL.", 2);
		handle_empty_env(mini);
		// return (1);
	}
	if (init_env_list(mini, env_array) != 0)
		return (1);
	// mini->env2 = env_list_to_array(mini->env);
	// printf("The mini->env2 is %s\n",mini->env2[0]);
	// 	if (!mini->env2)
	// {
	// 	ft_putstr_fd("Error: Failed to convert env_var to array\n", STDERR);
	// 	return (1);
	// }
	return (0);
}

int	count_env_vars(t_env *env)
{
	int		count;
	t_env	*tmp;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	is_valid_env(char *arg)
{
	int	i;

	if (!arg || !ft_isalpha(arg[0]))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
