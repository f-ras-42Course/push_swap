// temporary tester:

#include "push_swap.h"

void test (t_data *data)
{
	t_data *ptr;
	int i;

	if(!data)
	{
		printf("\n---TEST: NO DATA FOUND---\n");
		return;
	}
	printf("\n -- NEXT -- \n");

	printf("\nINPUT VALUES:\n");
 	i = 0;
	ptr = data;
 	printf("[HEAD %d] = %d\n", i++, ptr->input_value);
 	ptr = ptr->next;
 	while (ptr != data)
 	{
 		printf("[%d] = %d\n", i++, ptr->input_value);
 		ptr = ptr->next;
 	}
 	printf("\n[HEAD check] = %d\n", ptr->input_value);

	printf("\n\n");

	printf("\n -- PREV -- \n");
	i = 0;
	ptr = data;
 	printf("[HEAD %d] = %d\n", i++, ptr->input_value);
 	ptr = ptr->prev;
 	while (ptr != data)
 	{
 		printf("[%d] = %d\n", i++, ptr->input_value);
 		ptr = ptr->prev;
 	}
 	printf("\n[HEAD check] = %d\n", ptr->input_value);
	
	printf("\n\n");

}