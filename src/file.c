/**
*******************************************************************************
*  @file                  file.c
*  @version               1.0.1
*  @date                  30-May-2012 10:12:51
*  @author                YangBiao
*  @brief                 SVN interface.
*
*  @par Description:
*         Functions to interact with svn.
*
*  @par Revision History
*         - 20120530  Yang.Biao Add commments for Doxygen documentatnion. 
*
******************************************************************************/
#include <stdio.h>
#include "file.h"
#include "sys.h"
#include "dbg.h"

static char cmd[1024];

status file_delete(const char* file)
{
    check(file, "NULL file name passed in.");

    sprintf(cmd,"%s %s", delete, file);
    return !sys_call_exec(cmd);
error:
    return FAIL;
}

status file_copy(const char* from, const char* to)
{
    check(from, "NULL file name passed in.");
    check(to, "NULL file name passed in.");

    sprintf(cmd,"%s %s %s", copy, from, to);
    return !sys_call_exec(cmd);
error:
    return FAIL;
}