#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class Array
{
private:
	unsigned int size;
	unsigned int capacity;	
	T *m_data;
public:
	Array()
	:m_data(new T[4]),size(0),capacity(4){
	}
	Array(unsigned int len, const T &data){
		capacity = max((int)len * 2, 4);
		size = len;
		m_data = new T[capacity];
		for (int i = 0; i < len; i++)
			m_data[i] = data;
	}
	Array(const Array<T> &ay) {
		size = ay.size;
		capacity = ay.capacity;
		m_data = new T[capacity];
		for (int i = 0; i < size; i++)
			m_data[i] = ay.m_data[i];
	}
	~Array() {
		delete[]m_data;
	}
	Array<T>& operator=(const Array<T> &source) {
		if (this == &source)
			return *this;
		delete[] m_data;
		size = source.size;
		capacity = source.capacity;
		m_data = new T[capacity];
		for (int i = 0; i < size; i++)
			m_data[i] = source.m_data[i];
		return *this;
	}
	unsigned int Size() const {
		return size;
	}
	void resize() {
		T* newData = new T[capacity * 2];
		for (int i = 0; i < size; i++)
			newData[i] = m_data[i];
		capacity *= 2;
		delete[]m_data;
		m_data = newData;
	}
	void push_back(const T &data) {
		if (size >= capacity)
			this->resize();
		m_data[size++] = data;
	}
	T pop_back() {
		if (size == 0) throw - 1;
		return m_data[--size];
	}
	T& operator [] (unsigned int index) {
		if (index >= size) throw - 1;
		return m_data[index];
	}
	const T& operator [] (unsigned int index) const {
		if (index >= size) throw - 1;
		return m_data[index];
	}
};

int main() {
	try {
		Array<int> b;
		cout << b.Size() << endl;
		//a[0] = 0;
		b.push_back(2);
		cout << b[0] << endl;

		Array<int> a(2, 2);
		a.push_back(3);
		a.push_back(3);
		a.push_back(3);
		a.push_back(4);
		a.push_back(4);
		a.push_back(4);
		for (int i = 0; i < a.Size(); i++)
			cout << a[i] << " ";
		cout << endl;

		for (int i = 0; i < 3; i++)
			a.pop_back();
		for (int i = 0; i < a.Size(); i++)
			cout << a[i] << " ";
		cout << endl;
	}
	catch (int err) {
		cout << "error";
	}
	system("pause");
	return 0;
}
