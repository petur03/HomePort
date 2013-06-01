// linkedmap.c

/*  Copyright 2013 Aalborg University. All rights reserved.
 *   
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *  
 *  2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *  
 *  THIS SOFTWARE IS PROVIDED BY Aalborg University ''AS IS'' AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Aalborg University OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 *  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 *  SUCH DAMAGE.
 *  
 *  The views and conclusions contained in the software and
 *  documentation are those of the authors and should not be interpreted
 *  as representing official policies, either expressed.
 */

#include <string.h>
#include "../include/linkedmap.h"
#include "linked_list.h"

struct lm
{
	struct ll *pairs;
};

struct pair
{
	char* key;
	char* value;
};

struct lm *lm_create()
{
	struct lm *ret = malloc(sizeof(struct lm));
	if(ret == NULL)	{
		fprintf(stderr, "Malloc failed when creating new linkedmap\n");
		return NULL;
	}

	ll_create(ret->pairs);
	if(ret->pairs == NULL) {
		fprintf(stderr, "Malloc failed when creating new linkedlist in linkedmap\n");
		return NULL; 
	}

	return ret;
}

void lm_destroy(struct lm *map)
{
	struct ll_iter *it;

	if(map)	{
		// Loop through and destroy all keys
		for(it = ll_head(map->pairs); it != NULL; it = ll_next(it))	{
			free(((struct pair*)ll_data(it))->key);
			free(((struct pair*)ll_data(it))->value);
			free(((struct pair*)ll_data(it)));
		}

		ll_destroy(map->pairs);
	}
}

int lm_insert(struct lm *map, const char* key, const char* value)
{
	// Check if the item is already in the list
	if(lm_find(map, key) != NULL)
		return 1;

	char *mKey = malloc(strlen(key)*sizeof(char));
	if(mKey == NULL) {
		fprintf(stderr, "Malloc failed when allocating key for linkedmap\n");
		return 2;
	}

	char *mValue = malloc(strlen(value)*sizeof(char));
	if(mValue == NULL) {
		fprintf(stderr, "Malloc failed when allocating value for linkedmap\n");
		return 2;
	}

	struct pair *p = malloc(sizeof(struct pair));
	if(p == NULL) {
		fprintf(stderr, "Malloc failed when allocating pair struct for linkedmap\n");
		return 2;
	}

	strcpy(mValue, value);
	strcpy(mKey, key);

	p->key = mKey;
	p->value = mValue;

	ll_insert(map->pairs, ll_tail(map->pairs), p);

	return 0;
}

void lm_remove(struct lm *map, const char* key)
{
	struct ll_iter *it;

	if(map){
		for(it = ll_head(map->pairs); it != NULL; it = ll_next(it)) {
			if(strcmp(((struct pair*)ll_data(it))->key,key) == 0) {
				free(((struct pair*)ll_data(it))->key);
				free(((struct pair*)ll_data(it))->value);
				free(((struct pair*)ll_data(it)));
				ll_remove(it);
			}
		}
	}
}

char* lm_find(struct lm *map, const char* key)
{
	struct ll_iter *it;

	if(map){
		for(it = ll_head(map->pairs); it != NULL; it = ll_next(it)) {
			if(strcmp(key, ((struct pair*)ll_data(it))->key) == 0) {
				return ((struct pair*)ll_data(it))->value;
			}
		}
	}
	return NULL;
}

void lm_map(struct lm *map, lm_map_cb func)
{
	if(map && func) {
		struct ll_iter *it;
		for(it = ll_head(map->pairs); it != NULL; it = ll_next(it)) {
			func(((struct pair*)ll_data(it))->key, ((struct pair*)ll_data(it))->value);
		}
	}
}





