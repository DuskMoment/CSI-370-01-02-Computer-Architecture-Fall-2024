#include <iostream>
#include <fstream>
#include <cassert> 
#include <string>



using namespace std;
char* readFile(string fileName, int size)
{
    fstream fileStream;

    fileStream.open(fileName);
    assert(fileStream.is_open());
    //int counter;
    //   
    string newLine;
    string line;

    for (int i = 0 ; std::getline(fileStream, newLine); i++)
    {

        line += newLine;
    }

    char* arr = new char[line.length()];

    

    copy(line.begin(), line.end(), arr);

    return arr;
}
int countFile(string fileName)
{
    fstream fileStream;

    fileStream.open(fileName);

    assert(fileStream.is_open());    
    
    int counter = 0;
    char junk;
    string line;
  


    while (std::getline(fileStream, line))
    {
        //geting the size of the file
        counter += line.length();
    }

    fileStream.close();

    return counter;
}
void writeToFile(char* arr,int size)
{
    fstream fileStream;
    cout << "Please input a file to write too" << endl;
    string fileName;
    string junk;
    std::getline(std::cin, junk);
    std::getline(std::cin, fileName);

    fileStream.open(fileName);
    fileStream.clear();

    for (int i = 0; i < size; i++)
    {
        fileStream << arr[i];
    }

    return;
}

void encode(char* arr, int size)
{
    int eSize = size;
    char* eArr= arr;
    __asm {

        mov ecx, eSize
        mov edi, 0
        mov eax, eArr
        //shift by one assci
        myLoop :
            sub[eax + edi], 1
            ror[eax + edi], 3
            xor [eax + edi], 110001b
            add[eax + edi], 5
            rol[eax + edi], 40

            inc edi
            loop myLoop

    };

    for (int i = 0; i < size; i++)
    {
        cout << eArr[i];
    }
    cout << endl;

    writeToFile(eArr, eSize);
}

void decode(char* arr, int size)
{
    int dSize = size;
    char* dArr = arr;
    __asm {

        ; lea eax, dArr
        mov ecx, dSize
        mov edi, 0
        mov eax, arr
        //shift by one assci
        myLoopInv :
            ror[eax + edi], 40
            sub[eax + edi], 5
            xor [eax + edi], 110001b
            rol[eax + edi], 3
            add[eax + edi], 1
            inc edi
        loop myLoopInv

    };

    for (int i = 0; i < size; i++)
    {
        cout << dArr[i];
    }

    writeToFile(dArr, dSize);

}


int main()
{
    std::cout << "Hello World!\n";

    cout << "Welcome! Please enter the File to read" << endl;
    string file;
    std::getline(std::cin, file);

    int count = countFile(file);
    char* arr = readFile(file, count);

    cout << "1. Encode" << endl;
    cout << "2. Decode" << endl;
    int choice = 0;
    cin >> choice;

    if (choice == 1)
    {
        encode(arr, count);
    }
    else if (choice == 2)
    {
        //decode
        decode(arr, count);
    }
    else {
        cout << "Invalid input" << endl;
    }

   
    //remeber to free mem
    delete[] arr;

    return 0;
  
}



