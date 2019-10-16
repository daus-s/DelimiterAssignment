#include <iostream>
#include <fstream>

#include "GenericStack.h"

using namespace std;

bool literal = false;

void checkChars(ifstream in)
{
    int lineNumber = 1;
    string line;
    getline(in, line);
    GenericStack<char> stack = new GenericStack<char>();
    while (!in.eof())
    {
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i]='"')
                if (i>0 && line[i-1]!='\\')
                    literal = !literal;
            if (!literal)
            {
                if (line[i] == '{'||line[i] == '['||line[i] == '(')
                    stack.push(line[i]);
                if (line[i] == '}')
                {
                    if (stack.peek()=='{')
                        stack.pop();
                    else
                    {
                        cout << "error on line " << line << " } expected" << endl;
                        return;
                    }
                }
                if (line[i] == ')')
                {
                    if (stack.peek()=='(')
                        stack.pop();
                    else
                    {
                        cout << "error on line " << line << " ) expected" << endl;
                        return;
                    }
                }
                if (line[i] == ']')
                {
                    if (stack.peek()=='[')
                        stack.pop();
                    else
                    {
                        cout << "error on line " << line << " ] expected" << endl;
                        return;
                    }
                }
            }
        }
    ++lineNumber;
    }
    if (stack.size!=0)
    {
        cout << "missing" << stack.peek() << endl;
        return;
    }
    else
        cout << "delimiters properly ordered and even distribution of types" << endl;
}


int main()
{
    cout << "Enter file name:" << endl;
    string file;
    cin >> file;
    checkChars(new ifstream(file));
}
