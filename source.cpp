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
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 1)
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
                            tempData += line.at(line.length() - 1);
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
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 1)
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
                            tempData += line.at(line.length() - 1);
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
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 1)
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
                            tempData += line.at(line.length() - 1);
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
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (line.at(i) != ' ' && i < line.length() - 1)
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
                            tempData += line.at(line.length() - 1);
                            loadedStructure.subStruct4.floatVariable = stof(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
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

void clearFile(string filename)
{
    ofstream fileToClear;
    fileToClear.open(filename);
    fileToClear.close();
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

void appendFile(string targetFilePath, string text){

    ofstream targetFile(targetFilePath, ios::app);

    if(targetFile.is_open()){
        targetFile << text << endl; 
    }
    else{
        cout << "Unable to open file";
    }
}

void rewriteFile(string writeFrom, string writeTo)
{
    clearFile(writeTo);
    ifstream testFile;
    string line;
    testFile.open(writeFrom);

    if (testFile.is_open())
    {
        while (getline(testFile, line))
        {
            appendFile(writeTo, line);    
        }
    }
    else
    {
        cout << "Unable to open file";
    }
}

bool compareStructByInt(struct fromFile bigger, struct fromFile smaller)
{
    return bigger.intVariable > smaller.intVariable;
}

int getNumberOfStructInFile(string filename)
{
    int lineNumber = 0;

    ifstream testFile;
    string line;
    testFile.open("testy/input1.txt");

    if (testFile.is_open())
    {
        while (getline(testFile, line))
        {
            lineNumber++;
        }
    }
    else
    {
        cout << "Unable to open file";
    }

    return lineNumber / 7;
}

int getMinimum(string filepath, int startingStructNumber)
{
    int minimum;
    int minimumStructureNumber = startingStructNumber;

    int structNumber = getNumberOfStructInFile(filepath);

    for (int i = startingStructNumber; i < structNumber; i++)
    {
        if (i == startingStructNumber)
        {
            minimum = loadToStructure(filepath, i).intVariable;
        }
        else
        {
            int candidate = loadToStructure(filepath, i).intVariable;
            if (candidate < minimum)
            {
                minimum = candidate;
                minimumStructureNumber = i;
            }
        }
    }
    return minimumStructureNumber;
}

void swapStrucuresInFile(string sourcePath, string pom, int swapFromNumber, int swapStructureNumber)
{

    int structNumber = getNumberOfStructInFile(sourcePath);
    clearFile(pom);
    for (int i = 0; i < structNumber; i++)
    {
        if (i == swapFromNumber)
        {
            saveStructToFile(pom, loadToStructure(sourcePath, swapStructureNumber));
        }
        else if (i == swapStructureNumber)
        {
            saveStructToFile(pom, loadToStructure(sourcePath, swapFromNumber));
        }
        else
        {
            struct fromFile nextStructureToSave;
            nextStructureToSave = loadToStructure(sourcePath, i);
            saveStructToFile(pom, nextStructureToSave);
        }
    }
}

void sortInt(string sourcePath, string pom1 = "", string pom2 = "")
{
    int structureNumberInFile = getNumberOfStructInFile(sourcePath);
    for (int currentStructureNumber = 0; currentStructureNumber < structureNumberInFile; currentStructureNumber++)
    {
        int swapStrucureNumber = getMinimum(sourcePath, currentStructureNumber);
        swapStrucuresInFile(sourcePath, pom1, currentStructureNumber, swapStrucureNumber);
        rewriteFile(pom1, sourcePath);
    }
}

bool compareString(string higherAlfabetically, string lowerAlfabetically){
    if(higherAlfabetically.length()>lowerAlfabetically.length()){

        for(int i=0; i<lowerAlfabetically.length(); i++){
            int lowerCharToInt = tolower(lowerAlfabetically.at(i));
            int higherCharToInt = tolower(higherAlfabetically.at(i));
            if(lowerCharToInt>higherCharToInt){
                return false;
            }
            else{
                return true;
            }
        }
    }
    else{

        for(int i=0; i<higherAlfabetically.length(); i++){
            int lowerCharToInt = tolower(lowerAlfabetically.at(i));
            int higherCharToInt = tolower(higherAlfabetically.at(i));
            if(lowerCharToInt>higherCharToInt){
                return false;
            }
            else{
                return true;
            }
        }
    }
    return true;
}

int getLowestAlphabetically(string filepath, int startingStructure){
    int structuresInFile = getNumberOfStructInFile(filepath);
    string lowestString;
    int lowestStructureNumber;

    for(int i=startingStructure; i<structuresInFile; i++){
        if(i==startingStructure){
            struct fromFile firstStructure = loadToStructure(filepath, i);
            lowestString = firstStructure.stringVariable;
            lowestStructureNumber = i;
        }
        else{
            struct fromFile candidateStructure = loadToStructure(filepath, i);
            if(compareString(lowestString, candidateStructure.stringVariable)){
                lowestString = candidateStructure.stringVariable;
                lowestStructureNumber = i;
            }
        }
    }
    return lowestStructureNumber;
}

void sortString(string sourcePath, string pom1="", string pom2=""){
    int structuresInFile = getNumberOfStructInFile(sourcePath);
    for (int currentStructureNumber = 0; currentStructureNumber < structuresInFile; currentStructureNumber++)
    {
        int swapStrucureNumber = getLowestAlphabetically(sourcePath, currentStructureNumber);
        swapStrucuresInFile(sourcePath, pom1, currentStructureNumber, swapStrucureNumber);
        rewriteFile(pom1, sourcePath);
    }
}

int main()
{
    //sortInt("testy/input2.txt", "test_swap_structures_0_10.txt");
    sortString("testy/input2.txt", "test_sort_string.txt");
    return 0;
}