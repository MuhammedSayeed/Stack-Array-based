#include <iostream>
using namespace std;

class Stack
{
private:
    int *data_list;
    int top_index;
    int initial_size;
    int current_size;

public:
    Stack()
    {
        this->initial_size = 5;
        this->data_list = new int[this->initial_size];
        this->current_size = this->initial_size;
        this->top_index = -1;
    }
    void resizeOrNot()
    {
        if (this->top_index < this->current_size - 1)
        {
            cout << "stack will not be resized" << endl;
            return;
        }
        cout << "stack will be resized" << endl;
        int *newArray = new int[current_size + initial_size];
        copy(this->data_list, this->data_list + this->current_size, newArray);
        this->current_size += this->initial_size;
        delete[] this->data_list;
        this->data_list = newArray;
    }

    void push(int _data)
    {
        this->resizeOrNot();
        this->data_list[++this->top_index] = _data;
    }

    int peek()
    {
        if (this->top_index != -1)
        {
            return this->data_list[this->top_index];
        }
        cout << "stack is empty" << endl;
        return 0;
    }
    int pop()
    {
        if (this->top_index == -1)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        int head_data = this->data_list[this->top_index];
        this->data_list[this->top_index] = 0;
        this->top_index--;
        return head_data;
    }

    bool isEmpty()
    {
        if (this->top_index == -1){
            return true;
        }
        return false;
    }

    int size()
    {
        return this->top_index + 1;
    }

    void print()
    {

        for (int i = this->top_index; i >= 0; i--)
        {
            cout << this->data_list[i] << " -> ";
        }
        cout << "NULL";
        cout << endl;
    }
};
int main()
{
    Stack *stack = new Stack();

    cout<<stack->isEmpty()<<endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->print();
    
    
    return 0;
};