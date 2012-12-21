/**
*******************************************************************************
*  @file                  svn.h
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
#ifndef __svn_h__
#define __svn_h__

#include "status.h"
/**
*******************************************************************************
*  @struct t_svn_url                                               
*                                                                              
*  @brief  The structure holds the information about XXX svn url                  
*                                                                              
*  @param  protocol :                                                         
*          protocol header, such http, https.            
*                                                                              
*  @param  host :                                           
*          bost or domain name, xxx.xxx.com.            
*                                                                              
*  @param  svnroot :                                                      
*          svnroot for XXX SVN ROOT, default isource/root.      
*                                                                              
*  @param  extension :                                             
*          externsion for resource entenxtion.       
*                                                                              
******************************************************************************/
typedef struct t_svn_url
{
    char         *protocol;    
    char         *host;        
    char         *svnroot;     
    char         *extension;
}t_svn_url;

/**
*******************************************************************************
*  @brief           Check out files from SVN server.
*  @param           url:  URL to indicate the SVN resource.
*  @param           path: Local path to hold the checkout.
*  @return          return value: FAIL or SUCCESS
*  @code
*                   char *url = "https://inside.nokiasiemennetworks.com/trunk";
*                   char *path = "/tmp/trunk";
*                   status = svn_client_checkout(url, path);
*                   check(status, "Failed to checkout");
*  @endcode
*  @par             Exceptions
*                   exceptions
*  @todo            Use the official subversion api.
*  @see             <reference>
******************************************************************************/
status svn_client_checkout(const char* url, const char *path);

/**
*******************************************************************************
*  @brief           Export files from SVN server.
*  @param           url:  URL to indicate the SVN resource.
*  @param           path: Local path to hold the export.
*  @return          return value: FAIL or SUCCESS
*  @code
*                   char *url = "https://inside.nokiasiemennetworks.com/trunk";
*                   char *path = "/tmp/trunk";
*                   status = svn_client_export(url, path);
*                   check(status, "Failed to export");
*  @endcode
*  @par             Exceptions
*                   exceptions
*  @todo            Use the official subversion api.
*  @see             <reference>
******************************************************************************/
status svn_client_export(const char* url, const char *path);

/**
*******************************************************************************
*  @brief           Set the value of a property on files, dirs, or revisions.
*  @param           url:  URL to indicate the SVN resource.
*  @param           ps: propname.
*  @param           rev: operate on a revision property
*  @return          return value: FAIL or SUCCESS
*  @code
*                   status = svn_client_propset(url, path);
*                   check(status, "Failed to set");
*  @endcode
*  @par             Exceptions
*                   exceptions
*  @todo            Use the official subversion api.
*  @see             <reference>
******************************************************************************/
status svn_client_propset(char *url, char* ps, int rev);

/**
*******************************************************************************
*  @brief           Check files from SVN server.
*  @param           url:  URL to indicate the SVN resource.
*  @param           url_str: output url string.
*  @return          return value: FAIL or SUCCESS
*  @code
*                   t_svn_url url = {"xxx", "xxx", "xxx", "xxx"};
*                   char      url_str[1024];
*                   status = svn_create_url(url, url_str);
*                   check(status, "Failed to create");
*  @endcode
*  @par             Exceptions
*                   exceptions
*  @todo            Use the official subversion api.
*  @see             <reference>
******************************************************************************/
status svn_create_url(t_svn_url *url, char *url_str);
#endif