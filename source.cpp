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

int stringToInt(string convertedString)
{
    for (int i = 0; i < convertedString.length(); i++)
    {
        if (convertedString.at(i) == '\r' || convertedString.at(i) == '\n')
        {
            convertedString = convertedString.substr(0, i);
        }
    }
    int returnInt = 0;
    int multiplier = 1;
    for (int i = convertedString.length(); i != 0; i--)
    {
        returnInt += (convertedString.at(i - 1) - '0') * multiplier;
        multiplier *= 10;
    }
    return returnInt;
}

float stringToFloat(string convertedString)
{
    float returnFloat = 0;
    if (convertedString.find('.') != std::string::npos)
    {
        string intPart;
        string floatPart;
        for (int i = 0; i < convertedString.length() - 1; i++)
        {
            if (convertedString.at(i) == '.')
            {
                intPart = convertedString.substr(0, i);
                floatPart = convertedString.substr(i + 1);
            }
        }
        float intPartConverted = (float)stringToInt(intPart);

        for (int i = 0; i < floatPart.length(); i++)
        {
            if (floatPart.at(i) == '\r' || floatPart.at(i) == '\n')
            {
                floatPart = floatPart.substr(0, i);
            }
        }
        float multiplier = 0.1;
        for (int i = 0; i < floatPart.length(); i++)
        {
            returnFloat += (floatPart.at(i) - '0') * multiplier;
            multiplier /= 10;
        }
        returnFloat += intPartConverted;
    }
    else{
        returnFloat = (float) stringToInt(convertedString);
    }
    return returnFloat;
}

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

struct fromFile loadStructure(string filePath, int structNumber)
{
    struct fromFile loadedStructure;
    int currentLineNumber = 0;

    fstream testFile;
    string line;
    int attributeCounter = 0;
    testFile.open(filePath.c_str(), ios::in | ios_base::binary);

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
                    loadedStructure.intVariable = stringToInt(line);
                    attributeCounter++;
                }
                else if (attributeCounter == 1)
                {
                    loadedStructure.stringVariable = line;
                    attributeCounter++;
                }
                else if (attributeCounter == 2)
                {
                    loadedStructure.charVariable = line.at(0);
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
                            loadedStructure.subStruct1.boolVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct1.unsignedCharVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 1);
                            loadedStructure.subStruct1.floatVariable = stringToFloat(tempData);
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
                            loadedStructure.subStruct2.boolVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct2.unsignedCharVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 1);
                            loadedStructure.subStruct2.floatVariable = stringToFloat(tempData);
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
                            loadedStructure.subStruct3.boolVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct3.unsignedCharVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 1);
                            loadedStructure.subStruct3.floatVariable = stringToFloat(tempData);
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
                            loadedStructure.subStruct4.boolVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 1)
                        {
                            loadedStructure.subStruct4.unsignedCharVariable = stringToInt(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                        else if (innerAttributeCounter == 2)
                        {
                            tempData += line.at(line.length() - 1);
                            loadedStructure.subStruct4.floatVariable = stringToFloat(tempData);
                            tempData = "";
                            innerAttributeCounter++;
                        }
                    }
                    break;
                }
            }
        }
    }
    return loadedStructure;
}

void clearFile(string filename)
{
    fstream fileToClear;

    fileToClear.open(filename.c_str(), ios::out | ios_base::binary);
    fileToClear.close();
}

void appendStructToFile(string filename, struct fromFile structToSave)
{
    fstream fileToSave;
    fileToSave.open(filename.c_str(), ios::app | ios_base::binary);
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
}

void appendFile(string targetFilePath, string text)
{
    fstream targetFile;
    targetFile.open(targetFilePath.c_str(), ios::app | ios_base::binary);

    if (targetFile.is_open())
    {
        targetFile << text << endl;
    }
}

void rewriteFile(string writeFrom, string writeTo)
{
    clearFile(writeTo);
    fstream testFile;
    string line;
    testFile.open(writeFrom.c_str(), ios::in | ios_base::binary);

    if (testFile.is_open())
    {
        while (getline(testFile, line))
        {
            appendFile(writeTo, line);
        }
    }
}

bool compareStructByInt(struct fromFile bigger, struct fromFile smaller)
{
    return bigger.intVariable > smaller.intVariable;
}

int getNumberOfStructInFile(string filename)
{
    int lineNumber = 0;

    fstream testFile;
    string line;
    testFile.open(filename.c_str(), ios::in | ios_base::binary);

    if (testFile.is_open())
    {
        while (getline(testFile, line))
        {
            lineNumber++;
        }
    }

    return lineNumber / 7;
}

