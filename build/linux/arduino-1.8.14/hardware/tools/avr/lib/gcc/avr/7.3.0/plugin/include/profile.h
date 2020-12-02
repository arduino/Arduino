/* Header file for minimum-cost maximal flow routines used to smooth basic
   block and edge frequency counts.
   Copyright (C) 2008-2017 Free Software Foundation, Inc.
   Contributed by Paul Yuan (yingbo.com@gmail.com)
       and Vinodha Ramasamy (vinodha@google.com).

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

#ifndef PROFILE_H
#define PROFILE_H

/* Additional information about edges. */
struct edge_profile_info
{
  unsigned int count_valid:1;

  /* Is on the spanning tree.  */
  unsigned int on_tree:1;

  /* Pretend this edge does not exist (it is abnormal and we've
     inserted a fake to compensate).  */
  unsigned int ignore:1;
};

#define EDGE_INFO(e)  ((struct edge_profile_info *) (e)->aux)

typedef struct gcov_working_set_info gcov_working_set_t;
extern gcov_working_set_t *find_working_set (unsigned pct_times_10);
extern void add_working_set (gcov_working_set_t *);

/* Smoothes the initial assigned basic block and edge counts using
   a minimum cost flow algorithm. */
extern void mcf_smooth_cfg (void);

extern gcov_type sum_edge_counts (vec<edge, va_gc> *edges);

extern void init_node_map (bool);
extern void del_node_map (void);

extern void get_working_sets (void);

/* Counter summary from the last set of coverage counts read by
   profile.c.  */
extern const struct gcov_ctr_summary *profile_info;

#endif /* PROFILE_H */
