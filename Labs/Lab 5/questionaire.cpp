
#include "questionaire.h"

Questionaire::~Questionaire() {
    d_text.clear();
    d_number.clear();
    d_select.clear();

}

Questionaire::Questionaire(const Questionaire& _questionaire) {

    for(auto *question : _questionaire.d_text) {
        d_text.push_back(new TextEntry(*question));
    }

    for(auto *question : _questionaire.d_number) {
        d_number.push_back(new NumberResponse(*question));
    }

    for(auto *question : _questionaire.d_select) {
        d_select.push_back(new SelectionResponse(*question));
    }

}

void Questionaire::addTextEntry(const TextEntry &_text) {
    d_text.push_back(new TextEntry(_text));
}

void Questionaire::addNumberResponse(const NumberResponse &_text) {
    d_number.push_back(new NumberResponse(_text));
}

void Questionaire::addSelectionResponse(const SelectionResponse &_text) {
    d_select.push_back(new SelectionResponse(_text));
}

void Questionaire::conduct() {
    for(auto *text : d_text) {
        (*text).ask();
    }

    for(auto *num : d_number) {
        (*num).ask();
    }

    for(auto *sel : d_select) {
        (*sel).ask();
    }
}

void Questionaire::printAnswers() {

    for(auto *text : d_text) {
        (*text).print();
    }

    for(auto *num : d_number) {
        (*num).print();
    }

    for(auto *sel : d_select) {
        (*sel).print();
    }
}