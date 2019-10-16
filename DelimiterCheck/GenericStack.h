using namespace std;

template <class Generic> class GenericStack
{

        private Generic* stack;

        public int index;
        public int size;

        public char peek()
        {
            return stack[index];
        }
        public char pop()
        {
            if (index > 0)
            {
                index--;
                return stack[index];
            }
            else throw StackEmpty;
        }
        public void push(char c)
        {
            if (index < size)
            {
                index++;
                stack[index] = c;
            }
            else throw StackFull;
        }
        public bool isFull()
        {
            return size == index + 1;
        }
        public bool isEmpty()
        {
            return index == 0;
        }


        public GenericStack()
        {
            //TODO: question to ask, can i put index = -1 in the header
            index = -1;
            size = 128;
            stack = new char[size];
        }

        public GenericStack(int s)
        {
            index = -1;
            size = s;
            stack = new char[size];
        }
        public ~GenericStack()
        {
            delete stack;
        }
};
