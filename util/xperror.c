#include "util.h"
#include <sys/errno.h>
#include <unistd.h>

#ifndef ELAST
# define ELAST 255
#endif

static char *xerrlist[ELAST + 1] = {
	[0] = "No error value set (success?)",
	[EPERM] = "Operation not permitted",
	[ENOENT] = "No such file or directory",
	[ESRCH] = "No such process",
	[EINTR] = "Interrupted system call",
	[EIO] = "Input/output error",
	[ENXIO] = "Device not configured",
	[E2BIG] = "Argument list too long",
	[ENOEXEC] = "Exec format error",
	[EBADF] = "Bad file descriptor",
	[ECHILD] = "No child processes",
	[EDEADLK] = "Resource deadlock avoided",
	[ENOMEM] = "Cannot allocate memory",
	[EACCES] = "Permission denied",
	[EFAULT] = "Bad address",
	[EBUSY] = "Device / Resource busy",
	[EEXIST] = "File exists",
	[EXDEV] = "Cross-device link",
	[ENODEV] = "Operation not supported by device",
	[ENOTDIR] = "Not a directory",
	[EISDIR] = "Is a directory",
	[EINVAL] = "Invalid argument",
	[ENFILE] = "Too many open files in system",
	[EMFILE] = "Too many open files",
	[ENOTTY] = "Inappropriate ioctl for device",
	[ETXTBSY] = "Text file busy",
	[EFBIG] = "File too large",
	[ENOSPC] = "No space left on device",
	[ESPIPE] = "Illegal seek",
	[EROFS] = "Read-only file system",
	[EMLINK] = "Too many links",
	[EPIPE] = "Broken pipe",
	[EDOM] = "Numerical argument out of domain",
	[ERANGE] = "Result too large",
	[EWOULDBLOCK] = "Resource temporarily unavailable",
	[EINPROGRESS] = "Operation now in progress",
	[EALREADY] = "Operation already in progress",
	[ENOTSOCK] = "Socket operation on non-socket",
	[EDESTADDRREQ] = "Destination address required",
	[EMSGSIZE] = "Message too long",
	[EPROTOTYPE] = "Protocol wrong type for socket",
	[ENOPROTOOPT] = "Protocol not available",
	[EPROTONOSUPPORT] = "Protocol not supported",
	[ENOTSUP] = "Operation not supported",
	[EAFNOSUPPORT] = "Address family not supported by protocol family",
	[EADDRINUSE] = "Address already in use",
	[EADDRNOTAVAIL] = "Can't assign requested address",
	[ENETDOWN] = "Network is down",
	[ENETUNREACH] = "Network is unreachable",
	[ENETRESET] = "Network dropped connection on reset",
	[ECONNABORTED] = "Software caused connection abort",
	[ECONNRESET] = "Connection reset by peer",
	[ENOBUFS] = "No buffer space available",
	[EISCONN] = "Socket is already connected",
	[ENOTCONN] = "Socket is not connected",
	[ETIMEDOUT] = "Operation timed out",
	[ECONNREFUSED] = "Connection refused",
	[ELOOP] = "Too many levels of symbolic links",
	[ENAMETOOLONG] = "File name too long",
	[EHOSTUNREACH] = "No route to host",
	[ENOTEMPTY] = "Directory not empty",
	[EDQUOT] = "Disc quota exceeded",
	[ESTALE] = "Stale NFS file handle",
	[ENOLCK] = "No locks available",
	[ENOSYS] = "Function not implemented",
	[EOVERFLOW] = "Value too large to be stored in data type",
	[ECANCELED] = "Operation canceled",
	[EIDRM] = "Identifier removed",
	[ENOMSG] = "No message of desired type",
	[EILSEQ] = "Illegal byte sequence",
	[EBADMSG] = "Bad message",
	[EMULTIHOP] = "Reserved",
	[ENODATA] = "No message available on STREAM",
	[ENOLINK] = "Reserved",
	[ENOSR] = "No STREAM resources",
	[ENOSTR] = "Not a STREAM",
	[EPROTO] = "Protocol error",
	[ETIME] = "STREAM ioctl timeout",
};

void	xperror(char *s)
{
	if (g_progname)
	{
		xprinterr(g_progname);
		xprinterr(": ");
	}
	if (g_modulename)
	{
		xprinterr(g_modulename);
		xprinterr(": ");
	}
	if (s)
	{
		xprinterr(s);
		xprinterr(": ");
	}
	if (errno > ELAST || !xerrlist[errno])
		xputserr("Unknown error");
	else
		xputserr(xerrlist[errno]);
}
