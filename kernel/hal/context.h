#pragma once
#include "exn.h"

struct uctx;
struct context;
struct exn_ctx;

extern void ctx_make(struct uctx *ctx, void *entry, void *stack, int stacksz);
extern void ctx_copy(struct context *new_ctx, struct context *_ctx);
extern void ctx_switch(struct uctx *old, struct uctx *new);
extern void ctx_switchARG(struct uctx *old, struct uctx *new);
