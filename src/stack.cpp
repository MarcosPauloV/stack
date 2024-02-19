#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Cell *top;

void StackConstructor(Cell *stack){
    stack = NULL;
    stack->count = 0;
}

void StackDestructor(Cell *stack){
    Cell *temp;

    while(stack != NULL) {
        temp = stack;
        stack = stack -> nextCell;

        temp->nextCell = NULL; 
        free(temp); 
    }

    stack -> count = 0;
}

int StackSize(Cell *stack){
    return stack -> count;
}

bool StackAdd(Data element, Cell *stack){
    Cell *newCell;

    if((newCell = (Cell *) malloc(sizeof(Cell)))==NULL){
        return false;
    } else {
        newCell->item = element;
        newCell->nextCell = stack; 
        stack = newCell;
        stack->count++;
        return true;
    }
}

bool StackPop(Data &element, Cell *stack){
    if(StackSize(stack) != 0){
        Cell *temp = stack;
        stack = stack->nextCell;
        element = stack->item;
        temp->nextCell = NULL;
        free(temp);
        stack->count--;
        return true;
    } else {
        return false;
    }
}

bool StackFirstItem(Data &element, Cell *stack){
    if(StackSize(stack) != 0){
        element = stack->item;
        return true;
    } else {    
        return false;
    }
}