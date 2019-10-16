using namespace std;

template <class Generic> class GenericStack
{

    private:
        Generic* stack;

    public:
        int index;
        int size;

        char peek()
        {
            return stack[index];
        }

        char pop()
        {
            if (index > 0)
            {
                index--;
                return stack[index];
            }
            else throw StackEmpty;
        }

        void push(char c)
        {
            if (index < size)
            {
                index++;
                stack[index] = c;
            }
            else throw StackFull;
        }

        bool isFull()
        {
            return size == index + 1;
        }

        bool isEmpty()
        {
            return index == 0;
        }

        GenericStack()
        {
            //TODO: question to ask, can i put index = -1 in the header
            index = -1;
            size = 128;
            stack = new char[size];
        }

        GenericStack(int s)
        {
            index = -1;
            size = s;
            stack = new char[size];
        }

        ~GenericStack()
        {
            delete stack;
        }
};
