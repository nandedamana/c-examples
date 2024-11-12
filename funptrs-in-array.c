// 2024-11-12

// Demonstration of dynamically selecting the function to call.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }

int main()
{
	// We have an array of expected inputs and another array of pointers 
	// to the corresponding functions.
	char *operations[]      = { "+", "-", "*" };
	int(*funs[])(int, int)  = { add, sub, mul };
	int opcount = sizeof(operations) / sizeof(operations[0]); // = 3

	int x, y, res;
	char opstr[3];

	printf("Enter two integers: ");
	scanf("%d%d", &x, &y);

	printf("Enter an operator (+, -, *): ");
	// We need to read only one char, but read one more to reject, say, "++"
	scanf("%2s", opstr);

	int i;
	for(i = 0; i < opcount; i++) {
		if(strcmp(opstr, operations[i]) == 0) {
			res = funs[i](x, y);
			break;
		}
	}

	// The i loop should've broken earlier for a valid input.
	if(i == opcount) {
		fprintf(stderr, "Invalid operation.\n");
		return -1;
	}

	printf("%d %s %d = %d\n", x, opstr, y, res);
	return 0;
}
