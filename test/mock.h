/**
*******************************************************************************
*  @file                  mock.h
*  @version               1.0.1
*  @date                  30-May-2012 10:12:51
*  @author                YangBiao
*  @brief                 mock interface.
*
*  @par Description:
*         Functions to interact with svn.
*
*  @par Revision History
*         - 20120530  Yang.Biao Add commments for Doxygen documentatnion. 
*
******************************************************************************/

/* stdlib.h */
int   mock_system(const char *command);

/* stdlib.h */
void  mock_exit(int status);

/* stdlib.h */
char* mock_tmpnam(char *str );

/* stdio.h */
FILE* mock_fopen(const char * filename, const char * mode);

/* stdio.h */
int   mock_fclose(FILE * stream);

int   mock_printf ( const char * format, ...);

