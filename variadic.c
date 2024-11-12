// 2024-11-12

#include <stdarg.h>
#include <stdio.h>

// Returns the sum of the arguments.
// End the argument list with a negative number or you are doomed.
//
// 1) Compare this function with printf.
// 2) This is just a demo; arrays are recommended for this use case.
// 3) A better use case would be arguments of mixed and unknown data
//    types, like in printf.
//
int sum_positive(int first_number, ...)
{
	int sum = first_number;

	va_list ap;
	va_start(ap, first_number);

	while(1) {
		int next = va_arg(ap, int);
		if(next < 0)
			break;

		sum += next;
	}

	va_end(ap);

	return sum;
}

int main()
{
	int sum = sum_positive(8, 10, 2, 1, -1);
	printf("sum = %d\n", sum);

	return 0;
}
