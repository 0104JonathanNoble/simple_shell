#include "main.h"
/**
 * _env - get string array
 * @in: arguments to pass
 * Return: Always 0
 */
char *env(info_t *in)
{
	if (!in->envn || in->envo)
	{
		in->envn = list_to_string(in->envi);
		in->envo = 0;
	}
	return in->envn;
}

/**
 * _unsetenv - remove variable
 * @in: arguments
 * @var: the var
 * Return: 1 on success, 0 otherwise
 */
int _unsetenv(info_t *in, char *var)
{
	list_t *n = in->envi;
	size_t i = 0;
	char *v;

	if (!n || !var)
		return 0;
	while (n)
	{
		v = stw(n->str, var);
		if (v && v == '=')
		{
			in->envo = del(&(info->env), i);
			i = 0;
			n = in->envi;
			continue;
		}
		n = n->next;
		i++;
	}
	return in->envo;
}

/**
 * _setenv - initialize new env var
 * va: the string value
 * Return: Always 0
 */
int _setenv(info_t *, char *var, char *va)
{
	char *g = NULL;
	list_t *n;
	char *v;

	if (!var || !va)
		return 0;
	g = malloc(_str(var) + _str(val) + 2);
	if (!g)
		return 1;
	_strd(g, var);
	_strc(g, "=");
	_strc(g, val);

	n = in->envi;
	while (n)
	{
		v = st(n->str, var);
		if (v && *v == '=')
		{
			free(n->str);
			n->str = g;
			info->envo = 1;
			return 0;
		}
		n = n->next;
	}
	end(&(in->envi), g, 0);
	free(g);
	in->envo = 1;
	return 0;
}

