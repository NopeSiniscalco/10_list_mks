#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	srand(time(NULL));
	int max_pop=abs(rand());

	struct node *Data1;
	Data1 = new_node(max_pop/100, "USA");

	struct node *Data2;
	Data2 = new_node(max_pop / 1000, "New York");
	Data1->next_node = Data2;

	struct node *Data3;
	Data3 = new_node(max_pop / 10000, "Manhattan");
	Data2->next_node = Data3;

	struct node *Data0;
	Data0=insert_front(Data1,"North America",max_pop/10);

	print_list(Data0);
	printf("\n\n");

	remove_node(Data0,max_pop/1000);

	print_list(Data0);
	printf("\n\n Seg Fault expected:\n");

	Data0=free_list(Data0);

	print_list(Data0);

	return 0;
}