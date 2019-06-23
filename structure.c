/**
 * @file structure.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Testing function pointer in structures (object-oriented implementation)
 * @date 2019-06-23
 */

#include "mydef.h"

/**
 * @brief prints gives string
 * 
 * @param name character pointer
 */
void hello(char *name)
{
    printf("Hello %s!\n", name);
}

/**
 * @brief Student structure
 * 
 */
typedef struct Student
{
    char *name;
    int rollno;
    void (*p)(char *);
} Student;

int main(int argc, char const *argv[])
{
    Student s = {"ajit", 9, hello};
    s.p(s.name);
    return 0;
}
