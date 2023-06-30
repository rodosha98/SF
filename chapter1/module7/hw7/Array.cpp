#include "Array.h"
#include "Exception.h"

IntArray::IntArray(int length) : _length(length)
{
    if (length <= 0)
    {
        throw BadLength();
    }
    else
    {
        _data = new int[length]{};
    }

}

IntArray::~IntArray()
{
    delete [] this->_data;
}

// We need to make sure we set m_data to nullptr here, otherwise it will
// be left pointing at deallocated memory!
void IntArray::erase()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

//copy constructor
IntArray::IntArray(const IntArray& a)
{
    this->reallocate(a.get_length());

    //copy
    for (int i = 0; i < this->_length; ++i)
    {
        this->_data[i] = a._data[i];
    }
}


//operator overload
int& IntArray::operator[](int index)
{
    if(index < 0 || index >= _length )
    {
        throw BadRange();
    }
    else
    {
        return _data[index];
    }
}

int IntArray::get_length() const
{
    return _length;
}

//reallocate: resize an array by destroying existing elements. Quick.
void IntArray::reallocate(int new_len)
{
    this->erase(); //destroy _data

    if (new_len <= 0)
    {
        throw BadLength();
    }
    else
    {
        //allocate new elements
        this->_data = new int[new_len]{};
        this->_length = new_len;
    }

}

//Slow version. Keep all the elements.
void IntArray::resize(int new_len)
{
    if (new_len <= 0)
    {
        // erase();
        // return;
        throw BadLength();
    }
    else if (new_len == this->_length)
    {
        return;
    }
    else
    {
        int* data = new int[new_len];
        if (this->_length <= 0)
        {
            throw BadLength();
        }
        else
        {
            int nelememets2copy = (new_len > this->_length) ? this->_length : new_len;

            for (int i = 0; i < nelememets2copy; ++i)
            {
                data[i] = this->_data[i];
            }
        }

        delete [] this->_data;
        this->_data = data;
        this->_length = new_len;
    }


}

//copy operator overload
IntArray& IntArray::operator=(const IntArray& a)
{
    //self assigment check
    if (&a == this)
        return *this;

    this->reallocate(a.get_length());

    for (int i=0; i < this->_length; ++i)
    {
        this->_data[i] = a._data[i];
    }

    return *this;
}

void IntArray::insert(int value, int index)
{
    if (index < 0 || index > _length )
    {
        throw BadRange();
    }
    else
    {
    int* data = new int[_length + 1];

    int i = 0;
    //copy before index
    for (i = 0; i < index; ++i)
    {
        data[i] = _data[i];
    }

    //insert index
    data[i++] = value;

    for (i; i < _length + 1; ++i)
    {
        data[i] = _data[i - 1];
    }

    delete [] _data;

    _data = data;
    _length++;
    }

}

void IntArray::remove(int index)
{
    if (index < 0 || index >= _length )
    {
        throw BadRange();
    }
    else if (_length == 1)
    {
        erase();
        return;
    }
    {
        int* data = new int[_length - 1];

        int i = 0;
        //copy before index
        for (i = 0; i < index; ++i)
        {
            data[i] = _data[i];
        }

    
        for (i; i < _length - 1; ++i)
        {
            data[i] = _data[i + 1];
        }

        delete [] _data;

        _data = data;
        _length--;
    }
}

void IntArray::insertAtBeginning(int value)
{
    insert(value, 0);
}

void IntArray::insertAtEnd(int value)
{
    insert(value, this->_length);
}

void IntArray::removeFirst()
{
    remove(0);
}

void IntArray::removeLast()
{
    remove(this->_length - 1);
}

//return index of the Value. Return -1 if not found
int IntArray::findByValue(int value)
{
    
    int index = -1;

    for (int i = 0; i < _length; i++)
    {
        if (_data[i] = value)
        {
            index = value;
        }
    }
    return index;
    
}

void IntArray::print()
{
    std::cout << "Printed array: " << std::endl;
    for (int i = 0; i < _length; ++i)
    {
        std::cout << _data[i] << " ";
    }
    std::cout << std::endl;
}

void IntArray::fill(int value, int index)
{
    if (index < 0 || index >= _length )
    {
        throw BadRange();
    }
    else
    {
        _data[index] = value;
    }
}