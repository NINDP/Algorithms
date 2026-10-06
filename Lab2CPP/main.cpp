#include <iostream>
#include "stack.h"
#include "task.h"
#include <string>


int main() {
    std::string expr;

    std::getline(std::cin, expr);

    Stack *stack = stack_create();

    convertToRPN(expr, stack);

    while (!stack_empty(stack)) {
        std::cout << stack_get(stack) << ' ';
        stack_pop(stack);
    }
    return 0;
}
