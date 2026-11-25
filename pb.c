#include "hedear.h"

void	pb_index(t_indx **a, t_indx **b)
{
	t_indx	*temp;

	if (!a || !b || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	// write(1, "pb\n", 3);
}