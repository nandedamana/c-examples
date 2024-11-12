// 2024-11-12

#include <stdio.h>

// _Bool accepts {0, 1}; should take only one byte.

// First compile and run with the #pragma line commented out;
// then uncomment it, compile and run again.
//#pragma pack(1)
struct ComputerSpec {
	_Bool is_portable;
	float weight_kg;
	int   mfd_year;
	_Bool has_wifi;
};

int main()
{
	struct ComputerSpec s;

	printf("sizeof(is_portable) = %zu\n", sizeof(s.is_portable));
	printf("sizeof(weight_kg) = %zu\n", sizeof(s.weight_kg));
	printf("sizeof(mfd_year) = %zu\n", sizeof(s.mfd_year));
	printf("sizeof(has_wifi) = %zu\n\n", sizeof(s.has_wifi));

	size_t sum =
		sizeof(s.is_portable) + sizeof(s.weight_kg)
		+ sizeof(s.mfd_year) + sizeof(s.has_wifi);

	printf("Sum of the above = %zu\n", sum);
	printf("sizeof(s) = %zu\n", sizeof(s));
	printf("Padding inserted by the compiler = %zu\n", sizeof(s) - sum);

	return 0;
}
