#ifndef GUARD_mydef_h
#define GUARD_mydef_h

/**
 * @file mydef.h
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Collection of functions and macros which are required multiple times 
 * @date 2019-06-23
 */
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

/**
 * @brief macro for debug prints
 * 
 */
#define debug_print(fmt, ...) \
    do { if(DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while(0);

#define ps(x) puts(x)
#define pc(x) printf("%c ", x)
#define pi(x) printf("%d ", x)
#define pf(x) printf("%f ", x)

#define si(x) scanf("%d", &x)

#define Red "\033[0;31m"
#define Bold_Red "\033[1;31m"
#define Green "\033[0;32m"
#define Bold_Green "\033[1;32m"
#define Yellow "\033[0;33m"
#define Bold_Yellow "\033[01;33m"
#define Blue "\033[0;34m"
#define Bold_Blue "\033[1;34m"
#define Magenta "\033[0;35m"
#define Bold_Magenta "\033[1;35m"
#define Cyan "\033[0;36m"
#define Bold_Cyan "\033[1;36m"
#define Reset "\033[0m"
#define ResetColor() printf("\033[0m")

/**
 * @brief Max memory limit 2MB
 * 
 */
#define MEM_LIMIT_2MB struct rlimit r1 = {2097152, 2097152}

/**
 * @brief Max memory limit 4MB
 * 
 */
#define MEM_LIMIT_4MB struct rlimit r1 = {4194304, 4194304}

/**
 * @brief Max memory limit 8MB
 * 
 */
#define MEM_LIMIT_8MB struct rlimit r1 = {8388608, 8388608}

/**
 * @brief Max memory limit 16MB
 * 
 */
#define MEM_LIMIT_16MB struct rlimit r1 = {16777216, 16777216}

/**
 * @brief Max memory limit 32MB
 * 
 */
#define MEM_LIMIT_32MB struct rlimit r1 = {33554432, 33554432}

/**
 * @brief Max memory limit 128MB
 * 
 */
#define MEM_LIMIT_128MB struct rlimit r1 = {134217728, 134217728}

/**
 * @brief Max memory limit 512MB
 * 
 */
#define MEM_LIMIT_512MB struct rlimit r1 = {536870912, 536870912}

/**
 * @brief Max memory limit 1GB
 * 
 */
#define MEM_LIMIT_1GB struct rlimit r1 = {1073741824, 1073741824}

/**
 * @brief Max memory limit 4GB
 * 
 */
#define MEM_LIMIT_4GB struct rlimit r1 = {4294967296, 4294967296}

typedef enum bool{TRUE=1, FALSE=0}bool;

/**
 * @brief Prints out of range error on stderr
 * 
 */
void printOutOfRangeError();
/**
 * @brief Prints memory not available error on stderr
 * 
 */
void printMemNotAvailable();

void printOverflowError(char *);
void printUnderflowError(char *);
void printError(char *);

#endif