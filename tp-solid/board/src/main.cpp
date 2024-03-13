
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"

void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    ReportStdout rso;
    rso.reportStdout(b);

    ReportFile rf("testBoard.txt");
    rf.reportFile(b);
}

int main() {

    Board b1("tmp.txt");
    testBoard(b1);

    return 0;
}

