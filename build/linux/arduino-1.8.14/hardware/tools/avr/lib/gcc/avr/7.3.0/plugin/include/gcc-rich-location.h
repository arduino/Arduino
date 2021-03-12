/* Declarations relating to class gcc_rich_location
   Copyright (C) 2014-2017 Free Software Foundation, Inc.

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

#ifndef GCC_RICH_LOCATION_H
#define GCC_RICH_LOCATION_H

/* A gcc_rich_location is libcpp's rich_location with additional
   helper methods for working with gcc's types.  */
class gcc_rich_location : public rich_location
{
 public:
  /* Constructors.  */

  /* Constructing from a location.  */
  gcc_rich_location (source_location loc) :
    rich_location (line_table, loc) {}

  /* Methods for adding ranges via gcc entities.  */
  void
  add_expr (tree expr);

  void
  maybe_add_expr (tree t);

  void add_fixit_misspelled_id (location_t misspelled_token_loc,
				tree hint_id);
};

#endif /* GCC_RICH_LOCATION_H */
