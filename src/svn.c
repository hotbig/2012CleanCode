/**
*******************************************************************************
*  @file                  svn.c
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
#include "svn.h"
#include "sys.h"
#include "dbg.h"

/**
******************************************************************************
* Global definitions for svn comamnds
*****************************************************************************/
static const char export[] = "svn --non-interactive export --force";
static const char checkout[] = "svn --non-interactive co";
static const char propset[] = "svn --non-interactive ps %s --revprop -r %d T %s";
static char  cmd_str_buf[1024];

/**
******************************************************************************
* Implementation for public interfaces.
*****************************************************************************/
status svn_client_checkout(const char* url, const char *path)
{
    check(url, "Null Url Pointer passed in");
    check(path, "Null Path Pointer passed in");

    sprintf(cmd_str_buf, "%s %s %s", checkout, url, path);

    return !(sys_call_exec(cmd_str_buf));
error:
    return FAIL;
}

status svn_client_export(const char* url, const char *path)
{
    check(url, "Null Url Pointer passed in");

    sprintf(cmd_str_buf,"%s %s", export, url);
    if(path != NULL)
        sprintf(cmd_str_buf, "%s %s", cmd_str_buf, path);
    
    return !(sys_call_exec(cmd_str_buf));
error:
    return FAIL;
}

status svn_client_propset(char *url, char* ps, int rev)
{
    check(url, "Null Url Pointer passed in.");
    check(ps, "Null PS Pointer passed in.");

    sprintf(cmd_str_buf, propset, ps , rev, url);

    return !(sys_call_exec(cmd_str_buf));
error:
    return FAIL;
}

status svn_create_url(t_svn_url *url, char *out)
{
    check(url, "Null Url Pointer passed in");
    check(out, "Null Out Pointer passed in");

    sprintf(out, "%s%s/%s/%s", 
            url->protocol,
            url->host,
            url->svnroot,
            url->extension);

    return SUCCESS;
error:
    return FAIL;
}