int getMinimum(string filepath, int startingStructNumber)
{
    int minimum;
    int minimumStructureNumber = startingStructNumber;

    int structNumber = getNumberOfStructInFile(filepath.c_str());

    for (int i = startingStructNumber; i < structNumber; i++)
    {
        if (i == startingStructNumber)
        {
            minimum = loadStructure(filepath.c_str(), i).intVariable;
        }
        else
        {
            int candidate = loadStructure(filepath.c_str(), i).intVariable;
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
            appendStructToFile(pom, loadStructure(sourcePath, swapStructureNumber));
        }
        else if (i == swapStructureNumber)
        {
            appendStructToFile(pom, loadStructure(sourcePath, swapFromNumber));
        }
        else
        {
            struct fromFile nextStructureToSave;
            nextStructureToSave = loadStructure(sourcePath, i);
            appendStructToFile(pom, nextStructureToSave);
        }
    }
}

void SortInt(string sourcePath, string pom1, string pom2 = "")
{
    int structureNumberInFile = getNumberOfStructInFile(sourcePath);
    for (int currentStructureNumber = 0; currentStructureNumber < structureNumberInFile; currentStructureNumber++)
    {
        int swapStrucureNumber = getMinimum(sourcePath, currentStructureNumber);
        if (swapStrucureNumber != currentStructureNumber)
        {
            swapStrucuresInFile(sourcePath, pom1, currentStructureNumber, swapStrucureNumber);
            rewriteFile(pom1, sourcePath);
        }
    }
}

bool compareString(string higherAlfabetically, string lowerAlfabetically)
{
    if (higherAlfabetically.length() > lowerAlfabetically.length())
    {

        for (int i = 0; i < lowerAlfabetically.length(); i++)
        {
            int lowerCharToInt = tolower(lowerAlfabetically.at(i));
            int higherCharToInt = tolower(higherAlfabetically.at(i));
            if (lowerCharToInt > higherCharToInt)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    else
    {

        for (int i = 0; i < higherAlfabetically.length(); i++)
        {
            int lowerCharToInt = tolower(lowerAlfabetically.at(i));
            int higherCharToInt = tolower(higherAlfabetically.at(i));
            if (lowerCharToInt > higherCharToInt)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    return true;
}

int getLowestAlphabetically(string filepath, int startingStructure)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    string lowestString;
    int lowestStructureNumber;

    for (int i = startingStructure; i < structuresInFile; i++)
    {
        if (i == startingStructure)
        {
            struct fromFile firstStructure = loadStructure(filepath.c_str(), i);
            lowestString = firstStructure.stringVariable;
            lowestStructureNumber = i;
        }
        else
        {
            struct fromFile candidateStructure = loadStructure(filepath.c_str(), i);
            if (compareString(lowestString, candidateStructure.stringVariable))
            {
                lowestString = candidateStructure.stringVariable;
                lowestStructureNumber = i;
            }
        }
    }
    return lowestStructureNumber;
}

void SortString(string sourcePath, string pom1, string pom2 = "")
{
    int structuresInFile = getNumberOfStructInFile(sourcePath);
    for (int currentStructureNumber = 0; currentStructureNumber < structuresInFile; currentStructureNumber++)
    {
        int swapStrucureNumber = getLowestAlphabetically(sourcePath, currentStructureNumber);
        if (swapStrucureNumber != currentStructureNumber)
        {
            swapStrucuresInFile(sourcePath, pom1, currentStructureNumber, swapStrucureNumber);
            rewriteFile(pom1, sourcePath);
        }
    }
}

int countIntOccurence(string filepath, int structureNumber)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile countedStructure = loadStructure(filepath.c_str(), structureNumber);
    int occurenceCounter = 0;
    for (int i = 0; i < structuresInFile; i++)
    {
        struct fromFile candidateStructure = loadStructure(filepath.c_str(), i);
        if (candidateStructure.intVariable == countedStructure.intVariable)
        {
            occurenceCounter++;
        }
    }
    return occurenceCounter;
}

int countCharSum1(string filepath, int structureNumber)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile summedStructure = loadStructure(filepath.c_str(), structureNumber);

    return summedStructure.subStruct1.unsignedCharVariable;
}
int countCharSum2(string filepath, int structureNumber)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile summedStructure = loadStructure(filepath.c_str(), structureNumber);

    return summedStructure.subStruct1.unsignedCharVariable +
           summedStructure.subStruct2.unsignedCharVariable;
}
int countCharSum3(string filepath, int structureNumber)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile summedStructure = loadStructure(filepath.c_str(), structureNumber);

    return summedStructure.subStruct1.unsignedCharVariable +
           summedStructure.subStruct2.unsignedCharVariable +
           summedStructure.subStruct3.unsignedCharVariable;
}
int countCharSum4(string filepath, int structureNumber)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile summedStructure = loadStructure(filepath.c_str(), structureNumber);

    return summedStructure.subStruct1.unsignedCharVariable +
           summedStructure.subStruct2.unsignedCharVariable +
           summedStructure.subStruct3.unsignedCharVariable +
           summedStructure.subStruct4.unsignedCharVariable;
}

