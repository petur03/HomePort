# Copyright 2013 Aalborg University. All rights reserved.
#  
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY Aalborg University ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Aalborg University OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
# USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
# 
# The views and conclusions contained in the software and
# documentation are those of the authors and should not be interpreted
# as representing official policies, either expressed.

# linked_list.h test
add_executable(linked_list_test EXCLUDE_FROM_ALL
      linked_list_test.c
      )
add_test(linked_list_test ${CMAKE_CURRENT_BINARY_DIR}/linked_list_test)
add_dependencies(check linked_list_test)

# LinkedMap
add_library(linkedmap
	linkedmap.c
		)

# LinkedMap Test
add_executable(linkedmap_test EXCLUDE_FROM_ALL
      linkedmap_test.c
      linkedmap.c
      )
add_test(linkedmap_test ${CMAKE_CURRENT_BINARY_DIR}/linkedmap_test)
add_dependencies(check linkedmap_test)

# Trie
add_library(trie
      trie.c
      )

# Trie Test
add_executable(trie_test EXCLUDE_FROM_ALL
      trie_test.c
      trie.c
      )
add_test(trie_test ${CMAKE_CURRENT_BINARY_DIR}/trie_test)
add_dependencies(check trie_test)

