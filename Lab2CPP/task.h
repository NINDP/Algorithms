#ifndef ALGORITHMS_TASK_H
#define ALGORITHMS_TASK_H
#include <string>
#include "stack.h"

int getPriority(char op);

void convertToRPN(const std::string& str, Stack *stack);

#endif
