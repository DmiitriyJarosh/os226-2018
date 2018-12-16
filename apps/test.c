#include <stdio.h>
#include <kernel/syscall.h>
int main(int argc, char *argv[]) {
	rprintf("start\n");
	int tmp = os_fork();
	rprintf("os_fork returned: %d\n", tmp);
	for (int i = 0; i < 2; ++i) {
		rprintf("%d\n", i);
	}
	rprintf("end\n");
	return 0;
}
