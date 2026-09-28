#include <iostream>
using namespace std;

// Print array
void printArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";

        cout << endl;
    }
}

// Task 1 - add row to the beginning
void addRowStart(int**& arr, int& rows, int cols)
{
    int** newArr = new int* [rows + 1];

    newArr[0] = new int[cols];

    cout << "Enter new row: ";

    for (int j = 0; j < cols; j++)
        cin >> newArr[0][j];

    for (int i = 0; i < rows; i++)
    {
        newArr[i + 1] = new int[cols];

        for (int j = 0; j < cols; j++)
            newArr[i + 1][j] = arr[i][j];
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    rows++;
}

// Task 2 - delete first row
void deleteRowStart(int**& arr, int& rows, int cols)
{
    if (rows <= 1)
    {
        cout << "Cannot delete the last row!" << endl;
        return;
    }

    int** newArr = new int* [rows - 1];

    for (int i = 1; i < rows; i++)
    {
        newArr[i - 1] = new int[cols];

        for (int j = 0; j < cols; j++)
            newArr[i - 1][j] = arr[i][j];
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    rows--;
}

// Task 3 - delete row by position
void deleteRow(int**& arr, int& rows, int cols, int position)
{
    if (position < 0 || position >= rows)
    {
        cout << "Wrong position!" << endl;
        return;
    }

    if (rows <= 1)
    {
        cout << "Cannot delete the last row!" << endl;
        return;
    }

    int** newArr = new int* [rows - 1];

    int newRow = 0;

    for (int i = 0; i < rows; i++)
    {
        if (i == position)
            continue;

        newArr[newRow] = new int[cols];

        for (int j = 0; j < cols; j++)
            newArr[newRow][j] = arr[i][j];

        newRow++;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    rows--;
}

// Task 4 - add column to the beginning
void addColumnStart(int**& arr, int rows, int& cols)
{
    int** newArr = new int* [rows];

    cout << "Enter new column:" << endl;

    for (int i = 0; i < rows; i++)
    {
        newArr[i] = new int[cols + 1];

        cin >> newArr[i][0];

        for (int j = 0; j < cols; j++)
            newArr[i][j + 1] = arr[i][j];
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    cols++;
}

// Task 5 - add column by position
void addColumn(int**& arr, int rows, int& cols, int position)
{
    if (position < 0 || position > cols)
    {
        cout << "Wrong position!" << endl;
        return;
    }

    int** newArr = new int* [rows];

    cout << "Enter new column:" << endl;

    for (int i = 0; i < rows; i++)
    {
        newArr[i] = new int[cols + 1];

        for (int j = 0; j < position; j++)
            newArr[i][j] = arr[i][j];

        cin >> newArr[i][position];

        for (int j = position; j < cols; j++)
            newArr[i][j + 1] = arr[i][j];
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    cols++;
}

// Task 6 - delete column by position
void deleteColumn(int**& arr, int rows, int& cols, int position)
{
    if (position < 0 || position >= cols)
    {
        cout << "Wrong position!" << endl;
        return;
    }

    if (cols <= 1)
    {
        cout << "Cannot delete the last column!" << endl;
        return;
    }

    int** newArr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        newArr[i] = new int[cols - 1];

        int newCol = 0;

        for (int j = 0; j < cols; j++)
        {
            if (j == position)
                continue;

            newArr[i][newCol] = arr[i][j];
            newCol++;
        }
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    arr = newArr;
    cols--;
}

int main()
{
    int rows, cols;

    cout << "Enter rows: ";
    cin >> rows;

    cout << "Enter columns: ";
    cin >> cols;

    int** arr = new int* [rows];

    cout << "Enter array:" << endl;

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    cout << "\nOriginal array:" << endl;
    printArray(arr, rows, cols);

    // Task 1
    cout << "\nTASK 1" << endl;
    addRowStart(arr, rows, cols);
    printArray(arr, rows, cols);

    // Task 2
    cout << "\nTASK 2" << endl;
    deleteRowStart(arr, rows, cols);
    printArray(arr, rows, cols);

    // Task 3
    cout << "\nTASK 3" << endl;

    int rowPosition;

    cout << "Enter row position: ";
    cin >> rowPosition;

    deleteRow(arr, rows, cols, rowPosition);
    printArray(arr, rows, cols);

    // Task 4
    cout << "\nTASK 4" << endl;

    addColumnStart(arr, rows, cols);
    printArray(arr, rows, cols);

    // Task 5
    cout << "\nTASK 5" << endl;

    int columnPosition;

    cout << "Enter column position: ";
    cin >> columnPosition;

    addColumn(arr, rows, cols, columnPosition);
    printArray(arr, rows, cols);

    // Task 6
    cout << "\nTASK 6" << endl;

    cout << "Enter column position: ";
    cin >> columnPosition;

    deleteColumn(arr, rows, cols, columnPosition);
    printArray(arr, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    delete[] arr;

    return 0;
}
