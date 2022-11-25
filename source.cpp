#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct subStruct{
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

void structToString(struct fromFile toStringStructure){
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

struct fromFile loadToStructure(string filePath, int structNumber){
    struct fromFile loadedStructure;
    int currentLineNumber = 0;

    ifstream testFile1;
    string line;
    int attributeCounter = 0;
    testFile1.open("testy/input1.txt");
    if(testFile1.is_open()){
        while(getline(testFile1, line)){
            if(currentLineNumber/7<structNumber){
                currentLineNumber++;
            }
            else{
                if(attributeCounter==0){
                    loadedStructure.intVariable = stoi(line);
                    attributeCounter++;
                }
                else if(attributeCounter==1){
                    loadedStructure.stringVariable = line;
                    attributeCounter++;
                }
                else if(attributeCounter==2){
                    loadedStructure.charVariable = line.front();
                    attributeCounter++;
                }
                else if(attributeCounter == 3){
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for(int i=0; i<line.length()-1; i++){
                        if(line.at(i)!=' ' && i < line.length() - 2){
                            tempData+=line.at(i);
                        }
                        else if(innerAttributeCounter==0){
                            loadedStructure.subStruct1.boolVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==1){
                            loadedStructure.subStruct1.unsignedCharVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==2){
                            tempData += line.at(line.length()-2);
                            loadedStructure.subStruct1.floatVariable = stof(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if(attributeCounter == 4){
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for(int i=0; i<line.length()-1; i++){
                        if(line.at(i)!=' ' && i < line.length() - 2){
                            tempData+=line.at(i);
                        }
                        else if(innerAttributeCounter==0){
                            loadedStructure.subStruct2.boolVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==1){
                            loadedStructure.subStruct2.unsignedCharVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==2){
                            tempData += line.at(line.length()-2);
                            loadedStructure.subStruct2.floatVariable = stof(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if(attributeCounter == 5){
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for(int i=0; i<line.length()-1; i++){
                        if(line.at(i)!=' ' && i < line.length() - 2){
                            tempData+=line.at(i);
                        }
                        else if(innerAttributeCounter==0){
                            loadedStructure.subStruct3.boolVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==1){
                            loadedStructure.subStruct3.unsignedCharVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==2){
                            tempData += line.at(line.length()-2);
                            loadedStructure.subStruct3.floatVariable = stof(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
                else if(attributeCounter == 6){
                    int innerAttributeCounter = 0;
                    string tempData = "";
                    for(int i=0; i<line.length()-1; i++){
                        if(line.at(i)!=' ' && i < line.length()-2){
                            tempData+=line.at(i);
                        }
                        else if(innerAttributeCounter==0){
                            loadedStructure.subStruct4.boolVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==1){
                            loadedStructure.subStruct4.unsignedCharVariable = stoi(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                        else if(innerAttributeCounter==2){
                            tempData += line.at(line.length()-2);
                            loadedStructure.subStruct4.floatVariable = stof(tempData);
                            tempData="";
                            innerAttributeCounter++;
                        }
                    }
                    attributeCounter++;
                }
            }
        }
    }
    else{
        cout << "File not found!";
    }

    return loadedStructure;
}

int main(){
    struct fromFile testStructure1 = loadToStructure("testy/input1.txt", 1);
    structToString(testStructure1);
    return 0;
}