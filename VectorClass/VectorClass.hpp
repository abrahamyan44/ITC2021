//declaration
template <class T>
class VectorClass
{
private:
    T* m_array;
    int m_capacity;
    int m_quantity;
public:
    VectorClass();
    VectorClass(const int, T*);
    VectorClass(const VectorClass <T>&);
    ~VectorClass();
    void PushBack(const T&);
    void Push(int, int);
    T GetElement(int);
    void PopBack();
    int GetSize();
    int GetCapacity();
    bool IsEmpty();
    void Reserve(int);
    void ShrinkToFit();
    VectorClass<T>& operator=(const VectorClass&);
    T&  operator[](unsigned int);
    void Print();
};
