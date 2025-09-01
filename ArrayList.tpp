template <typename T>
ArrayList<T>::ArrayList(int i) {
    // TODO
this->length = 0;                       // empty list = 0
maxSize = i;                            // set max capacity = i
buffer = new T[maxSize];                // allocate dinamic array = buffer

}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    // TODO
     if (isFull()) {
        throw string("append: error, list is full");                // cout using a for loop when is full
    }
    buffer[this->length] = elem;                                    // put elem at the end 
    this->length++;                                                 // increase the lenght
}

template <typename T>
void ArrayList<T>::clear() {
    // TODO
     delete[] buffer;                // delete allocated memory 
    buffer = nullptr;               // good practice doing nullptr
    this->length = 0;               // reset lenght to starting 0
    maxSize = 0;                    // reser maxSize to 0 too
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;                          // copy max capasity
    this->length = copyObj.length;                      // copy lenght
    buffer = new T[maxSize];                            // allocate new buffer 
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];                  // foor loop to copy each element
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    // TODO
     if (position < 0 || position >= this->length) {                             // 
        throw string("getElement: error, position out of bounds");      
    }
    return buffer[position];   
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    // TODO
     if (isFull()) {
        throw string("insert: error, list is full");                    // cout error when is full 
    }
    if (position < 0 || position > this->length) {                          
        throw string("insert: error, position out of bounds");          // cout if position is invalid
    }
    for (int i = this->length; i > position; --i) {                     // 
        buffer[i] = buffer[i - 1];
    }
buffer[position] = elem;                                                // insert new elem into position
this->length++;                                                         // increase leghnt to reflec the new elem
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    // TODO
 if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");          // cout if position is invaliud
    }
    for (int i = position; i < this->length - 1; ++i) {                 // i = position, start from the pos of deleted elem and move to the next, move each to the left
        buffer[i] = buffer[i + 1];                                      // copy the elem form the right next to it to the current one
    }
    this->length--;                                                     // decrease leght
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    // TODO
if (position < 0 || position >= this->length) {                     //  
        throw string("replace: error, position out of bounds");         //
    }
    buffer[position] = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}

