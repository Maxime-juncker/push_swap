#include "push_swap.h"

/* t_node	*create_node(int value, t_node *pre, t_node *next)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->pre = pre;
	node->next = next;
	node->value = value;
	return (node);
}

void	node_addfront(t_node **start, t_node *new)
{
	if (start[0] == NULL)
	{
		start[0] = new;
		return ;
	}

	if (start[0]->next != NULL)
	{
		start[0]->next->pre = new;
		new->next = start[0]->next;
	}
	start[0]->next = new;
	start[0] = new;
}

t_node	*node_pop(t_node **start)
{
	if (start[0] == NULL)
		return (NULL);
} */