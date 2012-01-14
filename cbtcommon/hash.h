/*
 * Copyright 2001, 2002 David Mansfield and Cobite, Inc.
 * See COPYING file for license information 
 */

#ifndef _COMMON_HASH_H
#define _COMMON_HASH_H

#include "list.h"

struct hash_entry
{
    char              *he_key;
    void              *he_obj;
    struct list_head   he_list;
};

struct hash_table
{
    int                ht_size;
    struct list_head  *ht_lists;
    int                iterator;
    struct list_head  *iterator_ptr;
};

#ifdef __cplusplus
extern "C" {
#endif

struct hash_table *create_hash_table(unsigned int sz);
void destroy_hash_table(struct hash_table *tbl, void (*delete_obj)(void *));
void *put_hash_object(struct hash_table *tbl, const char *key, void *obj);
void *get_hash_object(struct hash_table *tbl, const char *key);
void *remove_hash_object(struct hash_table *tbl, const char *key);

void reset_hash_iterator(struct hash_table *tbl);
struct hash_entry *next_hash_entry(struct hash_table *tbl);

#ifdef __cplusplus
}
#endif

#endif /* _COMMON_HASH_H */
