#include "libft.h"

List    *new_list(void)
{
	List 	*list;

    if (!(list = (List *)malloc(sizeof(List))))
		ft_putstr_fd("Malloc error list\n", 1); // liberar espacios
    list->first = NULL;
    list->size = 0;
    return (list);
}

Node    *new_node(char *s)
{
    Node *node = (Node *)malloc(sizeof(Node)); // liberar espacio
    node->element = ft_strdup(s); // liberar espacio 
    node->next = NULL;
    return (node);
}

void    destructor_node(Node *node)
{
    free(node->element);
    free(node);
}

void    destructor_list(List *list) // no se si esta bien
{
    int i;
 
    i = 0;
    while (list->first != NULL)
    {
        pop_front(list);
        i++;
    }
    free(list);
}

int     size_list(List *lista)
{
    return (lista->size);
}









static void ft_destroy_node(Node *node)
{
    free(node->element);
    free(node);
}
static void ft_remove_back(List *list)
{
    Node  *pop;
    Node  *prev_position;
    pop = list->first;
    prev_position = NULL;
    if (list->first != NULL)
    {
        if (list->size > 1)
        {
            while (pop->next != NULL)
            {
                prev_position = pop;
                pop = pop->next;
            }
            prev_position->next = NULL;
        }
        else
            list->first = NULL;
        ft_destroy_node(pop);
        list->size--;
    }
}
void        ft_free_lists(List *list)
{
    while (list->first != NULL)
        ft_remove_back(list);
    free(list);
}

