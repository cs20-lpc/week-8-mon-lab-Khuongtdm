template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    maxSize = i;
    buffer = new T[maxSize];
    length = -1;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    
    delete[] buffer;
    buffer = nullptr;
    this->length = -1;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->buffer = new T[maxSize];

    for (int i = 0;i<=length;i++)
    {
        this->buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length+1;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == -1;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize-1;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if(isEmpty()) throw string("peek: error, stack is empty, cannot access the top");
    return buffer[length];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if (this->length <= -1)
    {
        throw string("pop: error, stack is empty, avoiding underflow");
    }
    this->length--;

}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    //check if push is valid
    if (this->length == maxSize - 1)
    {
        throw string("push: error, stack is full, avoiding overflow");
    }
    length++;
    buffer[length] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (this->length <= 0)
    {
        throw string("invalid length");
    }
    T temp;
    T holder;
    if (dir == RIGHT)
    {
        holder = buffer[length];
        for (int i = 0;i <= this->length;i++)
        {
            temp = holder;
            holder = buffer[i];
            buffer[i] = temp;

        }
        
    }
    if (dir == LEFT)
    {
        holder = buffer[0];
        for (int i = this->length;i >= 0;i--)
        {
            temp = holder;
            holder = buffer[i];
            buffer[i] = temp;
        }
    }
    
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length ; i >= 0; i--) {
            outStream << (i == myObj.length  ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
