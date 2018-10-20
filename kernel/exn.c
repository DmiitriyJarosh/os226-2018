
#include "util.h"
#include "exn.h"
#include "hal/exn.h"
#include "ksys.h"

#define EXN_N_MAX 64
#define NUM_OF_PROGTIMERS 40

static struct exndes {
	exn_hnd_t hnd;
	void* arg;
} exn_hnd_table[EXN_N_MAX];

static int progtimers[NUM_OF_PROGTIMERS + 1];
static long long time;

int exn_set_hnd(int exn, exn_hnd_t h, void *arg) {
	if (exn < 0 || EXN_N_MAX <= exn) {
		return -1;
	}
	struct exndes *e = &exn_hnd_table[exn];
	e->hnd = h;
	e->arg = arg;

	return 0;
}

void exn_do(int exn, struct context *c) {
	assert(0 <= exn && exn < EXN_N_MAX);
	struct exndes *e = &exn_hnd_table[exn];

	if (!e->hnd) {
		return;
	}

	e->hnd(exn, c, e->arg);
}

void initProgTimers() {
	for (int i = 0; i < NUM_OF_PROGTIMERS; i++) {
		progtimers[i] = -1;
	}
}
int* getProgTimers() {
	return &progtimers[0];
}
int getProgTimer(int i) {
	return progtimers[i];
}
int setProgTimer(int time) {
	for (int i = 0; i < NUM_OF_PROGTIMERS + 1; i++) {
		if (progtimers[i] == -1) {
			progtimers[i] = time;
			return i;
		}
	}
	return -1;
}
void progtimeup() {
	for (int i = 0; i < NUM_OF_PROGTIMERS; i++) {
		if (progtimers[i] != -1) {
			progtimers[i]--;
		}
	}
	if (progtimers[NUM_OF_PROGTIMERS] > 0) {
		progtimers[NUM_OF_PROGTIMERS]--;
	}
}
void initTime(long long inittime) {
	time = inittime;
}
void upTime() {
	time++;
}
long long getTime() {
	return time;
}

void checkTime() {
	if (progtimers[NUM_OF_PROGTIMERS] == 0) {
		sched();
	}
}

void setTime(int t) {
	progtimers[NUM_OF_PROGTIMERS] = t;
}
