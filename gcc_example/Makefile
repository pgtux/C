#################################################################################
############################# README ############################################
#################################################################################
# Names separated with '=' sign are variables
# In our case,
#
# CC - Type of the compiler i.e. 'gcc'
# CFLAGS - Flags specified for compilation
# TFLAGS - See below 'contional directive'
# BIN_PATH - Binary files (ELF/Executable files stored under this path. This is
#	     to make sure our source path clean
# 'Conditional directive':
# - To save the intermediate/staging files i.e. (save pre-processed, assembled and
#   compiled files)
# - To control this option 'TEMP' flag is used
# - To enable this flag use 'make -e TEMP=1'
#################################################################################
CC=gcc
CFLAGS=-Wall -Wextra -g3
#TFLAGS=-save-temps=obj
BIN_PATH=./bin

ifeq ($(TEMP), 1)
TFLAGS=-save-temps=obj
else
TFLAGS=
endif

all: hello

hello: 
	$(CC) $(CFLAGS) $(TFLAGS) hello.c -o $(BIN_PATH)/hello

clean:
	rm -rf $(BIN_PATH)/hello.*[!c] $(BIN_PATH)/hello
