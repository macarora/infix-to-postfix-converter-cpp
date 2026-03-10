#include "infix_to_postfix_converter.h"
#include "lstack.h"
#include "lqueue.h"
#include <iostream>

LStack<char> opStack;
LQueue<char> postFixQueue;

infix_to_postfix_converter::infix_to_postfix_converter(std::string &input) // construcotr and take input for the convertor
{
    infix = input;
    postfix = convert_to_postfix(input);
}

infix_to_postfix_converter::~infix_to_postfix_converter() // destructor
{
}

const std::string &infix_to_postfix_converter::get_infix() const
{
    return infix;
}

const std::string &infix_to_postfix_converter::get_postfix() const
{
    return postfix;
}

int infix_to_postfix_converter::precedence(char op) const
{
    if (op == '(' || op == ')')
    {
        return 1;
    }

    if (op == '+' || op == '-')
    {
        return 2;
    }

    else if (op == '*' || op == '/')
    {
        return 3;
    }

    return 0;
}

std::string infix_to_postfix_converter ::convert_to_postfix(std::string &input)
{

    for (char sym : input)
    {
        if (isspace(sym))
        { // ignore space
            continue;
        }

        if (isalnum(sym))
        {

            postFixQueue.enqueue(sym); // append to queue
        }

        // check for ( & )
        else if (sym == '(')
        {
            opStack.push(sym);
        }

        else if (sym == ')')
        {
            while (!opStack.empty() && opStack.top() != '(')
            {
                postFixQueue.enqueue(opStack.top());
                opStack.pop();
            }

            if (!opStack.empty() && opStack.top() == '(')
            {
                opStack.pop();
            }
        }

        // check for operator and operand
        else if (sym == '*' || sym == '/' || sym == '+' || sym == '-')

        {
            while (!opStack.empty() && opStack.top() != '(' && precedence(sym) >= precedence(opStack.top()))
            {
                postFixQueue.enqueue(opStack.top());
                opStack.pop();
            }

            opStack.push(sym);
        }

        else
        {
            throw std::invalid_argument("Check the Operator Symbol .Not accepted other than '*,/,+,/' ");
        }
    }
    while (!opStack.empty())
    {
        if (opStack.top() == '(')
        {
            throw std::invalid_argument("Check the Operator Symbol .Not accepted other than '*,/,+,/' ");
        }
        postFixQueue.enqueue(opStack.top());
        opStack.pop();
    }

    while (!postFixQueue.empty())
    {
        postfix += postFixQueue.front();
        postFixQueue.dequeue();
    }

    return postfix;
}
