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
            try
            {
                //cout << line << endl;

                if (line[i]=='"')
                    if (i>0 && line[i-1]!='\\')
                        literal = !literal;
                if (!literal)
                {
                    if (line[i] == '{'||line[i] == '['||line[i] == '(')
                    {
                        cout << "line[" << i << "]:" << line[i] << endl;
                        stack.push(line[i]);
                        cout << stack.to_string() << endl;
                    }
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
            catch (const char*)
            {
                if (stack.isFull())
                    stack = GenericStack<char>(stack.size * 2);
                if (stack.isEmpty())
                    cout << "yeet. a reference to a vine about an object being empty" << endl;
            }
        }
        ++lineNumber;
        getline(in, line);
    }
    if (stack.size!=0)
    {
        //yoo if i started this like 2 hours earlier i could use {},(),[] as an enum ya know like (1,6)(2,5)(3,4)
        if (stack.peek()=='[')
            cout << "missing ]" << endl;
        if (stack.peek()=='(')
            cout << "missing )" << endl;
        if (stack.peek()=='{')
            cout << "missing }" << endl;
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
