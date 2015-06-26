//
// Task.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project 		EMT-Task
//
// Created by 	Rei Vilo, Jun 23, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			Task.h and ReadMe.txt for references
//


// Library header
#include "Task.h"


// Code
/*
 UInt TaskKey;
 
 void disableTask()
 {
 TaskKey = Task_disable();
 }
 
 void restoreTask()
 {
 Task_restore(TaskKey);
 }
 */

Task::Task()
{
    ;
}

void Task::begin(void (*functionTask)(void), int8_t priority)
{
    Error_Block eb;
    Error_init(&eb);
    
    Task_Params params;
    Task_Params_init(&params);

    params.stackSize = 0x800;
    params.priority = priority;
    
    TaskHandle = Task_create((Task_FuncPtr)functionTask, &params, &eb);
    if (TaskHandle == NULL)
    {
        System_abort("Task create failed");
    }
}

//void Task::post()
//{
//    Task_post(TaskHandle);
//}

