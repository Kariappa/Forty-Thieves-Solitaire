/**
 * \file Stack.h
 * \author Ali Kariapper
 * \brief Provides a generic template for a first in last out datatype
 
 */


#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>

/**
 * \brief Contains the function to be used with a stack (first-in-last-out data structure)
 */
template <class T>
class Stack {
    private:
        std:: vector<T> S;
    public:
        /**
         * \brief A default constructor for Stack, does not take any parameters
         *
         * \details Not in specification as it should not be called.
         */
        Stack();


        /**
         * \brief Constructs a new Stack instance
         * \param A sequence of items of a given type
         */
        Stack( std:: vector<T> S); 

        /**
         * \brief Adds a given item to a stack
         * \param element The item to be added to the top of a stack
         * \returns A new stack with the item added to it
         */
        Stack<T> push(T element);
        
        /**
         * \brief Removes an element at the top of a stack
         * \throws out_of_range exception if the stack is empty
         * \returns A new stack without the item that was popped off
         * 
         */
        Stack<T> pop();

        /**
         * \brief Returns the element at the top of the stack
         * \throws out_of_range exception if the stack is empty
         * \returns A top item of the stack
         * 
         */
        T top();
        
       /**
         * \brief Returns the size of the stack
         * \returns Size of the stack
         * 
         */        
        unsigned int size();
        
       /**
         * \brief Returns the sequence members in a stack.
         * \returns A copy of the sequence of elements
         */
        std::vector<T> toSeq();
};

#endif

