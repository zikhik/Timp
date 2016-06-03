#include <iostream>

/// Объявление нового имени для беззнакового типа int
typedef unsigned int uint;

/// Используем стандартное пространство имен
using namespace std;

/**\param matrix − адрес буфера назначения
* \param graphCount − количество графов
*/
/// Функция DijkstraAlg() − точка входа в функцию алгоритма Дейкстры
void DijkstraAlg(uint** matrix, uint graphCount)
{
    ///> Алгоритм функции
    ///- Инициализация переменных
    uint* distance = new uint [graphCount];
    bool* visited = new bool [graphCount];
    uint k, index, u, i;
    uint uintMax = INT_MAX * 2 + 1;

    ///- Подготовка массивов путей и посещений узлов
    for (i = 0; i < graphCount; ++i) {
        distance[i] = uintMax;
        visited[i] = false;
    }

    ///- Расстояние от первого узла до самого себя равно 0
    distance[0] = 0;

    ///- Реализация алгоритма
    for (k = 0; k < graphCount - 1; ++k) {
        uint min = uintMax;
        for (i = 0; i < graphCount; ++i)
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                index = i;
            }
        u = index;
        visited[u] = true;
        for (i = 0; i < graphCount; ++i)
            if (
                (!visited[i]) &&
                (matrix[u][i]) &&
                (distance[u] != uintMax) &&
                (distance[u] + matrix[u][i] < distance[i])
               )
                distance[i] = distance[u] + matrix[u][i];
    }

    ///- Вывод значений кратчайших путей от первой вершины до остальных
    for (i = 1; i < graphCount; ++i)
        if (distance[i] != uintMax)
            cout << "Minimal way(1-" << i + 1 << ") = " << distance[i] << endl;
        else
            cout << "Minimal way(1-" << i + 1 << ") = the minimal way does not exist" << endl;

    ///- Освобождение выделенной под массивы памяти
    free(distance);
    free(visited);
}

/**\return {0} - выход из функции
*/
/// Функция main() − точка входа в программу
int main()
{
    ///- Инициализация переменных
    uint graphCount = 0;
    uint** matrix = new uint* [graphCount];
    
    cout << "If the straight way doesn't exist, enter 0 for it." << endl;
    cout << "Number of graphs = ";
    cin >> graphCount;

    ///- Заполнение матрицы смежности исходными данными
    for (uint i = 0; i < graphCount; ++i) {
        matrix[i] = new uint [graphCount];
        for (uint j = 0; j < graphCount; ++j)
            cin >> matrix[i][j];
    }

    ///- Вызов функции реализации алгоритма Дейкстры
    DijkstraAlg(matrix, graphCount);

    ///- Пауза в работе программы
    system("pause");
    return 0;
}
