#include <iostream>
#include <fstream>
#include <cassert> 
#include <string>
#include <stdexcept>


//MAKE SURE TO RUN IN 32 BIT MODE
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
    cout << "Please input a file to write too. Please make sure that this file exists" << endl;
    string fileName;
    string junk;
    std::getline(std::cin, junk);
    std::getline(std::cin, fileName);

    fileStream.open(fileName);
    assert(fileStream.is_open());

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
        mov esi, eArr
        //shift by one assci
        myLoop :
            mov al, [esi + edi]
            movsx edx, al
            mov eax, 2
            imul eax, edx
            
            mov [esi + edi], al

            ror[esi + edi], 3
            xor [esi + edi], 110001b
            add[esi + edi], 5
            rol[esi + edi], 40

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
        mov esi, arr
        //shift by one assci
        myLoopInv :
            ror[esi + edi], 40
            sub[esi + edi], 5
            xor [esi + edi], 110001b
            rol[esi + edi], 3

            xor eax, eax
            mov al, [esi + edi]
            xor edx, edx
            mov ebx, 2
            div ebx
            mov [esi + edi], al

            inc edi
        loop myLoopInv

    };

    for (int i = 0; i < size; i++)
    {
        cout << dArr[i];
    }
    cout << endl;

    writeToFile(dArr, dSize);

}


int main()
{
    std::cout << "Hello World!\n";

    cout << "Welcome! Please enter the File to read with the file extension. Please make sure that this file exists before typing in the name" << endl;
    string file;
    std::getline(std::cin, file);

    int count = countFile(file);
    char* arr = readFile(file, count);

    cout << "Please input a number" << endl;
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



