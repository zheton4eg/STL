#include <iostream>
#include <array>
#include <vector>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#define tab "\t"
#define delimiter "\n<----------------------------------------------------------->\n"

/////////////////////////////////////////////////////////

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_LIST
template<typename T>void vector_info(const std::vector<T>& vec);
void main()
{
	setlocale(LC_ALL, "");

	cout << "Hello STL" << endl;

#ifdef STL_ARRAY

	const int N = 5;
	std::array<int, N>arr{3,5,8,13,21};
	for (int i = 0; i <arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY
#ifdef STL_VECTOR

	std::vector<double> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.reserve(15);

	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);

	int index;
	int value;
	int count;

	vec.insert(vec.begin() + 4, { 1024,2048,3072,4096 });
	for (int i : vec)cout << i << tab; cout << endl;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите кол-во добавл€емых элементов: "; cin >> count;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;


	vec.insert(vec.begin()+index,count, value);
	for (int i : vec)cout << i << tab; cout<<endl;

	cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	cout << "¬ведите кол-во удал€емого элементов: "; cin >> count;

	vec.erase(vec.begin() + index, vec.begin()+index+count);
	for (int i : vec)cout << i << tab; cout << endl;
	
#endif // STL_VECTOR
#ifdef STL_LIST

	std::list<int> list = { 3,5,8,13,21 };
	for (std::list<int>::iterator it = list.begin();it!=list.end();++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << list.front() << endl;
	cout << list.back() << endl;
	list.push_front(2);
	list.push_back(34);
	list.emplace_front(1);
	for (int i : list)cout << i << tab; cout << endl;

	int index;
	int value;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элементов: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	std::advance(position, index);
	list.insert(position, value);
	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_LIST
}
template<typename T>void vector_info(const std::vector<T>& vec)
{
	
	cout << "Size: " << vec.size() << endl;
	cout << "Capasity: " << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
}