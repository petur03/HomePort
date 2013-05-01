// request.c

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

#include <stdlib.h>
#include "libREST.h"

struct lr_request {
};

struct lr_request *lr_request_create(struct lr_instance *ins)
{
	struct lr_request *request = malloc(sizeof(struct lr_request));

	if(request == NULL)
	{
		fprintf(stderr, "malloc failed in libREST when creating instance\n");
	}

	return request;
}

void lr_request_destroy(struct lr_request *req)
{
	if(req)
		free(req);
}

int lr_request_url(void *req, const char *chuck, size_t len)
{
}

int lr_request_url_cmpl(void *req)
{
}

int lr_request_hdr_field(void *req, const char *chuck, size_t len)
{
}

int lr_request_hdr_value(void *req, const char *chuck, size_t len)
{
}

int lr_request_hdr_cmpl(void *req)
{
}

int lr_request_body(void *req, const char *chuck, size_t len)
{
}

int lr_request_cmpl(void *req)
{
}


