
#include <iostream>
using namespace std;

bool isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

bool isDigitChar(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

void identifyTokens(string input) {

    string keywords[] = {"cout", "cin", "int", "float", "double", "char",
                          "if", "else", "while", "for", "return", "void"};
    int keywordCount = 12;

    string operators[] = {"<<", ">>", "+", "-", "*", "/", "%",
                           "=", "==", "<", ">", "<=", ">=", "!="};
    int operatorCount = 14;

    char punctuations[] = {';', ',', '(', ')', '{', '}', '[', ']'};
    int punctuationCount = 8;

    int n = input.length();
    int pointer1 = 0;
    int pointer2 = 0;

    cout << "\nInput Statement: " << input << "\n";
    cout << "----------------------------------------\n";
    cout << "Token\t\tType\n";
    cout << "----------------------------------------\n";

    while (pointer2 < n) {

        if (input[pointer2] == ' ' || input[pointer2] == '\t') {
            pointer2++;
            pointer1 = pointer2;
            continue;
        }

        if (isLetter(input[pointer2])) {
            pointer1 = pointer2;
            while (pointer2 < n && (isLetter(input[pointer2]) || isDigitChar(input[pointer2]) || input[pointer2] == '_')) {
                pointer2++;
            }
            string word = input.substr(pointer1, pointer2 - pointer1);

            bool isKeyword = false;
            for (int i = 0; i < keywordCount; i++) {
                if (word == keywords[i]) {
                    isKeyword = true;
                    break;
                }
            }

            if (isKeyword)
                cout << word << "\t\tKeyword\n";
            else
                cout << word << "\t\tIdentifier\n";

            pointer1 = pointer2;
            continue;
        }

        if (isDigitChar(input[pointer2])) {
            pointer1 = pointer2;
            while (pointer2 < n && (isDigitChar(input[pointer2]) || input[pointer2] == '.')) {
                pointer2++;
            }
            string num = input.substr(pointer1, pointer2 - pointer1);
            cout << num<<"\t\tConstant\n";
            pointer1 = pointer2;
            continue;
        }

        bool operatorFound = false;
        if (pointer2 + 1 < n) {
            string twoChar = input.substr(pointer2, 2);
            for (int i = 0; i < operatorCount; i++) {
                if (twoChar == operators[i]) {
                    cout << twoChar << "\t\tOperator\n";
                    pointer2 += 2;
                    pointer1 = pointer2;
                    operatorFound = true;
                    break;
                }
            }
        }
        if (operatorFound) continue;

        string oneChar(1, input[pointer2]);
        bool isOperator = false;
        for (int i = 0; i < operatorCount; i++) {
            if (oneChar == operators[i]) {
                cout << oneChar << "\t\tOperator\n";
                isOperator = true;
                pointer2++;
                pointer1 = pointer2;
                break;
            }
        }
        if (isOperator) continue;

        bool isPunctuation = false;
        for (int i = 0; i < punctuationCount; i++) {
            if (input[pointer2] == punctuations[i]) {
                cout << input[pointer2] << "\t\tPunctuation\n";
                isPunctuation = true;
                pointer2++;
                pointer1 = pointer2;
                break;
            }
        }
        if (isPunctuation) continue;

        cout << input[pointer2] << "\t\tInvalid Token\n";
        pointer2++;
        pointer1 = pointer2;
    }

    cout << "----------------------------------------\n";
}

int main() {
    string statement;

    cout << "Enter a statement: ";
    getline(cin, statement);

    identifyTokens(statement);

    return 0;
}
