#include "main.h"

/**
 * main - implements super simple shell
 *
 * @ac: number of commandline arguments
 * @av: array of commandline arguments
 * @env: array of environment variables
 *
 * Return: 0. otherwise 1
 */
int main(int ac, char **av, char **env)
{
	list_t *env_list = NULL;
	int shell_return;

	/* create env_list */
	env_list = create_env(env, env_list);

	/* handle SIGINT */
	signal(SIGINT, sig_handler);

	/* start shell */
	shell_return = shell(env_list, av[0]);

	/*check return value of shell */
	if (shell_return)
	{
		free_list(env_list);
		exit(shell_return);
	}

	(void)ac;

OAOAOA	free_list(env_list);

OAOAOA	return (0);
}

/**
 * sig_handler - handles SIGINT
 * @sig: SIGINT
OAOAOA */
void sig_handler(int sig)
{
	signal(sig, sig_handler);
	write(STDOUT_FILENO, "\n", 2);
	prompt();
}
