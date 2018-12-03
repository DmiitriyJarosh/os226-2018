#include <stdio.h>
#include <kernel/syscall.h>
int main(int argc, char *argv[]) {
	rprintf("start\n");
	os_fork();
	for (int i = 0; i < 2; ++i) {
		rprintf("%d\n", i);
	}
	rprintf("end");
	return 0;
}
