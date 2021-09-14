#include "../inc/push_swap.h"

void s(t_stack *a, t_stack *b, char *cmd);
void r(t_stack *a, t_stack *b, char *cmd);
void rr(t_stack *a, t_stack *b, char *cmd);
void p(t_stack *a, t_stack *b, char *cmd);

void pick(char *cmd, t_stack *a, t_stack *b)
{
	if (cmd[0] == 's')
		s(a, b, cmd);
	else if (cmd[0] == 'r' && !cmd[2])
		r(a, b, cmd);
	else if (cmd[0] == 'r' && cmd[2])
		rr(a, b, cmd);
	else if (cmd[0] == 'p')
		p(a, b, cmd);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
}

void s(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		swap(a);
	else if (cmd[1] == 'b')
		swap(b);
	else
	{
		swap(a);
		swap(b);
	}
}

void r(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		rotate(a);
	else if (cmd[1] == 'b')
		rotate(b);
	else
	{
		rotate(a);
		rotate(b);
	}
}

void rr(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		reverse(a);
	else if (cmd[1] == 'b')
		reverse(b);
	else
	{
		reverse(a);
		reverse(b);
	}
}

void p(t_stack *a, t_stack *b, char *cmd)
{
	if (cmd[1] == 'a')
		push(b, a);
	else if (cmd[1] == 'b')
		push(a, b);
}
