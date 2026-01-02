#include "push_swap.h"

int *stack_to_array(t_stack *a, int size)
{
    int     *arr;
    int     i;
    t_node  *current;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);

    i = 0;
    current = a->head;
    while (current)
    {
        arr[i++] = current->value;
        current = current->next;
    }
    return (arr);
}

void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void assign_indexes(t_stack *a, int *arr, int size)
{
    t_node  *current;
    int     i;

    current = a->head;
    while (current)
    {
        i = 0;
        while (i < size)
        {
            if (arr[i] == current->value)
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
}
