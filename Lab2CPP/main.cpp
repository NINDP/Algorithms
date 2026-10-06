#include <iostream>
#include "stack.h"
#include "task.h"
#include <string>


int main() {
    std::string expr;

    std::getline(std::cin, expr);

    Stack *stack = stack_create();
    convertToRPN(expr, stack);
    generateAssembler(stack);
    return 0;
}
