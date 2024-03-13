
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "Reportable.hpp"
#include "NumBoard.hpp"

void testBoard(Board & b, Reportable& r) {
    b.add("item 1");
    b.add("item 2");

    r.report(b);
}

void testNumBoard(NumBoard & nb, Reportable& r) {
    nb.addNum("item 1");
    nb.addNum("item 2");

    ReportStdout rso;
    r.report(nb);
}

int main() {

    Board b1;
    ReportStdout r1;

    testBoard(b1, r1);

    NumBoard nb;
    ReportFile r2("test2.txt");
    testNumBoard(nb,r2);

    testBoard(nb,r1);

    return 0;
}

