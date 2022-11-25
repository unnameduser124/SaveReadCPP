#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct subStruct
{
    bool boolVariable;
    unsigned char unsignedCharVariable;
    float floatVariable;
};

struct fromFile
{
    int intVariable;
    string stringVariable;
    char charVariable;

    struct subStruct subStruct1;
    struct subStruct subStruct2;
    struct subStruct subStruct3;
    struct subStruct subStruct4;
};

void structToString(struct fromFile toStringStructure)
{
    cout << "Int variable: " << toStringStructure.intVariable << endl;
    cout << "String variable: " << toStringStructure.stringVariable << endl;
    cout << "Char variable: " << toStringStructure.charVariable << endl;
    cout << "Substruct 1 bool: " << toStringStructure.subStruct1.boolVariable << endl;
    cout << "Substruct 1 unsigned char: " << toStringStructure.subStruct1.unsignedCharVariable << endl;
    cout << "Substruct 1 float: " << toStringStructure.subStruct1.floatVariable << endl;
    cout << "Substruct 2 bool: " << toStringStructure.subStruct2.boolVariable << endl;
    cout << "Substruct 2 unsigned char: " << toStringStructure.subStruct2.unsignedCharVariable << endl;
    cout << "Substruct 2 float: " << toStringStructure.subStruct2.floatVariable << endl;
    cout << "Substruct 3 bool: " << toStringStructure.subStruct3.boolVariable << endl;
    cout << "Substruct 3 unsigned char: " << toStringStructure.subStruct3.unsignedCharVariable << endl;
    cout << "Substruct 3 float: " << toStringStructure.subStruct3.floatVariable << endl;
    cout << "Substruct 4 bool: " << toStringStructure.subStruct4.boolVariable << endl;
    cout << "Substruct 4 unsigned char: " << toStringStructure.subStruct4.unsignedCharVariable << endl;
    cout << "Substruct 4 float: " << toStringStructure.subStruct4.floatVariable << endl;
}

struct fromFile loadToStructure(string filePath, int structNumber)
{
    struct fromFile loadedStructure;
    int currentLineNumber = 0;

    ifstream testFile;
    string line;
    int attributeCounter = 0;
    testFile.open("testy/input1.txt");
    bool loaded = false;

