/*
 * fs_param.h
 *
 * File server parameters (used by both clients and server).
 */

#ifndef _FS_PARAM_H_
#define _FS_PARAM_H_

/*
 * File system parameters
 */

/*
 * Size of a disk block (in bytes)
 */
#define FS_BLOCKSIZE	512

/*
 * Maximum # of data blocks in a file or directory.  Computed so that
 * an inode is exactly 1 block, i.e.,
 * (FS_BLOCKSIZE - (FS_MAXUSERNAME+1) - sizeof(unsigned int)) / sizeof(unsigned int)
 */
#define FS_MAXFILEBLOCKS  124

/*
 * Maximum name of a file, not including the null terminator
 */
#define FS_MAXFILENAME	11

/*
 * Maximum name of a user, not including the null terminator
 */
#define FS_MAXUSERNAME	11

/*
 * Maximum password length, not including the null terminator
 */
#define FS_MAXPASSWORD	15

#endif /* _FS_PARAM_H_ */
