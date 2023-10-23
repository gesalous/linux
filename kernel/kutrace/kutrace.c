// SPDX-License-Identifier: BSD-3-Clause
/*
 * kernel/kutrace/kutrace.c
 *
 * Author: Richard Sites <dick.sites@gmail.com>
 * Signed-off-by: Richard Sites <dick.sites@gmail.com>
 */

/*
 * Small hooks for a module that implements kernel/user tracing
 * See include/linux/kutrace.h for struct definitions
 *
 * Most patches will be something like
 *   kutrace1(event, arg)
 *
 */

#include <linux/kutrace.h>
#include <linux/kernel.h>
#include <linux/percpu.h>
#include <linux/types.h>

bool kutrace_tracing = false;
EXPORT_SYMBOL(kutrace_tracing);

struct kutrace_ops kutrace_global_ops = {NULL, NULL, NULL, NULL};
EXPORT_SYMBOL(kutrace_global_ops);

u64* kutrace_pid_filter = NULL;
EXPORT_SYMBOL(kutrace_pid_filter);

struct kutrace_nf kutrace_net_filter = {0LLU, {0LLU, 0LLU, 0LLU}};
EXPORT_SYMBOL(kutrace_net_filter);

DEFINE_PER_CPU(struct kutrace_traceblock, kutrace_traceblock_per_cpu);
EXPORT_PER_CPU_SYMBOL(kutrace_traceblock_per_cpu);





