/**
 * @file structure.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Testing function pointer in structures (object-oriented implementation)
 * @date 2019-06-23
 */

#ifndef __MY_LIB
    #define __MY_LIB
    #include "mydef.h"
#endif
#include "stack.h"

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

void printStudent(Student s)
{
    s.p = hello;
    s.p(s.name);
}

void printStudentRef(Student *s)
{
    s->p = hello;
    s->p(s->name);
}

int main(int argc, char const *argv[])
{
    Student s[2] = {{"ajit", 28, hello}, {"uday", 10, hello}};
    Student *p;
    stackNode *n;
    // s.p(s.name);
    printStudent(s[0]);    // pass by value
    // printStudentRef(&(Student *){"Uday", 10, NULL});
    printStudentRef(&s[1]); // pass by reference
    stackNode *TOP = NULL;
    
    TOP = push((void *)&s[0], "N", TOP);
    printf("%p\n", TOP);
    printf("Elements in stack %d\n", totalElementsInStack(TOP));
    
    TOP = push((void *)&s[1], "N", TOP);
    printf("%p\n", TOP);
    printf("Elements in stack %d\n", totalElementsInStack(TOP));

    n = pop(&TOP);
    printf("%p\n", TOP);
    p = (Student *) n->data_ptr;
    free(n);
    printStudentRef(p);
    printf("Elements in stack %d\n", totalElementsInStack(TOP));

    n = pop(&TOP);
    printf("%p\n", TOP);
    p = (Student *) n->data_ptr;
    free(n);
    printStudentRef(p);
    printf("Elements in stack %d\n", totalElementsInStack(TOP));
    
    return 0;
}
