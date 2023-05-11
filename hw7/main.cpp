#include"Array.h"

using namespace std;

int main(void)
{
    IntArray* arr = new IntArray(5);

    //insert array
    int num;
    cout << "Ввод массива" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Введите целое число" << endl;
        cin >> num;

        arr->fill(num, i);
    }
    arr->print();

    //Check the functions(correct usage no exceptions)
    arr->insertAtBeginning(10);
    arr->print();

    arr->insertAtEnd(10);
    arr->print();

    arr->removeFirst();
    arr->print();

    arr->removeLast();
    arr->print();

    arr->insert(28, 3);
    arr->print();

    arr->remove(3);
    arr->print();

    int find_num = arr->findByValue(4);
    (find_num == -1) ? cout << "No such value in array" << endl 
    : cout << "THe index of the element is: " << find_num << endl;

    //Exception catch 

    try 
    {
        IntArray* arr1 = new IntArray(-10);
    }
    catch(exception& e)
    {
        cout << "Exception 1" << endl;
        cout << e.what() << endl;
    }

    try 
    {
        IntArray* arr2 = new IntArray(5);
        arr2->resize(-5);
    }
    catch(exception& e)
    {
        cout << "Exception 2" << endl;
        cout << e.what() << endl;
    }

    try 
    {
        
        IntArray* arr3 = arr;
        arr3->insert(10, 20);
    }
    catch(exception& e)
    {
        cout << "Exception 3" << endl;
        cout << e.what() << endl;
    }

    try 
    {
        cout << "Exception 4" << endl;
        IntArray* arr4 = arr;
        arr4->remove(10);
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }

}