int getHighestCount(string filepath, int startingStructure)
{
    int structuresInFile = getNumberOfStructInFile(filepath.c_str());
    struct fromFile highestStructure;
    int highestOccurence;
    int highestCharSum1;
    int highestCharSum2;
    int highestCharSum3;
    int highestCharSum4;
    int highestOccurenceStructureNumber;

    for (int i = startingStructure; i < structuresInFile; i++)
    {
        if (i == startingStructure)
        {
            highestStructure = loadStructure(filepath.c_str(), i);
            highestOccurence = countIntOccurence(filepath.c_str(), i);
            highestOccurenceStructureNumber = i;
            highestCharSum1 = countCharSum1(filepath.c_str(), i);
            highestCharSum2 = countCharSum2(filepath.c_str(), i);
            highestCharSum3 = countCharSum3(filepath.c_str(), i);
            highestCharSum4 = countCharSum4(filepath.c_str(), i);
        }
        else
        {
            struct fromFile candidate = loadStructure(filepath.c_str(), i);
            int occurenceForCandidate = countIntOccurence(filepath.c_str(), i);
            int candidateCharSum1 = candidateCharSum1;
            int candidateCharSum2 = candidateCharSum2;
            int candidateCharSum3 = candidateCharSum3;
            int candidateCharSum4 = candidateCharSum4;
            if (occurenceForCandidate > highestOccurence)
            {
                highestStructure = loadStructure(filepath.c_str(), i);
                highestOccurence = countIntOccurence(filepath.c_str(), i);
                highestOccurenceStructureNumber = i;
                highestCharSum1 = candidateCharSum1;
                highestCharSum2 = candidateCharSum2;
                highestCharSum3 = candidateCharSum3;
                highestCharSum4 = candidateCharSum4;
            }
            else if (candidate.intVariable > highestStructure.intVariable && occurenceForCandidate == highestOccurence)
            {
                highestStructure = loadStructure(filepath.c_str(), i);
                highestOccurence = countIntOccurence(filepath.c_str(), i);
                highestOccurenceStructureNumber = i;
                highestCharSum1 = candidateCharSum1;
                highestCharSum2 = candidateCharSum2;
                highestCharSum3 = candidateCharSum3;
                highestCharSum4 = candidateCharSum4;
            }
            else if (candidate.intVariable == highestStructure.intVariable 
            && occurenceForCandidate == highestOccurence 
            && candidate.intVariable == highestStructure.intVariable)
            {
                if (candidateCharSum1 > highestCharSum1)
                {
                    highestStructure = loadStructure(filepath.c_str(), i);
                    highestOccurence = countIntOccurence(filepath.c_str(), i);
                    highestOccurenceStructureNumber = i;
                    highestCharSum1 = candidateCharSum1;
                    highestCharSum2 = candidateCharSum2;
                    highestCharSum3 = candidateCharSum3;
                    highestCharSum4 = candidateCharSum4;
                }
            }
            else if (candidate.intVariable == highestStructure.intVariable 
            && occurenceForCandidate == highestOccurence 
            && candidate.intVariable == highestStructure.intVariable 
            && candidateCharSum1 == highestCharSum1)
            {
                if (candidateCharSum2 > highestCharSum2)
                {
                    highestStructure = loadStructure(filepath.c_str(), i);
                    highestOccurence = countIntOccurence(filepath.c_str(), i);
                    highestOccurenceStructureNumber = i;
                    highestCharSum1 = candidateCharSum1;
                    highestCharSum2 = candidateCharSum2;
                    highestCharSum3 = candidateCharSum3;
                    highestCharSum4 = candidateCharSum4;
                }
            }
            else if (candidate.intVariable == highestStructure.intVariable 
            && occurenceForCandidate == highestOccurence 
            && candidate.intVariable == highestStructure.intVariable 
            && candidateCharSum1 == highestCharSum1 
            && candidateCharSum2 == highestCharSum2)
            {
                if (candidateCharSum3 > highestCharSum3)
                {
                    highestStructure = loadStructure(filepath.c_str(), i);
                    highestOccurence = countIntOccurence(filepath.c_str(), i);
                    highestOccurenceStructureNumber = i;
                    highestCharSum1 = candidateCharSum1;
                    highestCharSum2 = candidateCharSum2;
                    highestCharSum3 = candidateCharSum3;
                    highestCharSum4 = candidateCharSum4;
                }
            }
            else if (candidate.intVariable == highestStructure.intVariable 
            && occurenceForCandidate == highestOccurence 
            && candidate.intVariable == highestStructure.intVariable 
            && candidateCharSum1 == highestCharSum1 
            && candidateCharSum2 == highestCharSum2 
            && candidateCharSum3 == highestCharSum3)
            {
                if (candidateCharSum4 > highestCharSum4)
                {
                    highestStructure = loadStructure(filepath.c_str(), i);
                    highestOccurence = countIntOccurence(filepath.c_str(), i);
                    highestOccurenceStructureNumber = i;
                    highestCharSum1 = candidateCharSum1;
                    highestCharSum2 = candidateCharSum2;
                    highestCharSum3 = candidateCharSum3;
                    highestCharSum4 = candidateCharSum4;
                }
            }
        }
    }
    return highestOccurenceStructureNumber;
}

