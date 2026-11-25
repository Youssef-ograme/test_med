#include "hedear.h"

static int ft_sqrt(int nb)
{
    int i = 1;
    while (i <= nb / i)
    {
        if (i * i == nb)
        {
            return i;
        }
        i++;
    }
    return 0;
}
void total_numbers(stack *head , int *total)
{
    *total = 0;
    while (head)
    {
        (*total)++;
        head = head -> next;
    }
}
int som_of_sqrt(stack *head , int *total)
{
    total_numbers(head ,total);
    return ft_sqrt(*total);
}
