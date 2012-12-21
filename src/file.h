/**
*******************************************************************************
*  @file                  file.h
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
#ifndef __fop_h__
#define __fop_h__

#include "status.h"
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

/**
*******************************************************************************
*  @brief           Delete speficy file from file system.
*  @param           file: file path and file name
*  @return          return value: FAIL or SUCCESS
*  @par             Exceptions
*                   exceptions
*  @todo            <none>.
*  @see             <reference>
******************************************************************************/
status file_delete(const char* file);

/**
*******************************************************************************
*  @brief           Copy file from to.
*  @param           from: Source.
*  @param           to: Destination.
*  @return          return value: FAIL or SUCCESS
*  @par             Exceptions
*                   exceptions
*  @todo            <none>.
*  @see             <reference>
******************************************************************************/
status file_copy(const char* from, const char* to);

#endif