#include "gemstones.h"

int Quartz::getCoinsForCards(int cards) {
    if (cards >= 4 && cards < 6) {
        return 1;
    } else if (cards >= 6 && cards < 8) {
        return 2;
    } else if (cards >= 8 && cards < 10) {
        return 3;
    } else if (cards >= 10) {
        return 4;
    }
    return 0;
}

std::string Quartz::getName() {
    return "Quartz";

}

void Quartz::print(std::ostream &out) {
    out << " Q ";
}


int Hematite::getCoinsForCards(int cards) {
    if (cards >= 3 && cards < 6) {
        return 1;
    } else if (cards >= 6 && cards < 8) {
        return 2;
    } else if (cards >= 8) {
        return 3;
    } else if (cards >= 9) {
        return 4;
    }
    return 0;
}

std::string Hematite::getName() {
    return "Hematite";
}

void Hematite::print(std::ostream &out) {
    out << " H ";
}

int Obsidian::getCoinsForCards(int cards) {
    if (cards >= 3 && cards < 5) {
        return 1;
    } else if (cards >= 5 && cards < 7) {
        return 2;
    } else if (cards >= 7) {
        return 3;
    } else if (cards >= 8) {
        return 4;
    }
    return 0;
}

std::string Obsidian::getName() {
    return "Obsidian";
}

void Obsidian::print(std::ostream &out) {
    out << " O ";
}

int Malachite::getCoinsForCards(int cards) {
    if (cards >= 3 && cards < 5) {
        return 1;
    } else if (cards >= 5) {
        return 2;
    } else if (cards >= 6) {
        return 3;
    } else if (cards >= 7) {
        return 4;
    }
    return 0;
}

std::string Malachite::getName() {
    return "Malachite";
}

void Malachite::print(std::ostream &out) {
    out << " M ";
}

int Turquoise::getCoinsForCards(int cards) {
    if (cards >= 2 && cards < 4) {
        return 1;
    } else if (cards >= 4 && cards < 6) {
        return 2;
    } else if (cards >= 6) {
        return 3;
    } else if (cards >= 7) {
        return 4;
    }
    return 0;
}

std::string Turquoise::getName() {
    return "Turquoise";
}

void Turquoise::print(std::ostream &out) {
    out << " T " ;
}

int Ruby::getCoinsForCards(int cards) {
    if (cards >= 2) {
        return 1;
    } else if (cards >= 4) {
        return 2;
    } else if (cards >= 5) {
        return 3;
    } else if (cards >= 6) {
        return 4;
    }
    return 0;
}

std::string Ruby::getName() {
    return "Ruby";
}

void Ruby::print(std::ostream &out) {
    out << " R ";
}

int Amethyst::getCoinsForCards(int cards) {
    if (cards >= 2) {
        return 1;
    } else if (cards >= 3) {
        return 2;
    } else if (cards >= 4) {
        return 3;
    } else if (cards >= 5) {
        return 4;
    }
    return 0;
}

std::string Amethyst::getName() {
    return "Amethyst";
}

void Amethyst::print(std::ostream &out) {
    out << " A " ;
}

int Emerald::getCoinsForCards(int cards) {
    if (cards >= 2) {
        return 2;
    } else if (cards >= 3) {
        return 3;
    }
    return 0;
}

std::string Emerald::getName() {
    return "Emerald";
}

void Emerald::print(std::ostream &out) {
    out << " E " ;
}