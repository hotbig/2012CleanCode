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

/**
*******************************************************************************
* @def    Global definition to cross platfrom
* 
* @param  slash : File system directory slash
* @param  delete: Shell command to delete file.
* @param  copy:   Shell command to copy file.
******************************************************************************/
#if defined(UNIX) || defined(__CYGWIN__)
static const char slash[]  = "/";
static const char delete[] = "rm -f";
static const char copy[]   = "cp";
static const char null[]   = "> /dev/null 2<&1";
#else
static const char slash[]  = "\\";
static const char delete[] = "del";
static const char copy[]   = "copy";
static const char null[]   = "> /dev/null 2<&1";
#endif

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
