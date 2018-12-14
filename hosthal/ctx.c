#define _GNU_SOURCE

#include <stddef.h>

#include "hal/context.h"
#include "hal_context.h"
#include "util.h"
#include "exn.h"

#include <string.h>

void ctx_make(struct uctx *ctx, void *entry, void *stack, int stacksz) {
	memset(ctx, 0, sizeof(*ctx));

	ctx->rsp = (unsigned long) stack + stacksz - 16;
	ctx->rsp = ctx->rsp;
	ctx->rsp -= 8;
	*(unsigned long *)ctx->rsp = (unsigned long) entry;
}

void ctx_copy(struct context *old_ctx, struct context *_ctx) {
	struct exn_ctx *new_ctx = (struct exn_ctx *) old_ctx;
	memset(new_ctx, 0, sizeof(*new_ctx));
	struct exn_ctx *cur_ctx = (struct exn_ctx *) _ctx;
	
	//dbg_out("copyping\n", 9);
	new_ctx->sp = cur_ctx->sp;
	new_ctx->rbx = cur_ctx->rbx;
	new_ctx->r12 = cur_ctx->r12;
	new_ctx->r13 = cur_ctx->r13;
	new_ctx->r14 = cur_ctx->r14;
	new_ctx->r15 = cur_ctx->r15;
	new_ctx->r11 = cur_ctx->r11;
	new_ctx->r10 = cur_ctx->r10;
	new_ctx->r9 = cur_ctx->r9;
	new_ctx->r8 = cur_ctx->r8;
	new_ctx->rdi = cur_ctx->rdi;
	new_ctx->rsi = cur_ctx->rsi;
	new_ctx->rdx = cur_ctx->rdx;
	new_ctx->rcx = cur_ctx->rcx;
	new_ctx->rax = 0;//cur_ctx->rax;
	new_ctx->rflags = cur_ctx->rflags;
	new_ctx->target = cur_ctx->target;
	new_ctx->exn = cur_ctx->exn;
	new_ctx->rip = cur_ctx->rip;
}


//display /i $pc
