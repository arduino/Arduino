/* Find near-matches for identifiers.
   Copyright (C) 2015-2017 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_SPELLCHECK_TREE_H
#define GCC_SPELLCHECK_TREE_H

#include "spellcheck.h"

/* spellcheck-tree.c  */

extern edit_distance_t
levenshtein_distance (tree ident_s, tree ident_t);

extern tree
find_closest_identifier (tree target, const auto_vec<tree> *candidates);

/* Specialization of edit_distance_traits for identifiers.  */

template <>
struct edit_distance_traits<tree>
{
  static size_t get_length (tree id)
  {
    gcc_assert (TREE_CODE (id) == IDENTIFIER_NODE);
    return IDENTIFIER_LENGTH (id);
  }

  static const char *get_string (tree id)
  {
    gcc_assert (TREE_CODE (id) == IDENTIFIER_NODE);
    return IDENTIFIER_POINTER (id);
  }
};

/* Specialization of edit_distance_traits for preprocessor macros.  */

template <>
struct edit_distance_traits<cpp_hashnode *>
{
  static size_t get_length (cpp_hashnode *hashnode)
  {
    return hashnode->ident.len;
  }

  static const char *get_string (cpp_hashnode *hashnode)
  {
    return (const char *)hashnode->ident.str;
  }
};

/* Specialization of best_match<> for finding the closest preprocessor
   macro to a given identifier.  */

class best_macro_match : public best_match<tree, cpp_hashnode *>
{
 public:
  best_macro_match (tree goal, edit_distance_t best_distance_so_far,
		    cpp_reader *reader);
};

#endif  /* GCC_SPELLCHECK_TREE_H  */
