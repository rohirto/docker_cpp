/**
 * @file custom_deleter2.cpp
 * @author rohirto
 * @brief Complicated demo of custom deleters
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//This code provides a template-based implementation of a MakeUnique function for creating std::unique_ptr instances. 
//The unique pointers created by this function have custom deleters that allow control over whether the pointed-to object should be deleted or not.

#include <iostream>
#include <memory>

/*
MakeUniqueTraits: This is a template structure that provides two static member functions (Delete and NoDelete) and a type alias (UniquePtrType). 
It's used to define the traits for creating std::unique_ptr instances with custom deleters.

Delete: A static function that deletes the given pointer.
NoDelete: A static function that does nothing (no deletion).
UniquePtrType: A type alias for the desired type of std::unique_ptr with the appropriate deleter.
*/
template<class T>
struct MakeUniqueTraits
{
  static void Delete(const T* ptr)
  { delete ptr; }
    
  static void NoDelete(const T*)
  { }
    
  using UniquePtrType = std::unique_ptr<const T, void(*)(const T*)>;
};


/*
MakeUnique(T const& ref): Creates a std::unique_ptr from a const reference. It uses MakeUniqueTraits<T>::NoDelete as the deleter, 
indicating that the pointed-to object should not be deleted.
*/
template<class T>
auto MakeUnique(T const& ref)
{
    return typename MakeUniqueTraits<T>::UniquePtrType(&ref, MakeUniqueTraits<T>::NoDelete);
}


/*
MakeUnique(T* ptr): Creates a std::unique_ptr from a pointer. It uses MakeUniqueTraits<T>::Delete as the deleter, 
indicating that the pointed-to object should be deleted.*/
template<class T>
auto MakeUnique(T* ptr)
{
    return typename MakeUniqueTraits<T>::UniquePtrType(ptr, MakeUniqueTraits<T>::Delete);
}

/*
POO (Plain Old Object) structure: It represents a simple class with a constant integer member value. 
The destructor prints the value when the object is destroyed.
*/
struct POO
{
  const int value;
    
  POO(int value)
    : value{value}
  { }
    
  ~POO()
  { std::cout << value << '\n'; }
};


/*
Main function:

Creates a POO object named test with a value of 1.
Calls MakeUnique(test) to create a std::unique_ptr that takes ownership of test without deleting it.
Calls MakeUnique(new POO(2)) to create a std::unique_ptr that takes ownership of a dynamically allocated POO object with a value of 2.
Calls MakeUnique(new POO(3)) similarly for a POO object with a value of 3.
The destructors of the POO objects are automatically called when the corresponding std::unique_ptr instances go out of scope, 
demonstrating the ownership and automatic deletion behavior.*/
int main()
{
  POO test(1);  //Create POO object named test with a value of 1:
  auto uPtr = MakeUnique(test);  //This creates a std::unique_ptr with a custom deleter that does not delete the object (MakeUniqueTraits<T>::NoDelete).
                                // So, the test object is not deleted.
  uPtr = MakeUnique(new POO(2));    // This creates a new POO object dynamically with a value of 2 and transfers ownership to a     
                                    // std::unique_ptr with a deleter that will delete the object (MakeUniqueTraits<T>::Delete).
                                    //The POO object with a value of 2 is printed when its destructor is called.
  uPtr = MakeUnique(new POO(3));    // Similar to above step
  
  // Here the scope of uPtr gets ended, hence ist destructor is also called
  return 0;
}

