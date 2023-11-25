// practic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>


int main()
{
	std::string path = "p.bin";

	const int size = 13;
	int massive_a[size] = { 1,2,3,4,5,6,7,8,9,10,11,100,1000 };
	int massive_b[size];

	std::ofstream out;                         // ofstream НА ЗАПИСЬ в файл!!
	out.open(path, std::ios::binary);
	if (!out.is_open())
	{
		std::cout << "ERROR!!";
		return 1;
	}

	for (int i = 0; i < size; i++)
	{
		out.write(reinterpret_cast<char*>(&massive_a[i]), sizeof(int));
	}
	out.close();

	std::ifstream in;                           // ifstream НА ЧТЕНИЕ из файла!!
	in.open(path, std::ios::binary);
	if (!in.is_open())
	{
		std::cout << "ERROR!!";
		return 1;
	}
	

	for (int i = 0; i < size; i++)
	{
		int value;
		in.read(reinterpret_cast<char*>(&value), sizeof(int));
		massive_b[i] = value;
		std::cout << massive_b[i] << ' ';
	}

	in.close();

	//for (auto b : massive_b)
	//{
	//	std::cout << b;
	//}
}
	

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
