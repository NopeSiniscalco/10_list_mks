struct node *new_node(int i, char *n);
void print_node(struct node *inputData);
struct node
{
	char text[256];
	int number;
	struct node *next_node;
};
void change_node(struct node *inputData, int new_number);
void print_list(struct node *in);
struct node *insert_front(struct node *, char *text, int number);
struct node *free_list(struct node *list_to_free);
struct node * remove_node(struct node *inputData, int data);