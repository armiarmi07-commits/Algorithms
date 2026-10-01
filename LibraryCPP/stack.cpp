#include "stack.h"
#include "vector.h"
struct Stack
{
    Vector *vector;
};

Stack *stack_create()
{
    Stack *stack = new Stack();
    stack->vector = vector_create();
    return stack;
}

void stack_delete(Stack *stack)
{
    // TODO: free stack elements
    if (stack) {
        vector_delete(stack->vector);
        delete stack;
    }

}

void stack_push(Stack *stack, Data data)
{
    if (!stack) {
        return;
    }
    size_t size = vector_size(stack->vector);
    vector_resize(stack->vector,size+1);
    vector_set(stack->vector,size,data);
}

Data stack_get(const Stack *stack)
{
    if (!stack) {
        return "";
    }
    size_t size = vector_size(stack->vector);
    if (size == 0) {
        return "";
    }
    return vector_get(stack->vector, size - 1);
}

void stack_pop(Stack *stack)
{
    if (!stack) {
        return;
    }
    size_t size = vector_size(stack->vector);
    if (size == 0) {
        return;
    }
    if (size > 0) {
        vector_resize(stack->vector,size-1);
    }
}

bool stack_empty(const Stack *stack)
{
    if (!stack) {
        return true;
    }
    return vector_size(stack->vector) == 0;
}
