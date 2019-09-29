// Implementation here

 #include "Stack.h"
 #include <stdexcept>
 #include <vector>
 #include "CardTypes.h"

template <class T> 
Stack<T>::Stack() {     
    this->S = std::vector<T>();
} 

template <class T> 
Stack<T>::Stack( std:: vector<T> s ) {     
    this->S = s;
} 

template <class T> 
Stack<T> Stack<T>:: push(T element) { 
    this->S.push_back(element);  
    return Stack<T>(this->S);



}
template <class T> 
Stack<T> Stack<T>:: pop() {  
    if (this->S.size() == 0) {
	    throw std::out_of_range("");
    }



    else {
	    this->S.pop_back();
	    return Stack<T>(this->S);
    }
}

template <class T> 
T Stack<T>:: top() { 
    if (this->S.size() == 0) {
	    throw std::out_of_range("");
    }
    else {
        return (this->S.back());
    }
}

template <class T> 
unsigned int Stack<T>:: size() {   
    return this->S.size();
}

template <class T> 
std::vector<T> Stack<T>:: toSeq() {   
    return this->S;
}


template class Stack<CardT>;
// Keep this at bottom

