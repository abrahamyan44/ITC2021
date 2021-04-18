
template <typename T>
class List
{
struct node
{
    T number;
    node* prev = 0;
    node* next = 0;
};

private:
    int m_size;
    node* m_begin;
    node* m_end;

private:
    void free();

public:
    List();
    List(int count, T value);
    List(const List&);
    List& operator=(const List&);
    T& operator[](int);
    ~List();

public:
    int Size() const;
    void InsertBegin(const T& value);
    void InsertEnd(const T& value);
    void Insert(int pos, const T& value);
    void EraseBegin();
    void EraseEnd();
    void Erase(int pos);
    void Print();
};
