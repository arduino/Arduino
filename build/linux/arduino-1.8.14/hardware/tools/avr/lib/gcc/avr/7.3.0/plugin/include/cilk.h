/* This file is part of the Intel(R) Cilk(TM) Plus support
   This file contains Cilk Support files.
   Copyright (C) 2013-2017 Free Software Foundation, Inc.
   Contributed by Balaji V. Iyer <balaji.v.iyer@intel.com>,
                  Intel Corporation

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef GCC_CILK_H
#define GCC_CILK_H

/* Frame status bits known to compiler.  */
#define CILK_FRAME_UNSYNCHED 0x02
#define CILK_FRAME_DETACHED  0x04
#define CILK_FRAME_EXCEPTING 0x10
#define CILK_FRAME_VERSION   (1 << 24)

enum cilk_tree_index  {
/* All the built-in functions for Cilk keywords.  */
  CILK_TI_F_WORKER = 0,               /* __cilkrts_get_worker ().  */
  CILK_TI_F_SYNC,                     /* __cilkrts_sync ().  */
  CILK_TI_F_DETACH,                   /* __cilkrts_detach (...).   */
  CILK_TI_F_ENTER,                    /* __cilkrts_enter_frame (...).  */
  CILK_TI_F_ENTER_FAST,               /* __cilkrts_enter_frame_fast (.).  */
  CILK_TI_F_LEAVE,                    /* __cilkrts_leave_frame (...).  */
  CILK_TI_F_POP,                      /* __cilkrts_pop_frame (...).  */
  CILK_TI_F_RETHROW,                  /* __cilkrts_rethrow (...).  */
  CILK_TI_F_SAVE_FP,                  /* __cilkrts_save_fp_ctrl_state (...).  */
  CILK_TI_F_LOOP_32,                  /* __cilkrts_cilk_for_32 (...).  */
  CILK_TI_F_LOOP_64,                  /* __cilkrts_cilk_for_64 (...).  */

  /* __cilkrts_stack_frame struct fields.  */
  CILK_TI_FRAME_FLAGS,                /* stack_frame->flags.  */
  CILK_TI_FRAME_PARENT,               /* stack_frame->parent.  */
  CILK_TI_FRAME_WORKER,               /* stack_frame->worker.  */
  CILK_TI_FRAME_EXCEPTION,            /* stack_frame->except_data.  */
  CILK_TI_FRAME_CONTEXT,              /* stack_frame->context[4].  */
  CILK_TI_FRAME_PEDIGREE,             /* stack_frame->pedigree.  */

  /* __cilkrts_worker struct fields.  */
  CILK_TI_WORKER_CUR,                 /* worker->current_stack_frame.  */
  CILK_TI_WORKER_TAIL,                /* worker->tail.  */
  CILK_TI_WORKER_PEDIGREE,            /* worker->pedigree.  */

  /* __cilkrts_pedigree struct fields.  */
  CILK_TI_PEDIGREE_RANK,              /* pedigree->rank.  */
  CILK_TI_PEDIGREE_PARENT,            /* pedigree->parent.  */
  
  /* Types.  */
  CILK_TI_FRAME_TYPE,                 /* struct __cilkrts_stack_frame.  */
  CILK_TI_FRAME_PTR,                  /* __cilkrts_stack_frame *.  */
  CILK_TI_WORKER_TYPE,                /* struct __cilkrts_worker.  */
  CILK_TI_PEDIGREE_TYPE,              /* struct __cilkrts_pedigree.  */
  CILK_TI_MAX
};

extern GTY (()) tree cilk_trees[CILK_TI_MAX];

#define cilk_worker_fndecl            cilk_trees[CILK_TI_F_WORKER]
#define cilk_sync_fndecl              cilk_trees[CILK_TI_F_SYNC]
#define cilk_synched_fndecl           cilk_trees[CILK_TI_F_SYNCED]
#define cilk_detach_fndecl            cilk_trees[CILK_TI_F_DETACH]
#define cilk_enter_fndecl             cilk_trees[CILK_TI_F_ENTER]
#define cilk_enter_fast_fndecl        cilk_trees[CILK_TI_F_ENTER_FAST]
#define cilk_leave_fndecl             cilk_trees[CILK_TI_F_LEAVE]
#define cilk_rethrow_fndecl           cilk_trees[CILK_TI_F_RETHROW]
#define cilk_pop_fndecl               cilk_trees[CILK_TI_F_POP]
#define cilk_save_fp_fndecl           cilk_trees[CILK_TI_F_SAVE_FP]
#define cilk_for_32_fndecl            cilk_trees[CILK_TI_F_LOOP_32]
#define cilk_for_64_fndecl            cilk_trees[CILK_TI_F_LOOP_64]

#define cilk_worker_type_fndecl       cilk_trees[CILK_TI_WORKER_TYPE]
#define cilk_frame_type_decl          cilk_trees[CILK_TI_FRAME_TYPE]
#define cilk_frame_ptr_type_decl      cilk_trees[CILK_TI_FRAME_PTR]
#define cilk_pedigree_type_decl       cilk_trees[CILK_TI_PEDIGREE_TYPE]

extern void expand_builtin_cilk_detach (tree);
extern void expand_builtin_cilk_pop_frame (tree);
extern tree cilk_arrow (tree, int, bool);
extern tree cilk_dot (tree, int, bool);
extern void cilk_init_builtins (void);
extern void gimplify_cilk_sync (tree *, gimple_seq *);
extern tree cilk_call_setjmp (tree);

/* Returns true if Cilk Plus is enabled and if F->cilk_frame_decl is not
   NULL_TREE.  */

inline bool
fn_contains_cilk_spawn_p (function *f)
{
  return (flag_cilkplus 
	  && (f->calls_cilk_spawn || f->cilk_frame_decl != NULL_TREE));
}

#endif
