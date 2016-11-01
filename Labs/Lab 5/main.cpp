
// ==========================================================================
// $Id: main.cpp,v 1.1 2016/10/14 22:19:53 jlang Exp $
// CSI2372 Lab Assignment 5 2016
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada.
//   http://www.eecs.uottawa.ca
//
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: main.cpp,v $
// Revision 1.1  2016/10/14 22:19:53  jlang
// Created Lab 5.
//
// ==========================================================================
#include <iostream>
#include <string>

#include "text_entry.h"
#include "questionaire.h"

using std::cout;
using std::endl;


int main() {
    // Make a questionaire
    Questionaire hotel;
    TextEntry t1("Hotel name");
    hotel.addTextEntry(t1);
    TextEntry t2("Room description");
    hotel.addTextEntry(t2);
    NumberResponse n1("Room number");
    hotel.addNumberResponse(n1);
    NumberResponse n2("Price");
    hotel.addNumberResponse(n2);
    SelectionResponse s("Number of guests (0-4)", 5);
    hotel.addSelectionResponse(s);

    Questionaire central(hotel);
    Questionaire standard(hotel);

    cout << "Hotel" << endl;
    cout << "---------------------------" << endl;
    central.conduct();
    cout << "Hotel" << endl;
    cout << "---------------------------" << endl;
    standard.conduct();

    cout << "---------------------------" << endl;
    central.printAnswers();
    cout << "---------------------------" << endl;
    standard.printAnswers();
    cout << "---------------------------" << endl;

    return 0;
}