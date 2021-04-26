// declaration
template <class T>
class StackClass {
private:
    struct Node {
        T value;
        Node* link;
        Node(const T& data) {
            value = data;
            link = nullptr;
        }
    };
    Node* m_top;
    int m_size;
public:
    StackClass();
    StackClass(int, T*);
    StackClass(const StackClass&);
    ~StackClass();
    void Pop();
    void Push(T);
    int GetSize() const;
    bool IsEmpty() const;
    T Top();
    void Print();
};
