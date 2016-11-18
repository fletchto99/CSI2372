#ifndef CSI2372_TABLE_H
#define CSI2372_TABLE_H

#include <string>

class Table {

    Table(std::istream& file);

    bool win( std::string& );
    void print(std::ostream&);

};


#endif
