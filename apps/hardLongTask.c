#include <kernel/syscall.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	for (int j = 0; j < 10; j++) {
		for (long long i = 1; i <= 100000000; i++) {}
		rprintf("%d iteration finished\n", j); 
	}
	rprintf("hardLongTask finished\n");
	return 0;
}
