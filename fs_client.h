/*
 * fs_client.h
 *
 * Header file for clients of the file server.
 */

#ifndef _FS_CLIENT_H_
#define _FS_CLIENT_H_

#include <sys/types.h>
#include <netinet/in.h>

#include "fs_param.h"

/*
 * Initialize the client library.
 * The location of the file server is specified by (hostname, port).
 *
 * fs_clientinit returns 0 on success, -1 on failure.
 */
extern int fs_clientinit(const char *hostname, uint16_t port);

/*
 * Ask the file server for a new session.  The new session is returned
 * in *session_ptr.
 *
 * fs_session returns 0 on success, -1 on failure.  Possible failures are:
 *     bad username or password
 *
 * fs_session is thread safe.
 */
extern int fs_session(const char *username, const char *password,
                      unsigned int *session_ptr, unsigned int sequence);

/*
 * Read a portion of the file "filename".  "offset" specifies the starting
 * byte of the portion to be read; "size" specifies the number of bytes to
 * read from the file.  "buf" gives a pointer in the client's address space
 * where the read data should be stored.
 *
 * fs_read returns 0 on success, -1 on failure.  Possible failures are:
 *     filename is not owned by username
 *     filename does not exist
 *     size is invalid (e.g., 0)
 *     there are not enough bytes in the file to satisfy the request
 *     invalid session or sequence
 *     bad username or password
 *
 * fs_read is thread safe.
 */
extern int fs_read(const char *username, const char *password,
                   unsigned int session, unsigned int sequence,
                   const char *filename, unsigned int offset, void *buf,
                   unsigned int size);

/*
 * Append data to an existing file "filename".  The data to be appended
 * starts at "buf" and is "size" bytes long.
 *
 * fs_append returns 0 on success, -1 on failure.  Possible failures are:
 *     filename is not owned by username
 *     filename does not exist
 *     size is invalid (e.g., 0)
 *     the disk or file is out of space
 *     invalid session or sequence
 *     bad username or password
 *
 * fs_append is thread safe.
 */
extern int fs_append(const char *username, const char *password, unsigned
                     int session, unsigned int sequence,
                     const char *filename, const void *buf,
                     unsigned int size);

/*
 * Create a new file "filename".
 *
 * fs_create returns 0 on success, -1 on failure.  Possible failures are:
 *     filename already exists
 *     filename too long
 *     the directory or disk is out of space
 *     invalid session or sequence
 *     bad username or password
 *
 * fs_create is thread safe.
 */
extern int fs_create(const char *username, const char *password,
                     unsigned int session, unsigned int sequence,
                     const char *filename);

/*
 * Delete the existing file "filename".
 *
 * fs_delete returns 0 on success, -1 on failure.  Possible failures are:
 *     filename is not owned by username
 *     filename does not exist
 *     invalid session or sequence
 *     bad username or password
 *
 * fs_delete is thread safe.
 */
extern int fs_delete(const char *username, const char *password,
                     unsigned int session, unsigned int sequence,
                     const char *filename);

#endif /* _FS_CLIENT_H_ */
