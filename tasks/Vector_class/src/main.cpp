#include "vector.cpp"
using namespace std;



int main(){
	Vector<int> a(2,0);
	a.pushback(9);
	a.pushback(4645);
	cout<<"size: "<<a.getsize()<<endl;
	cout<<"cap: "<<a.getcapacity()<<endl;
	a.pushback(464565);
	cout<<"size: "<<a.getsize()<<endl;
	cout<<"cap: "<<a.getcapacity()<<endl;
	a.print();
	a.pushfront(25);
	cout<<"a:"<<endl;
	a.print();
	Vector<int> b;
	b.pushfront(256);
	b.print();
	cout<<"################"<<endl;
	Vector<int> c(a);
	c.print();
	cout<<"after insert"<<endl;
	c.insert(3,1000);
	c.print();
	c.insert(2,521);
	c.print();
	c.pop_back();
	cout<<"c:"<<endl;
	c.print();
	cout<<"after assign"<<endl;
	a=c;
	cout<<a[3]<<endl;
	return 0;
}
