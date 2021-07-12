#include "solong.h"

int	isinlist(t_coordinates *component, int x, int y)
{
	while (component != NULL)
	{
		if (component->y == y && component->x == x)
			break ;
		component = component->next;
	}
	if (component == NULL)
		return (0);
	return (1);
}

void	remove_list_srtuct(t_coordinates **component, int x, int y)
{
	t_coordinates	*start;
	t_coordinates	*temp;

	start = *component;
	temp = *component;
	while (temp != NULL)
	{
		if (temp->y == y && temp->x == x)
			break ;
		temp = temp->next;
	}
	if (start == temp)
		*component = start->next;
	else
	{
		while (start->next != temp)
			start = start->next;
		if (temp->next == NULL)
			start->next = NULL;
		else
			start->next = temp->next;
	}
	free (temp);
}
