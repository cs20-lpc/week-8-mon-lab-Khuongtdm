#include <iostream>
#include "ArrayStack.hpp"
#include<string>
using namespace std;

template <typename T>

void testRotate(ArrayStack<T> s)
{
    ArrayStack<T> temp = s;

    cout << "Original Stack:\n" << s << endl;

    cout << "Rotating RIGHT (Top to Bottom):" << endl;
    s.rotate(Stack<T>::RIGHT);
    cout << s << endl;

    cout << "Rotating LEFT (Bottom to Top):" << endl;
    temp.rotate(Stack<T>::LEFT);
    cout << temp << endl;
}


int main()
{
    //cout << "\n=========== Basic operator (including copy constructor) and some edge case===========" << endl;
    //ArrayStack<int> s1(3); 

    //cout << "Is empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;
    //s1.push(10);
    //s1.push(20);
    //s1.push(30);
    //cout << "Stack after 3 pushes:\n" << s1;

    //ArrayStack<int> s2 = s1;
    //cout << " Stack 2 after copy by contruction\n" << s2;
    ////test clear function
    //cout << "Clear stack 2:\n";
    //s2.clear();
    //cout << "stack 2 after clear\n " << s2;
    //// Edge Case: Push to full
    //try {
    //    cout << "test overflow by do a push" << endl;
    //    s1.push(40);
    //}
    //catch (string e) { cout << "Caught expected error(it should say stackOverflow: " << e << endl; }

    //cout << "\n================================================= Peek and Pop ==========================================" << endl;
    //cout << "Top element (peek): " << s1.peek() << endl;
    //s1.pop();
    //cout << "After 1 pop, top is: " << s1.peek() << endl;

    //s1.pop();
    //s1.pop();
    //// Edge Case: Pop from empty
    //try {
    //    cout << "Attempting underflow pop..." << endl;
    //    s1.pop();
    //}
    //catch (string e) { cout << "Caught expected error(it should say: invalid length): " << e << endl; }

    //cout << "\n==================================== Rotational function ===============================" << endl;
    //ArrayStack<int> s3(5);
    //s3.push(1);
    //s3.push(2);
    //s3.push(3);
    //s3.push(4);
    //testRotate(s3);
    
    //cout << "\n=========== Basic operator (including copy constructor) and some edge case===========" << endl;
    //ArrayStack<string> s1(3);

    //cout << "Is empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;
    //s1.push("dog");
    //s1.push("cat");
    //s1.push("frog");
    //cout << "Stack after 3 pushes:\n" << s1;

    //ArrayStack<string> s2 = s1;
    //cout << " Stack 2 after copy by contruction\n" << s2;
    ////test clear function
    //cout << "Clear stack 2:\n";
    //s2.clear();
    //cout << "stack 2 after clear\n " << s2;
    //// Edge Case: Push to full
    //try {
    //    cout << "test overflow by do a push" << endl;
    //    s1.push("fish");
    //}
    //catch (string e) { cout << "Caught expected error(it should say stackOverflow: " << e << endl; }

    //cout << "\n================================================= Peek and Pop ==========================================" << endl;
    //cout << "Top element (peek): " << s1.peek() << endl;
    //s1.pop();
    //cout << "After 1 pop, top is: " << s1.peek() << endl;

    //s1.pop();
    //s1.pop();
    //// Edge Case: Pop from empty
    //try {
    //    cout << "Attempting underflow pop..." << endl;
    //    s1.pop();
    //}
    //catch (string e) { cout << "Caught expected error(it should say: invalid length): " << e << endl; }

    //cout << "\n==================================== Rotational function ===============================" << endl;
    //ArrayStack<string> s3(5);
    //s3.push("pho");
    //s3.push("orange chicken");
    //s3.push("milktea");
    //s3.push("rice");
    //testRotate(s3);
    //return 0;
    // 1. Initialize Stack A with size 10
    ArrayStack<int> sA(10);

   
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
        sA.push(i);
    }


    if (sA.isFull()) {
        cout << "Stack A is full!" << endl;
    }
    cout << "Stack A length: " << sA.getLength() << endl;


    ArrayStack<int> sB(sA);
    cout << "Stack B length: " << sB.getLength() << endl;


    try {
        sB.push(100);
    }
    catch (string e) {
        cout << e << endl; 
    }

    for (int i = 0; i < 5; i++) {
        cout << "Popping " << sB.peek() << " from stack B" << endl;
        sB.pop();
    }


    cout << "Stack B length: " << sB.getLength() << endl;


    sB.clear();
    if (sB.isEmpty()) {
        cout << "Stack B is now empty after being cleared" << endl;
    }


    try {
        sB.pop();
    }
    catch (string e) {
        cout << e << endl; 
    }

 
    try {
        sB.peek();
    }
    catch (string e) {
        cout << e << endl; 
    }


    ArrayStack<int> sC = sA;
    cout << "Stack A length: " << sA.getLength() << endl;
    cout << "Stack C length: " << sC.getLength() << endl;

    //this just create to pass the test case.

    return 0;
}