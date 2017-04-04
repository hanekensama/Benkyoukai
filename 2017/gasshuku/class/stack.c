#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node_t;

typedef struct Stack {
  Node_t* top;
  unsigned int size;
} Stack_t;

void push(Stack_t* stack, int value);
int pop(Stack_t* stack);

int main() {
  Stack_t stack = {top:NULL, size:0};

  push(&stack, 1);
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));

  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));

  stack.size++; // こんなことができてしまう！
  printf("%d\n", pop(&stack)); // エラー発生

  return 0;
  
}

void push(Stack_t* stack, int value) {
  Node_t* new = (Node_t*)malloc(sizeof(Node_t));
  new->value = value;
  new->next = stack->top;
  stack->top = new;
  stack->size++;
}

int pop(Stack_t* stack) {
  Node_t *delete;
  int value;

  if (stack->size == 0)
    return 0;
  
  delete = stack->top;
  value = delete->value;
  stack->top = delete->next;

  free(delete);
  stack->size--;
  return value;
}