void SortCount(string sourcePath, string pom1, string pom2 = "")
{
    int structuresInFile = getNumberOfStructInFile(sourcePath);
    for (int currentStructureNumber = 0; currentStructureNumber < structuresInFile; currentStructureNumber++)
    {
        int swapStrucureNumber = getHighestCount(sourcePath, currentStructureNumber);
        if (swapStrucureNumber != currentStructureNumber)
        {
            struct fromFile swapStruct = loadStructure(sourcePath, swapStrucureNumber);
            swapStrucuresInFile(sourcePath, pom1, currentStructureNumber, swapStrucureNumber);
            rewriteFile(pom1, sourcePath);
        }
    }
}

bool compareStructures(struct fromFile structOne, struct fromFile structTwo)
{
    if (structOne.intVariable != structTwo.intVariable)
    {
        return false;
    }
    else if (structOne.stringVariable != structTwo.stringVariable)
    {
        return false;
    }
    else if (structOne.charVariable != structTwo.charVariable)
    {
        return false;
    }
    else if (structOne.subStruct1.boolVariable != structTwo.subStruct1.boolVariable)
    {
        return false;
    }
    else if (structOne.subStruct1.unsignedCharVariable != structTwo.subStruct1.unsignedCharVariable)
    {
        return false;
    }
    else if (structOne.subStruct1.floatVariable != structTwo.subStruct1.floatVariable)
    {
        return false;
    }
    else if (structOne.subStruct2.boolVariable != structTwo.subStruct2.boolVariable)
    {
        return false;
    }
    else if (structOne.subStruct2.unsignedCharVariable != structTwo.subStruct2.unsignedCharVariable)
    {
        return false;
    }
    else if (structOne.subStruct2.floatVariable != structTwo.subStruct2.floatVariable)
    {
        return false;
    }
    else if (structOne.subStruct3.boolVariable != structTwo.subStruct3.boolVariable)
    {
        return false;
    }
    else if (structOne.subStruct3.unsignedCharVariable != structTwo.subStruct3.unsignedCharVariable)
    {
        return false;
    }
    else if (structOne.subStruct3.floatVariable != structTwo.subStruct3.floatVariable)
    {
        return false;
    }
    else if (structOne.subStruct4.boolVariable != structTwo.subStruct4.boolVariable)
    {
        return false;
    }
    else if (structOne.subStruct4.unsignedCharVariable != structTwo.subStruct4.unsignedCharVariable)
    {
        return false;
    }
    else if (structOne.subStruct4.floatVariable != structTwo.subStruct4.floatVariable)
    {
        return false;
    }
    return true;
}

void removeStructureFromFile(string filename, string pom1, int structNumber)
{
    int structNumberInFile = getNumberOfStructInFile(filename.c_str());
    clearFile(pom1);

    for (int i = 0; i < structNumberInFile; i++)
    {
        if (i != structNumber)
        {
            struct fromFile structureToSave = loadStructure(filename.c_str(), i);
            appendStructToFile(pom1, structureToSave);
        }
    }

    rewriteFile(pom1, filename.c_str());
}

bool structureInFile(struct fromFile structFromFile, string filepath)
{
    int structNumberInFile = getNumberOfStructInFile(filepath.c_str());

    for (int i = 0; i < structNumberInFile; i++)
    {
        struct fromFile candidateStructure = loadStructure(filepath.c_str(), i);
        if (compareStructures(candidateStructure, structFromFile))
        {
            return true;
        }
    }
    return false;
}

void SymmetricDifference(string fileAppendTo, string fileRemoveFrom, string pom1)
{
    int structuresInFile = getNumberOfStructInFile(fileRemoveFrom);
    for (int currentStructureNumber = 0; currentStructureNumber < structuresInFile; currentStructureNumber++)
    {
        struct fromFile candidate = loadStructure(fileRemoveFrom, currentStructureNumber);
        if (!structureInFile(candidate, fileAppendTo))
        {
            appendStructToFile(fileAppendTo, candidate);
            removeStructureFromFile(fileRemoveFrom, pom1, currentStructureNumber);
            structuresInFile = getNumberOfStructInFile(fileRemoveFrom);
            currentStructureNumber--;
        }
    }
}