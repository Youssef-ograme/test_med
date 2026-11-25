#include "hedear.h"

static void	chunk_update(int *max, int *push, int som, int total)
{
	*max += som;
	*push = 0;
	if (total - 1 - *max < som)
		*max = total - 1;
}

t_indx	*res_from_stack(stack *list, t_indx *stack_b)
{
	t_indx	*stack_a;
	int		som;
	int		max;
	int		push;
	int		total;

	som = som_of_sqrt(list , &total);
	max = som - 1;
	push = 0;
	stack_a = add_rank(list);
	while (stack_a)
	{
		if (stack_a->index <= max)
		{
			pb_index(&stack_a, &stack_b);
			push++;
		}
		else
			ra_index(&stack_a);
		if (push == som)
			chunk_update(&max, &push, som, total);
	}
	return (stack_b);
}

// #include <stdio.h>
// void print_nodes(t_indx *head)
// {
//     while (head)
//     {
//         printf ("nb : %d\n",head -> nb);
//         head = head -> next;
//     }
// }
// int main ()
// {
//     stack a = {5, NULL};
//     stack b = {2, NULL};
//     stack c = {8, NULL};
//     stack d = {1, NULL};
//     stack e = {9, NULL};
//     stack f = {4, NULL};
//     stack g = {7, NULL};
//     stack h = {3, NULL};
//     stack i = {6, NULL};

//     a.next = &b;
//     b.next = &c;
//     c.next = &d;
//     d.next = &e;
//     e.next = &f;
//     f.next = &g;
//     g.next = &h;
//     h.next = &i;
//     t_indx *stack_b = NULL;
//     t_indx *res = res_from_stack(&a,stack_b);
//     print_nodes(res);    
//     return (0);
// }