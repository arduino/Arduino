/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       ListP.h
 *
 *  @brief      Linked List interface for the RTOS Ports Interface
 *
 *  This module provides simple doubly-link list implementation. There are two
 *  main structures:
 *     - ::ListP_List: The structure that holds the start of a linked list. There
 *  is no API to create one. It is up to the driver to provide the structure
 *  itself.
 *     - ::ListP_Elem: The structure that must be in the structure that is placed
 *  onto a linked list. Generally it is the first field in the structure. For
 *  example:
 *  @code
 *  typedef struct MyStruct {
 *      ListP_Elem elem;
 *      void *buffer;
 *  } MyStruct;
 *  @endcode
 *
 *  The following shows how the link list with three elements.
 *
 *  @code
 *  + denotes null-terminated
 *          _______        _______        _______      _______
 *         |_______|----->|_______|----->|_______|--->|_______|--//---,
 *    ,----|_______|    ,-|_______|<-----|_______|<---|_______|<-//-, +
 *    |      List       +   elem           elem          elem       |
 *    |_____________________________________________________________|
 *  @endcode
 *
 *  The APIs ::ListP_get, ::ListP_put, and ::ListP_putHead are
 *  atomic. The other APIs are not necessarily atomic. In other words, when
 *  traversing a linked list, it is up to the application to provide
 *  thread-safety (e.g. HwiP_disable/restore or MutexP_pend/post).
 *
 *  Initializing and adding an element to the tail and removing it
 *  @code
 *  typedef struct MyStruct {
 *      ListP_Elem elem;
 *      void *buffer;
 *  } MyStruct;
 *
 *  ListP_List list;
 *  MyStruct foo;
 *  MyStruct *bar;
 *
 *  ListP_clearList(&list);
 *  ListP_put(&list, (ListP_Elem *)&foo);
 *  bar = (MyStruct *)ListP_get(&list);
 *  @endcode
 *
 *  The ::ListP_put and ::ListP_get APIs are used to maintain a first-in first-out
 *  (FIFO) linked list.
 *
 *  The ::ListP_putHead and ::ListP_get APIs are used to maintain a last-in first-out
 *  (LIFO) linked list.
 *
 *  Traversing a list from head to tail. Note: thread-safety calls are
 *  not shown here.
 *  @code
 *  ListP_List list;
 *  ListP_Elem *temp;
 *
 *  for (temp = ListP_head(&list); temp != NULL; temp = ListP_next(temp)) {
 *       printf("address = 0x%x\n", temp);
 *  }
 *  @endcode
 *
 *  Traversing a list from tail to head. Note: thread-safety calls are
 *  not shown here.
 *  @code
 *  ListP_List list;
 *  ListP_Elem *temp;
 *
 *  for (temp = ListP_tail(&list); temp != NULL; temp = ListP_prev(temp)) {
 *       printf("address = 0x%x\n", temp);
 *  }
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_ports_ListP__include
#define ti_drivers_ports_ListP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct ListP_Elem {
    struct ListP_Elem *next;
    struct ListP_Elem *prev;
} ListP_Elem;

typedef struct ListP_List {
    ListP_Elem *head;
    ListP_Elem *tail;
} ListP_List;

/*!
 *  @brief  Function to initialize the contents of a ListP_List
 *
 *  @param  list Pointer to a ListP_List structure that will be use to
 *               maintain a linked list
 */
extern void ListP_clearList(ListP_List *list);

/*!
 *  @brief  Function to test whether a linked list is empty
 *
 *  @param  list A pointer to a linked list
 *
 *  @return true if empty, false if not empty
 */
extern bool ListP_empty(ListP_List *list);

/*!
 *  @brief  Function to atomically get the first elem in a linked list
 *
 *  @param  list A pointer to a linked list
 *
 *  @return Pointer the first elem in the linked list or NULL if empty
 */
extern ListP_Elem *ListP_get(ListP_List *list);

/*!
 *  @brief  Function to return the head of a linked list
 *
 *  This function does not remove the head, it simply returns a pointer to
 *  it. This function is typically used when traversing a linked list.
 *
 *  @param  list A pointer to the linked list
 *
 *  @return Pointer to the first elem in the linked list or NULL if empty
 */
extern ListP_Elem *ListP_head(ListP_List *list);

/*!
 *  @brief  Function to insert an elem into a linked list
 *
 *  @param  list A pointer to the linked list
 *
 *  @param  newElem New elem to insert
 *
 *  @param  curElem Elem to insert the newElem in front of.
 *          This value cannot be NULL.
 */
extern void ListP_insert(ListP_List *list, ListP_Elem *newElem,
                         ListP_Elem *curElem);

/*!
 *  @brief  Function to return the next elem in a linked list
 *
 *  This function does not remove the elem, it simply returns a pointer to
 *  next one. This function is typically used when traversing a linked list.
 *
 *  @param  elem Elem in the list
 *
 *  @return Pointer to the next elem in linked list or NULL if at the end
 */
extern ListP_Elem *ListP_next(ListP_Elem *elem);

/*!
 *  @brief  Function to return the prev elem in a linked list
 *
 *  This function does not remove the elem, it simply returns a pointer to
 *  prev one. This function is typically used when traversing a linked list.
 *
 *  @param  elem Elem in the list
 *
 *  @return Pointer to the prev elem in linked list or NULL if at the beginning
 */
extern ListP_Elem *ListP_prev(ListP_Elem *elem);

/*!
 *  @brief  Function to atomically put an elem onto the end of a linked list
 *
 *  @param  list A pointer to the linked list
 *
 *  @param  elem Element to place onto the end of the linked list
 */
extern void ListP_put(ListP_List *list, ListP_Elem *elem);

/*!
 *  @brief  Function to atomically put an elem onto the head of a linked list
 *
 *  @param  list A pointer to the linked list
 *
 *  @param  elem Element to place onto the beginning of the linked list
 */
extern void ListP_putHead(ListP_List *list, ListP_Elem *elem);

/*!
 *  @brief  Function to remove an elem from a linked list
 *
 *  @param  list A pointer to the linked list
 *
 *  @param  elem Element to be removed from a linked list
 */
extern void ListP_remove(ListP_List *list, ListP_Elem *elem);

/*!
 *  @brief  Function to return the tail of a linked list
 *
 *  This function does not remove the tail, it simply returns a pointer to
 *  it. This function is typically used when traversing a linked list.
 *
 *  @param  list A pointer to the linked list
 *
 *  @return Pointer to the last elem in the linked list or NULL if empty
 */
extern ListP_Elem *ListP_tail(ListP_List *list);


#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_ports_ListP__include */
