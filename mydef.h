/**
 * @file mydef.h
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Collection of functions and macros which are required multiple times 
 * @date 2019-06-23
 */
#include <stdio.h>
#include <stdlib.h>

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
 * @brief Max memory limit 32MB
 * 
 */
#define MEM_LIMIT_32MB struct rlimit r1 = {33554432, 33554432}

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