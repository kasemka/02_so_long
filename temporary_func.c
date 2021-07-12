#include "solong.h"


void printfCoordinates(t_coordinates *stack) 
{
	while (stack) {
		printf("%d %d\n", stack->x, stack->y);
		stack = stack->next;
	}
	printf("\n");
}
