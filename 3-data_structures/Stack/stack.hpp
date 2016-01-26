/*
 * 
 */

#ifndef STACK_HPP
#define STACK_HPP 1

template <class T>
class stack
{
  private:
    int size;
    int top;
    T* stackPtr;
    
  public:
    stack(int);
    ~stack();
};

template <class T>
stack <T>::stack(int s = 10)
{
  size = s;
  top = -1;
  stackPtr = new T[size];
}

template <class T>
<T> stack <T>::stack(int s = 10)
{
  
}

#endif
