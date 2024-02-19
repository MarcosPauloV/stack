#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef int Data;

struct Cell {
    int count;
    Data item;
    Cell *nextCell;
};

void StackConstructor(Cell &stack);
void StackDestructor(Cell &stack);
int StackSize(Cell $stack);
bool StackAdd(Cell element);
bool StackPop(Cell &element);
bool StackFirstItem(Cell &element);

#endif // PILHA_H_INCLUDED
