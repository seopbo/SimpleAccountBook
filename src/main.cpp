#include "../include/AccountBook.h"

int main() {
    AccountBook accountBook;
    accountBook.initialize();

    while (!accountBook.isProgramTerminate()) {
        MENU menu = accountBook.printAndGetMenu();
        switch (menu) {
            case (MENU::INPUT): {
                INPUT_MENU inputMenu = accountBook.printAndGetInputMenu();
                accountBook.runInput(inputMenu);
            }
                break;
            case (MENU::SPA): {
                accountBook.runSPA();
            }
                break;
            case (MENU::TERMINATE): {
                accountBook.setProgramTerminate();
            }
                break;
            default:
                break;
        }
    }
    return 0;
}