/*
 * Copyright 2001 David Mansfield and Cobite, Inc.
 * See COPYING file for license information 
 */

#ifndef UTIL_INLINE_H
#define UTIL_INLINE_H

#ifdef unix
#define INLINE __inline__
#endif

#ifdef WIN32
#define INLINE __inline
#endif

#ifdef MACINTOSH
#define INLINE /* void */
#endif

#endif
