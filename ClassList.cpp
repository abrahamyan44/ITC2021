#include <iostream>

struct item
{
    int number;
    int* prev = 0;
    int* next = 0;
}

class list
{
private:
    int size;
    item* begin = 0;
    item* end = 0;

public:
    list();
    list(int count, int value);
    list(const list&);
    list& operator=(const list&);

public:
    int size() const;
    void insert(int pos, const int& value);
    void erase(int pos);
};

list::list()
    :size(0), begin(0), end(0)
{
}

list::list()
{
    
}

int main()
{


}
