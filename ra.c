#include "hedear.h"
static t_indx	*last_node(t_indx *s_a)
{
	if (!s_a)
		return (NULL);
	while (s_a->next != NULL)
		s_a = s_a->next;
	return (s_a);
}

void ra_index(t_indx **s_a)
{
    if(!s_a || !(*s_a) || !(*s_a)->next)
        return ;
    t_indx *end;
    t_indx *second;
    t_indx *last;
    last = last_node(*s_a);
    end = (*s_a);
    second = (*s_a) -> next;
    last -> next = end;
    end -> next = NULL;
    (*s_a) = second;
}