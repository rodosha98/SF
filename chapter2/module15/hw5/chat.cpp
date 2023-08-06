#include "chat.hpp"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
    mem_size = 8;
    data = new AuthData [mem_size];
}

Chat::~Chat() {
    delete[] data;
}

void Chat::add(char login[LOGINLENGTH], uint* pass_sha1_hash) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(login, i);
        if(data[index].status != enPairStatus::engaged) { 
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }
    if(i >= mem_size) 
    {
        resize();
        add(login, pass_sha1_hash);
    } // все перебрали, нет места
    
    // кладем в свободную ячейку пару
    data[index] = AuthData(login, pass_sha1_hash);
    data_count++;
}

void Chat::del(char login[LOGINLENGTH]) {
    // Ваш код
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(; i < mem_size; i++) 
    {
        index = hash_func(login, i);
        if(data[index].status == enPairStatus::free) { 
            // найдена пустая ячейка, занимаем ее
            return;
        }
        else if (data[index].status == enPairStatus::deleted)
        {
            continue;
        }
        else
        {
            if (!strcmp(data[index].login, login))
            {
                break;
            }
        }
    }

    data[index].status = enPairStatus::deleted;
    data_count--;
    return;

}

uint* Chat::find(char login[LOGINLENGTH]) {
    // вернуть нужно значение, соответствующее ключу fr_name
    // если такого ключа нету в таблице, то верните -1
    // Ваш код
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(; i < mem_size; i++) 
    {
        index = hash_func(login, i);
        if(data[index].status == enPairStatus::free) { 
            // найдена пустая ячейка, занимаем ее
            return nullptr;
        }
        else if (data[index].status == enPairStatus::deleted)
        {
            continue;
        }
        else
        {
            if (!strcmp(data[index].login, login))
            {
                return data[index].pass_sha1_hash;
            }
        }
    }

 
    return nullptr;
}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    add(_login, sha1(_pass, pass_length));
}

bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    // Нужно вернуть true в случае успешного логина
    uint* real_pass_hash = find(_login);
    uint* pass_hash  = sha1(_pass, pass_length);

    if (*real_pass_hash == *pass_hash)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int Chat::hash_func(char login[LOGINLENGTH], int step) {
    long sum = 0;
    for (int i = 0; i < LOGINLENGTH; i++) {
        sum += login[i];
    }

    const double A = 0.7;
    int hf = int(mem_size * (A * sum - int(A * sum)));

    return (hf + step) % mem_size;
}

void Chat::resize() {
    // Не забудьте добавить вызов resize() в нужное место
    // внутри метода add, а затем добавить элемент в увеличенный массив
    // Ваш код

    AuthData* save_array = data; 
    int oldSize = mem_size;

    mem_size *= 2;
    data_count = 0;

    data = new AuthData[mem_size];
    
    for(int i = 0; i < oldSize; i++)
    {
        add(save_array[i].login, save_array[i].pass_sha1_hash);
    }

    
    delete [] save_array;

}