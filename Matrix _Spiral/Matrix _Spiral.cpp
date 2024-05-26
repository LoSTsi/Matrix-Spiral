#include <iostream>
using namespace std;


int n;
int size_nul = 0;
int x = 0;
int y = 1;

void add_map(int** map_size, int size_arr, int arr[], int number_turns)
{
	int Rows = n;
	int Cols = n;

	for (int i = 0; i < number_turns - 1; i++)
	{
		for (int i = (Rows + x) - Rows; i < (Rows + y) - Rows; i++)//запись первой строки / без поворота 
		{
			for (int j = (Cols + x) - Cols; j < Cols - x; j++)
			{
				map_size[i][j] = arr[size_nul++];
			}
		}

		for (int i = (Rows + y) - Rows; i < Rows - x; i++) // запись правого столбика / с верху в низ
		{
			for (int j = Cols - y; j < Cols - x; j++)
			{
				map_size[i][j] = arr[size_nul++];
			}
		}

		for (int i = Rows - y; i < Rows - x; i++)//запись строки / нижний ряд / право на лево 
		{
			for (int j = Cols - (y + 1); x <= j; j--)
			{
				map_size[i][j] = arr[size_nul++];

			}
		}

		for (int i = Rows - (y + 1); i >= (Rows + y) - Rows; i--) //запись левого столбика / с низу в сверх 
		{
			for (int j = Cols - Cols + x; j < (Cols + y) - Cols; j++)
			{
				map_size[i][j] = arr[size_nul++];
			}
		}
		

		x++;
		y++;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << endl;
		for (size_t j = 0; j < n; j++)
		{
			cout << "\t" << map_size[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] map_size[i];
	}
	delete[]map_size;
	delete[]arr;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число: ";
	cin >> n;

	int number_turns = (n * 2) - 1;
	int j = 0;

	int size_arr = n * n;
	int* arr = new int[size_arr];

	for (size_t i = 0; i < size_arr; i++)
	{
		j++;
		arr[i] = j;
	}

	int** map_size = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		map_size[i] = new int[n] {0};
	}
	add_map(map_size, size_arr, arr, number_turns);

}