#pragma once

#include <stdbool.h>

struct context;

typedef bool (*exn_hnd_t)(int exn, struct context *c, void *arg);

int exn_set_hnd(int exn, exn_hnd_t h, void *arg);

void exn_do(int exn, struct context *c);

void initProgTimers();

void initTime(long long inittime);

void upTime(); 

long long getTime();

int setProgTimer(int time);

int getProgTimer(int i);

int* getProgTimers();

void progtimeup();
