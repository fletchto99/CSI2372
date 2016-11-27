#ifndef CSI2372_TABLE_H
#define CSI2372_TABLE_H

#include <string>

#include "Players.h"

class Table {
private:
    std::vector<Player*> players;
public:
    Table(std::istream& file);
    bool win( std::string& );
    void print(std::ostream&);

};


#endif
