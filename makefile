# C Preprocessor Flags #
###################################################################
CPPFLAGS = -DUNIX
ifeq ($(test),1)
CPPFLAGS += -Dmain=mock_main
CPPFLAGS += -Dsystem=mock_system
CPPFLAGS += -Dexit=mock_exit
CPPFLAGS += -Dfopen=mock_fopen
CPPFLAGS += -Dfclose=mock_fclose
CPPFLAGS += -Dtmpnam=mock_tmpnam
CPPFLAGS += -Dprintf=mock_printf
CPPTEST = -DUNIX
CPPTEST += -Dtest_main=main
endif

ifeq ($(release),1)
CPPFLAGS += -Dxxxx_main=main
#CPPFLAGS += -DNDEBUG
endif

# C Compiler Flags #
###################################################################
CCFLAGS  = -c

ifeq ($(test),1)
CCFLAGS += -g
endif

# Source Files #
###################################################################
source = ./src/svn.c
source += ./src/file.c


ifeq ($(test),1)
source += ./test/mock.c
endif

objects = $(source:.c=.o)

# Project Dependencies #
###################################################################
# Removed for GitHub#