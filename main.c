#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* Stack;

Stack top1;
Stack top2;
Stack topResult;

//this function pushes the digit in Stack 1. (first number be inside this stack)
void pushStack1(int digit){
    struct  Node* node = malloc(sizeof(struct Node));
    node->data = digit;
    node->next = NULL;
    if(top1 == NULL){
        top1 = node;
    }else{
        node->next = top1;
        top1 = node;
    }
}

//pops the top digit from the stack 1.
int popStack1(){
    if(top1 != NULL){
        struct Node* node = top1;
        top1 = top1->next;
        int data = node->data;
        free(node);
        return data;
    }else{
        return NULL;
    }
}

//pops the top digit from the stack 2.
int popStack2(){
    if(top2 != NULL){
        struct Node* node = top2;
        top2 = top2->next;
        int data = node->data;
        free(node);
        return data;
    }else{
        return NULL;
    }
}

//this function pushes the digit in Stack 2. (second number be inside this stack)
void pushStack2(int digit){
    struct  Node* node = malloc(sizeof(struct Node));
    node->data = digit;
    node->next = NULL;
    if(top2 == NULL){
        top2 = node;
    }else{
        node->next = top2;
        top2 = node;
    }
}

//this function pushes the digit in the Results Stack
void pushResultStack(int digit){
    struct  Node* node = malloc(sizeof(struct Node));
    node->data = digit;
    node->next = NULL;
    if(topResult == NULL){
        topResult = node;
    }else{
        node->next = topResult;
        topResult = node;
    }
}

void display();

void addLargeNumbers(const char* num1, const char* num2){
    int i = 0, result = 0;
    for(i = 0; i < strlen(num1); i++){
        int digit = num1[i] - '0';
        pushStack1(digit);
    }
    for(i = 0; i < strlen(num2); i++){
        int digit = num2[i] - '0';
        pushStack2(digit);
    }
    while (top1 != NULL || top2 != NULL){
        int digit1 = 0,digit2 = 0;
        if(top1 != NULL){
            digit1 = popStack1();
        }
        if(top2 != NULL){
            digit2 = popStack2();
        }
        result = result + digit1 + digit2;
        int unitDigit = result % 10;
        pushResultStack(unitDigit);
        result = result/10;
    }
    display();
}

void display(){
    if(topResult == NULL){
    }
    struct Node* temp = topResult;
    while (temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

/*
 * This function is used to clear all the stacks and free the nodes so that can be used for next numbers.
 */
void freeResources(){
    if(topResult != NULL){
        while (topResult != NULL){
            struct Node* temp = topResult;
            free(temp);
            topResult = topResult->next;
        }
    }
    if(top1 != NULL){
        while (top1 != NULL){
            struct Node* temp = top1;
            free(temp);
            top1 = top1->next;
        }
    }
    if(top2 != NULL){
        while (top2 != NULL){
            struct Node* temp = top2;
            free(temp);
            top2 = top2->next;
        }
    }
}
int main() {
    char* num1 = "592";
    char* num2 = "3784";
    addLargeNumbers(num1,num2);
    freeResources();
    char* largeNum1 = "123456789123456789123456789";
    char* largeNum2 = "1234567890123456789012345678901234567890";
    printf("\n");
    addLargeNumbers(largeNum1,largeNum2);
    freeResources();
    //add some big number here and call add large number and submit.
    return 0;
}