    if (testFile.is_open())
    {
        while (getline(testFile, line))
        {
            if (currentLineNumber / 7 < structNumber)
            {
                currentLineNumber++;
            }
            else
            {
                loaded = true;
                if (attributeCounter == 0)
                {
                    loadedStructure.intVariable = stoi(line);
                    attributeCounter++;
                }
                else if (attributeCounter == 1)
                {
                    loadedStructure.stringVariable = line;
                    attributeCounter++;
                }
                else if (attributeCounter == 2)
                {
                    loadedStructure.charVariable = line.front();
                    attributeCounter++;
                }
                else if (attributeCounter == 3)
                {
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for (int i = 0; i < line.length() - 1; i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 2)
                        {
                            tempData += line.at(i);
                        }
                        else if (innerAttributeCounter == 0)
                        {
                            loadedStructure.subStruct1.boolVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct1.unsignedCharVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 2);
                            loadedStructure.subStruct1.floatVariable = stof(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if (attributeCounter == 4)
                {
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for (int i = 0; i < line.length() - 1; i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 2)
                        {
                            tempData += line.at(i);
                        }
                        else if (innerAttributeCounter == 0)
                        {
                            loadedStructure.subStruct2.boolVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct2.unsignedCharVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 2);
                            loadedStructure.subStruct2.floatVariable = stof(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if (attributeCounter == 5)
                {
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for (int i = 0; i < line.length() - 1; i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 2)
                        {
                            tempData += line.at(i);
                        }
                        else if (innerAttributeCounter == 0)
                        {
                            loadedStructure.subStruct3.boolVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct3.unsignedCharVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 2);
                            loadedStructure.subStruct3.floatVariable = stof(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if (attributeCounter == 6)
                {
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for (int i = 0; i < line.length() - 1; i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 2)
                        {
                            tempData += line.at(i);
                        }
                        else if (innerAttributeCounter == 0)
                        {
                            loadedStructure.subStruct4.boolVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct4.unsignedCharVariable = stoi(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 2);
                            loadedStructure.subStruct4.floatVariable = stof(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "File not found!";
    }
    return loadedStructure;
}

void saveStructToFile(string filename, struct fromFile structToSave)
{
    ofstream fileToSave(filename, ios::app);
    if (fileToSave.is_open())
    {
        fileToSave << structToSave.intVariable << endl;
        fileToSave << structToSave.stringVariable << endl;
        fileToSave << structToSave.charVariable << endl;

        fileToSave << structToSave.subStruct1.boolVariable << " " << (int)structToSave.subStruct1.unsignedCharVariable << " " << structToSave.subStruct1.floatVariable << endl;
        fileToSave << structToSave.subStruct2.boolVariable << " " << (int)structToSave.subStruct2.unsignedCharVariable << " " << structToSave.subStruct2.floatVariable << endl;
        fileToSave << structToSave.subStruct3.boolVariable << " " << (int)structToSave.subStruct3.unsignedCharVariable << " " << structToSave.subStruct3.floatVariable << endl;
        fileToSave << structToSave.subStruct4.boolVariable << " " << (int)structToSave.subStruct4.unsignedCharVariable << " " << structToSave.subStruct4.floatVariable << endl;

        fileToSave.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void rewriteFile(string writeFrom, string writeTo)
{
    int currentLineNumber = 0;

    ifstream testFile;
    string line;
    testFile.open("testy/input1.txt");

    if (testFile.is_open())
    {
        int attributeCounter = 0;
        struct fromFile loadTo;
        while (getline(testFile, line))
        {
            if(currentLineNumber % 7 == 0 && currentLineNumber != 0){
                saveStructToFile(writeTo, loadTo);
            }
            if (attributeCounter == 0)
            {
                loadTo.intVariable = stoi(line);
                attributeCounter++;
            }
            else if (attributeCounter == 1)
            {
                loadTo.stringVariable = line;
                attributeCounter++;
            }
            else if (attributeCounter == 2)
            {
                loadTo.charVariable = line.front();
                attributeCounter++;
            }
            else if (attributeCounter == 3)
            {
                int innerAttributeCounter = 0;
                string tempData = "";
                for (int i = 0; i < line.length() - 1; i++)
                {
                    if (line.at(i) != ' ' && i < line.length() - 2)
                    {
                        tempData += line.at(i);
                    }
                    else if (innerAttributeCounter == 0)
                    {
                        loadTo.subStruct1.boolVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 1)
                    {
                        loadTo.subStruct1.unsignedCharVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 2)
                    {
                        tempData += line.at(line.length() - 2);
                        loadTo.subStruct1.floatVariable = stof(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                }
                attributeCounter++;
            }
            else if (attributeCounter == 4)
            {
                int innerAttributeCounter = 0;
                string tempData = "";
                for (int i = 0; i < line.length() - 1; i++)
                {
                    if (line.at(i) != ' ' && i < line.length() - 2)
                    {
                        tempData += line.at(i);
                    }
                    else if (innerAttributeCounter == 0)
                    {
                        loadTo.subStruct2.boolVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 1)
                    {
                        loadTo.subStruct2.unsignedCharVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 2)
                    {
                        tempData += line.at(line.length() - 2);
                        loadTo.subStruct2.floatVariable = stof(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                }
                attributeCounter++;
            }
            else if (attributeCounter == 5)
            {
                int innerAttributeCounter = 0;
                string tempData = "";
                for (int i = 0; i < line.length() - 1; i++)
                {
                    if (line.at(i) != ' ' && i < line.length() - 2)
                    {
                        tempData += line.at(i);
                    }
                    else if (innerAttributeCounter == 0)
                    {
                        loadTo.subStruct3.boolVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 1)
                    {
                        loadTo.subStruct3.unsignedCharVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 2)
                    {
                        tempData += line.at(line.length() - 2);
                        loadTo.subStruct3.floatVariable = stof(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                }
                attributeCounter++;
            }
            else if (attributeCounter == 6)
            {
                int innerAttributeCounter = 0;
                string tempData = "";
                for (int i = 0; i < line.length() - 1; i++)
                {
                    if (line.at(i) != ' ' && i < line.length() - 2)
                    {
                        tempData += line.at(i);
                    }
                    else if (innerAttributeCounter == 0)
                    {
                        loadTo.subStruct4.boolVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 1)
                    {
                        loadTo.subStruct4.unsignedCharVariable = stoi(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                    else if (innerAttributeCounter == 2)
                    {
                        tempData += line.at(line.length() - 2);
                        loadTo.subStruct4.floatVariable = stof(tempData);
                        tempData = "";
                        innerAttributeCounter++;
                    }
                }
                attributeCounter = 0;
            }
            currentLineNumber++;
        }
        saveStructToFile(writeTo, loadTo);
    }
    else
    {
        cout << "File not found!";
    }
}

void clearFile(string filename){
    ofstream fileToClear;
    fileToClear.open(filename);
    fileToClear.close();
}

bool compareStructByInt(struct fromFile bigger, struct fromFile smaller){
    return bigger.intVariable>smaller.intVariable;
}

int getNumberOfStructInFile(string filename){
    int lineNumber = 0;

    ifstream testFile;
    string line;
    testFile.open("testy/input1.txt");

    if (testFile.is_open()){
        while (getline(testFile, line)){
            lineNumber++;
        }
    }
    else{
        cout << "Unable to open file";
    }

    return lineNumber/7;
}

void sortInt(string source, string pom1="", string pom2="")
{
    int structNumber = getNumberOfStructInFile(source);
    clearFile(pom1);

    struct fromFile smallestNumber;
    smallestNumber = loadToStructure(source, 0);
    for (int i=1; i<structNumber; i++){
        struct fromFile candidateNumber;
        candidateNumber = loadToStructure(source, i);
        if(candidateNumber.intVariable < smallestNumber.intVariable){
            smallestNumber = candidateNumber;
        }
    }
    saveStructToFile(pom1, smallestNumber);
}

int main()
{
    sortInt("testy/input1.txt", "getSmallestFromInput1.txt");
    return 0;
}