/* Sara Park
ID: 103387397
Date Created: 1/28/16
Assignment 2: Word Analysis
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct WordReps{
    string word;
    int number;
    bool operator<(const WordReps &rhs) const {
    return number > rhs.number;
    }
};



int Top50(string word){
//Check if word is part of the 50 most common English words
string Top50words[]={
"the","be","to","of","and","a","in","that","have","i","it","for","not","on",
"with","he","as","you","do","at","this","but","his","by","from","they","we",
"say","her","she","or","an","will","my","one","all","would","there","their",
"what","so","up","out","if","about","who","get","which","go","me"
};
bool tooCommon = false;
for (int i=0; i<=50; i++){
    if (word==Top50words[i]){
        tooCommon = true;
    }
}
return tooCommon;
}

WordReps *ArrayDynamicAllocation(WordReps *oldArray, int oldSize){

    int newSize = oldSize*2;
    WordReps *newArray = new WordReps[newSize];
        for(int j=0; j<oldSize; j++){
            newArray[j]= oldArray[j];

        }

        delete[] oldArray;

    return newArray;
}


int main(string filename, int n) {

ifstream inFile;
string data;
inFile.open("HungerGames_edit.txt");
n = 10;
WordReps *wordReps;
int numWord = 0;
int arraySize = 100;
wordReps = new WordReps[100];
int arrayDoubled = 0;
int totalWords = 0;

if (inFile.good()){
    //cout<<"The file has opened successfully"<<endl;


    while(getline(inFile,data)){

            stringstream ss(data);
            // divide lines to single words

            string inputWord;
            while(ss>>inputWord){

            bool tooCommon = Top50(inputWord);

            if(tooCommon == false){
                totalWords++;
                if(numWord==arraySize-1){
                        //cout<<"*****double now*****"<<endl;
                        wordReps = ArrayDynamicAllocation(wordReps, arraySize);
                        arraySize = 2*arraySize;
                        //cout<<arraySize<<endl;
                        arrayDoubled++;
                    }
                    bool match = false;
                for(int i=0; i<numWord;i++){
                    if (inputWord==wordReps[i].word){
                        match = true;
                        wordReps[i].number++;

                        break;
                    }
                }

                if (match==false){
                    wordReps[numWord].word=inputWord;
                    wordReps[numWord].number=1;
                    numWord++;
                    //cout<<numWord<<" word is:"<<wordReps[numWord].word<<endl;

                }



            }
            }




    }
}
else {
    cout<< "The message board has not opened successfully."<< endl;
}

sort(wordReps,wordReps+arraySize);
inFile.close();
for (int i=0; i<n; i++){
    cout<<wordReps[i].number<<" - "<<wordReps[i].word<<endl;
}
cout<<"#"<<endl;
cout<< "Array doubled: "<<arrayDoubled<<endl;
cout<<"#"<<endl;
cout<< "Unique non-common words: "<<numWord<<endl;
cout<<"#"<<endl;
cout<< "Total non-common words: "<<totalWords<<endl;

}
