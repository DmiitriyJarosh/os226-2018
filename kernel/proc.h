#pragma once

#include <stdbool.h>
#include "hal_context.h"
#include "third-party/queue.h"
#include "exn.h"

struct proc {
	TAILQ_ENTRY(proc) lentry;
	struct uctx ctx;
	struct proc *parent;

	int code;

	bool sleep;
	bool inqueue;
	bool exited;

	bool first_run_fork;

	struct proc *childs[20];
	int nextChild;
	int childNum;

	bool canExit;

	struct proc *forkParent;

	struct exn_ctx full_ctx;

	void *load;
	int loadn;

	void *stack;
	int stackn;

	void *argvb;
	int argvbn;
	char **argv;
	int nargv;
	void (*entry)(void);
};

extern struct proc *current_process();
