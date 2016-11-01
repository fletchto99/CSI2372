#include <iostream>

#include "text_entry.h"

using namespace std;


TextEntry::TextEntry(const string &_question) {
    d_question = _question;
}

int TextEntry::ask() {
    cout << d_question << " : ";
    cin >>  d_answer;
    return sizeof(d_answer);
}

string TextEntry::getResponse() {
    return std::string();
}

void TextEntry::print() {
    cout << d_question << " : " << d_answer << endl;
}

TextEntry::TextEntry() {}

NumberResponse::NumberResponse(const string &_question) : TextEntry(_question) {
    d_question = _question;
}


int NumberResponse::getNumber() {
    return d_number;
}

void NumberResponse::limitOff() {
    d_activeLim = !d_activeLim;
}

bool NumberResponse::limits(int _lowerLim, int _upperLim) {
    d_lowerLim = _lowerLim;
    d_upperLim = _upperLim;
    return d_number >= d_lowerLim && d_number <= d_upperLim;
}

bool NumberResponse::ask() {
    cout << d_question << " : ";
    cin >>  d_number;
    d_answer = to_string(d_number);;
    return d_number >= d_lowerLim && d_number <= d_upperLim;
}

void NumberResponse::print() {
    TextEntry::print();
}

NumberResponse::NumberResponse() {}

SelectionResponse::SelectionResponse(const string &_question, int numChoices) {
    d_question = _question;
    d_upperLim = numChoices;
    d_lowerLim = 0;
}

void SelectionResponse::print() {
    NumberResponse::print();
}

int SelectionResponse::getSelection() {
    return d_number;
}

int SelectionResponse::ask() {
    bool valid = false;
    while (!valid) {
        cout << d_question << " : ";
        cin >> d_number;
        d_answer = to_string(d_number);
        valid = d_number > d_lowerLim && d_number < d_upperLim;
    }
    return d_number;
}
