/* Declarations and definitions dealing with attribute handling.
   Copyright (C) 2013-2017 Free Software Foundation, Inc.

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

#ifndef GCC_ATTRIBS_H
#define GCC_ATTRIBS_H

extern const struct attribute_spec *lookup_attribute_spec (const_tree);
extern void init_attributes (void);

/* Process the attributes listed in ATTRIBUTES and install them in *NODE,
   which is either a DECL (including a TYPE_DECL) or a TYPE.  If a DECL,
   it should be modified in place; if a TYPE, a copy should be created
   unless ATTR_FLAG_TYPE_IN_PLACE is set in FLAGS.  FLAGS gives further
   information, in the form of a bitwise OR of flags in enum attribute_flags
   from tree.h.  Depending on these flags, some attributes may be
   returned to be applied at a later stage (for example, to apply
   a decl attribute to the declaration rather than to its type).  */
extern tree decl_attributes (tree *, tree, int);

extern bool cxx11_attribute_p (const_tree);
extern tree get_attribute_name (const_tree);
extern void apply_tm_attr (tree, tree);
extern tree make_attribute (const char *, const char *, tree);

extern struct scoped_attributes* register_scoped_attributes (const struct attribute_spec *,
							     const char *);

#endif // GCC_ATTRIBS_H
