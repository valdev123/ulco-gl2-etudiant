
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "NumBoard.hpp"

void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    ReportStdout rso;
    rso.reportStdout(b);

    ReportFile rf("testBoard.txt");
    rf.reportFile(b);
}

void testNumBoard(NumBoard & nb) {
    std::cout << nb.getTitle() << std::endl;
    nb.addNum("item 1");
    nb.addNum("item 2");

    ReportStdout rso;
    rso.reportStdout(nb);
}

int main() {

    Board b1;
    testBoard(b1);

    NumBoard nb;
    testNumBoard(nb);

    return 0;
}

