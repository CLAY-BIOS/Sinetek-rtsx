#ifndef SINETEK_RTSX_OPENBSD_OPENBSD_COMPAT_KTHREAD_H
#define SINETEK_RTSX_OPENBSD_OPENBSD_COMPAT_KTHREAD_H

#include <sys/cdefs.h> // __BEGIN_DECLS, __END_DECLS

// forward-declaration
struct proc;

__BEGIN_DECLS

int
kthread_create(void (*func)(void *), void *arg, struct proc **newpp, const char *name);

/// The system will call back the function func with argument arg when it can create threads, so it is up to func to
/// call kthread_create() at that point.
void kthread_create_deferred(void (*func)(void *), void *arg);

void
kthread_exit(int ecode);

__END_DECLS

#endif // SINETEK_RTSX_OPENBSD_OPENBSD_COMPAT_KTHREAD_H
