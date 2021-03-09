#include <iostream>
#include <ctime>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    :data(d), next(nullptr), prev(nullptr) {}

};

class List {
    int size;
    Node* first;

public:
    List()
    :size(0), first(nullptr) {}

    List(int count, int v) {
        size = 0;
        first = nullptr;
        for(int i = 0; i < count; ++i) {
            push_back(v);
        }
    }

    List(const List& a) {
        size = 0;
        if(a.size == 0) {
            first = nullptr;
        }
        else {
            Node* q = a.first;
            while(q) {
                push_back(q->data);
                q = q->next;
            }
        }
    }

    void insert(int index, const int& d) {
        if(index > size) {
            push_back(d);
            return;
        }
        if(index == 0) {
            push_front(d);
            return;
        }
        if(index == size) {
            push_back(d);
            return;
        }
        Node* q = first;
        for(int i = 1; i < index; ++i) {
            q = q->next;
        }
        Node* g = q->next;
        Node* f = new Node(d);
        q->next = f;
        f->prev = q;
        f->next = g;
        g->prev = f;
        ++size;
    }

    void remove(int index) {
        if(index >= size) {
            return;
        }
        if(index == 0) {
            pop_front();
            return;
        }
        if(index == size - 1) {
            pop_back();
            return;
        }
        Node* q = first;
        for(int i = 1; i < index; ++i) {
            q = q->next;
        }
        Node* g = q->next;
        q->next = g->next;
        if(g->next)
            (g->next)->prev = q;
        delete g;
    }

    void push_back(const int& d) {
        Node* g = new Node(d);
        if(size == 0) {
            first = g;
        }
        else {
            Node* q = first;
            while(q->next) {
                q = q->next;
            }
            q->next = g;
            g->prev = q;
        }
        ++size;
    }

    void push_front(const int& d) {
        Node* q = new Node(d);
        q->next = first;
        if(first) {
            first->prev = q;
        }
        first = q;
        ++size;
    }

    void pop_back() {
        if(size == 0) {
            return;
        }
        if(size == 1) {
            first = nullptr;
        } else {
            Node* q = first;
            while(q->next) {
                q = q->next;
            }
            (q->prev)->next = nullptr;
            delete q;
        }
        --size;
    }

    void pop_front() {
        if(size > 0) {
            Node* q = first;
            first = first->next;
            first->prev = nullptr;
            delete q;
            --size;
        }
    }

    void print() const {
        Node* q = first;
        std::cout<<"{";
        while(1) {
            std::cout<<q->data;
            q = q->next;
            if(q) {
                std::cout<<", ";
            }
            else {
                break;
            }
        }
        std::cout<<"}"<<std::endl;
    }

    int getSize() const {
        return size;
    }

    List& operator=(const List& a) {
        Node* g = a.first;
        if(a.size == 0) {
            size = 0;
            return *this;
        }
        while(g->next) {
            push_back(g->data);
            g = g->next;
        }

        return *this;
    }

    int find_min() {
        if(size == 0) {
            throw "You don't have any member";
        }
        int num = first->data;
        Node* q = first;
        while(q) {
            if(num > q->data) {
                num = q->data;
            }
            q = q->next;
        }
        return num;
    }

    int find_max() {
        if(size == 0) {
            throw "You don't have any member";
        }
        int num = first->data;
        Node* q = first;
        while(q) {
            if(num < q->data) {
                num = q->data;
            }
            q = q->next;
        }
        return num;
    }

    int calculate_sum() {
        int ans = 0;
        if(size == 0) {
            return ans;
        }
        Node* q = first;
        while(q) {
            ans += q->data;
            q = q->next;
        }
        return ans;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    srand(time(NULL));
    List a;
    for(int i = 0; i < 10; ++i) {
        a.push_back(rand() % 100);
    }
    a.print();
    std::cout<<"Min: "<<a.find_min()<<std::endl;
    std::cout<<"Max: "<<a.find_max()<<std::endl;
    std::cout<<"Sum: "<<a.calculate_sum()<<std::endl;
    return 0;
}