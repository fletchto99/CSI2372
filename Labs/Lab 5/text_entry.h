// ==========================================================================
// $Id: text_entry.h,v 1.1 2016/10/14 22:19:53 jlang Exp $
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
// $Log: text_entry.h,v $
// Revision 1.1  2016/10/14 22:19:53  jlang
// Created Lab 5.
//
// ==========================================================================
#ifndef _TextEntry_h_
#define _TextEntry_h_

#include <string>

using std::string;


/**
 * Base TextEntry
 */
class TextEntry {
protected:
    string d_question;
    string d_answer;
public:
    TextEntry( const string& _question );

    TextEntry();

    // show question and record answer; returns the length of the answer
    int ask();
    // get the current answer
    string getResponse();
    // print question and answer
    void print();
};

/**
 * Entry that takes a number as reponse
 */
class NumberResponse : public TextEntry {
protected:
    int d_number;
    int d_upperLim;
    int d_lowerLim;
    bool d_activeLim;
public:
    NumberResponse( const string& _question );

    NumberResponse();

    // show question and record answer; returns true if entered number is within the limits
    bool ask();
    // sets the limits; returns true if current number is within the limits (inclusive)
    bool limits( int _lowerLim, int _upperLim );
    // turn limits off
    void limitOff();
    // accessor: get the current answer
    int getNumber();
    // print question and answer
    void print();
};

/**
 * Entry that allows for a selection of 0 ... numChoices-1
 */
class SelectionResponse : public NumberResponse {
public:
    SelectionResponse( const string& _question, int numChoices );
    // show question and record answer; returns the answer
    // will ask until a valid choice is made
    int ask();
    // accessor: get the current answer
    int getSelection();
    // print question and answer
    void print();
};

#endif