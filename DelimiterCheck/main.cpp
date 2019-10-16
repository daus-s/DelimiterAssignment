#include <iostream>
#include <fstream>

#include "GenericStack.h"

using namespace std;



void checkChars(ifstream in)
{
    int lineNumber = 1;
    bool literal = false;
    string line;
    getline(in, line);
    GenericStack<char> stack = GenericStack<char>();
    while (!in.eof())
    {
        for (int i = 0; i < line.size(); ++i)
        {
            cout << stack.to_string() << endl;
            cout << line << endl;

            if (line[i]=='"')
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
                        cout << "error on line " << line << ", } expected" << endl;
                        return;
                    }
                }
                if (line[i] == ')')
                {
                    if (stack.peek()=='(')
                        stack.pop();
                    else
                    {
                        cout << "error on line " << line << ", ) expected" << endl;
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
        getline(in, line);
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
    checkChars(ifstream(file));
}
