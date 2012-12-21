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
