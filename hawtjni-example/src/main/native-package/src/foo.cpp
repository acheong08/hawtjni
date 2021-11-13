/*******************************************************************************
 * Copyright (C) 2009-2011 FuseSource Corp.
 * 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "foo.h"
#include <stdio.h>

float get_d(struct foo *arg) {
    return 0.0f;
}
void set_d(struct foo *arg, float d) {
}

std::shared_ptr<intptr_t> get_sp(long CheckStr) {
    return std::make_shared<intptr_t> (CheckStr);
}
void set_sp(struct foo *arg, std::shared_ptr<intptr_t> ptr) {
}

void print_foo(struct foo *arg) {
    printf("foo@%p: { a: %d, b: %d, c: \"%s\", prev: @%p, d: %f, Checkstr: %p}\n", arg, arg->a, (int)arg->b, arg->c, arg->prev, get_d(arg), get_sp(arg->CheckStr).get());
}

size_t foowork(struct foo **arg, int count) {
    size_t rc=0;
	int i=0;
	for( i=0; i < count; i++ ) {
	   rc = rc + (*arg)->a;
	   rc = rc + (*arg)->b;
	   arg++;
	}
	return rc;
}

void callmeback(void (*thecallback)(int number)) {
	thecallback(69);
}

int product(int u, int v) {
	return u * v;
}

int callproduct(t_somefunc prod) {
	return prod(2, 3);
}

struct foo * foo_add(struct foo *arg, int count) {
    return arg+count;
}

char * char_add(char *arg, int count) {
    return arg+count;
}

void passingtheenv (const char *who, JNIEnv *env) {
    printf("%s, the JNIEnv is at: %p\n", who, env);
}
