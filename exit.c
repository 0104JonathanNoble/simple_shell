#include "main.h"
/**
 * ext - exit the built-in shell
 * @in: arguments used
 * Return: exit
 */
int ext(info_t *in)
{
	int ec;

	if (in->argv[1])
	{
		ec = _to(in->argv[1]);
		if (ec == -1)
		{
			in->status = 2;
			print_e(in, "Illegal number: ");
			_puts(in->argv[1]);
			_putchar('\n');
			return 1;
		}
		in->error_num = ec; return 1;
	}
	in->error_num = -1;
	return -2;
}

/**
 * ncd - change directory
 * Return: Always 0
 */
int ncd(info_t *in)
{
	char *s, *d, buffer[1024];
	int d_ch;

	s = getcwd(buffer, 1024);
	if (!s)
		_put("TODO: >>getcwd failure emsg here<<\n");
	if (!in->argv[1])
	{
		d = _env(in, "HOME=");
		if (!d)
			
