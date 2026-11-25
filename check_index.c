#include "hedear.h"

static t_indx *creat_index (int rank , int nb)
{
    t_indx *new = malloc (sizeof (t_indx));
    if (!new)
        return NULL;
    new -> index = rank;
    new -> nb =  nb;
    new -> next = NULL;
    return new;
}

static void	ft_indexadd_back(t_indx **lst, t_indx *new)
{
	t_indx	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_indx *add_rank (stack *list)
{
    int rank;
    stack *head1 = list;
    stack *head2;
    t_indx *new;
    t_indx *new_nodes = NULL;
    while (head1)
    {
        head2 = list;
        rank = 0;
        while (head2)
        {
            if (head1->nb > head2 -> nb)
                rank++;
            head2 = head2 -> next;
        }
        new = creat_index(rank , head1->nb);
        if (!new)
            return (NULL);
        ft_indexadd_back(&new_nodes,new);
        head1 = head1 -> next;
    }
    return new_nodes;
}

// #include <stdio.h>
// void print_nodes(t_indx *head)
// {
//     while (head)
//     {
//         printf ("nb : %d index: %d\n",head -> nb , head -> index);
//         head = head -> next;
//     }
// }
// int main ()
// {
//     stack a = {5, NULL};
//     stack b = {2, NULL};
//     stack c = {8, NULL};
//     stack d = {1, NULL};

//     a.next = &b;
//     b.next = &c;
//     c.next = &d;
//     t_indx *res = add_rank(&a);
//     print_nodes(res);    
//     return (0);
// }