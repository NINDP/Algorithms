#include <iostream>
#include <string>
#include "stack.h"

int getPriority(int op) {
    if (op == -1 || op == -2) {
        return 1;
    }
    if (op == -3) {
        return 2;
    }
    return 0;
}

int encodeOperator(char op) {
    if (op == '+') {
        return -1;
    }
    if (op == '-') {
        return -2;
    }
    if (op == '*') {
        return -3;
    }
    if (op == '(') {
        return -4;
    }
    if (op == ')') {
        return -5;
    }

    return 0;
}

void convertToRPN(const std::string& str, Stack *stack) {
    Stack *operators = stack_create();
    Stack *raw = stack_create();
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];

        if (isspace(c)) {
            continue;
        }

        if (isalnum(c)) {
            std::string num;
            while (i < str.length() && isalnum(str[i])) {
                num += str[i];
                i++;
            }
            i--;
            stack_push(raw, std::stoi(num));
        }
        else if (c == -4) {
            stack_push(operators, encodeOperator(c));
        } else if (c == -5) {
            while (!stack_empty(operators) && stack_get(operators) != -4) {
                stack_push(raw, stack_get(operators));
                stack_pop(operators);
            }
            if (!stack_empty(operators)) {
                stack_pop(operators);
            }
        } else {
            while (!stack_empty(operators) && getPriority(stack_get(operators)) >= getPriority(encodeOperator(c))) {
                stack_push(raw, stack_get(operators));
                stack_pop(operators);
            }
            stack_push(operators, encodeOperator(c));
        }

    }

    while (!stack_empty(operators)) {
        stack_push(raw, stack_get(operators));
        stack_pop(operators);
    }
    stack_delete(operators);

    while (!stack_empty(raw)) {
        stack_push(stack, stack_get(raw));
        stack_pop(raw);
    }
    stack_delete(raw);
}
