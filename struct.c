#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct.h"

struct node *new_node(int i, char *n)
{

	struct node *nu;

	nu = malloc(sizeof(struct node));

	strncpy(nu->text, n, sizeof(nu->text) - 1);
	nu->number = i;

	return nu;
}

void print_node(struct node *inputData)
{
	printf("%s -> %d\n", inputData->text, inputData->number);
}

void change_node(struct node *inputData, int new_number)
{
	inputData->number = new_number;
}

void print_list(struct node *in)
{
	while (in->next_node)
	{
		print_node(in);
		in = in->next_node;
	}
	print_node(in);
}

struct node *insert_front(struct node * next, char *text, int number)
{
	struct node * temp;
	temp=new_node(number,text);
	temp->next_node=next;
	return temp;
}

struct node *free_list(struct node *list_to_free){
	if(list_to_free->next_node)
		free_list(list_to_free->next_node);
	else
		free(list_to_free);
	return NULL;
}

struct node * remove_node(struct node *inputData, int data){
	struct node * prev_node;
	struct node * new_next_node;
	struct node * return_node;
	while(inputData->next_node){
		if(data==inputData->number){
			new_next_node=inputData->next_node;
			inputData->next_node=NULL;
			if(prev_node){
				prev_node->next_node=new_next_node;
			}
			else
			{
				return_node=inputData;
			}
			free_list(inputData);
			break;
		}
		prev_node=inputData;
		inputData=inputData->next_node;
	}
	return return_node;
}