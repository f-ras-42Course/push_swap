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
	
	// printf("\nNORMALIZED VALUES:\n");
	// i = 0;
	// ptr = data;
 	// printf("[HEAD %d] = %d, ", i++, ptr->normalized_value);
 	// ptr = ptr->next;
 	// while (ptr != data)
 	// {
 	// 	printf("[%d] = %d, ", i++, ptr->normalized_value);
 	// 	ptr = ptr->next;
 	// }
	// printf("\n[HEAD check] = %d\n", ptr->normalized_value);

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
	
	// printf("\nNORMALIZED VALUES:\n");
	// i = 0;
	// ptr = data;
 	// printf("[HEAD %d] = %d, ", i++, ptr->normalized_value);
 	// ptr = ptr->prev;
 	// while (ptr != data)
 	// {
 	// 	printf("[%d] = %d, ", i++, ptr->normalized_value);
 	// 	ptr = ptr->prev;
 	// }
	// printf("\n[HEAD check] = %d\n", ptr->normalized_value);

	printf("\n\n");

 	// Output:
 	// ./push_swap 4463 24 544 344
 	// [0] = 4463, [1] = 24, [2] = 544, [3] = 344, [4] = 4463, 
	// push_swap(data);
}