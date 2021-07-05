#include <iostream>
#include <ctime>
#include "./set/set.h"
#include "./set/set.tpp"
#include "extrafunctions/extrafunctions.h"
#include "./person/person.h"

using namespace std;

const char *MENU_MAIN[] = {/*"Type of sets",*/
                           "Quit",
                           "Integer",
                           "Float",
                           "String",
                           "Person",
};
const int MENU_MAIN_SIZE = sizeof(MENU_MAIN) / sizeof(MENU_MAIN[0]);

const char *MENU_SECOND[] = {/*"Type of sets",*/
                           "Qiit",
                           "Back",
                           "First set generate",
                           "Second set generate",
                           "First set insert value",
                           "Second set insert value",
                           "Next menu"
};
const int MENU_SECOND_SIZE = sizeof(MENU_SECOND) / sizeof(MENU_SECOND[0]);

const char *MENU_THIRD[] = {/*"Actions",*/
                            "Back",
                            "First set max value",
                            "Second set max value",
                            "Union",
                            "Crossing",
                            "Subtraction (first set - second set)",
                            "Subtraction (second set - first set)",
                            "Subset inclusion check (second set in first set)",
                            "Subset inclusion check (first set in second set)",
                            "Equality check"
};
const int MENU_THIRD_SIZE = sizeof(MENU_THIRD) / sizeof(MENU_THIRD[0]);



int dialog(const char **msgs, int n) {
    int choice;
    char temp;
    do {
        std::cout << std::endl << std::endl;

        for (int i = 0; i < n; ++i)
            std::cout << i <<". "<< msgs[i] << std::endl;
        std::cout << "> " << std::endl;


        do {
            std::cin >> temp;

        } while (temp == '\n');

        choice = temp - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

//        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

template <typename T>
void second_menu(T set1, T set2) {

    int menu;
    do {
        menu = dialog(MENU_THIRD, MENU_THIRD_SIZE);

        switch(menu) {
            case 0: //Отмена
                break;
            case 1:
                cout << "\nOption 1 - First set max value\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << set1->GetMax();
                break;
            case 2:
                cout << "\nOption 2 - Second set max value\n";

                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << set2->GetMax();
                break;
            case 3:
                cout << "\nOption 3 - Union\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (*set1 + *set2) << endl;
                break;
            case 4:
                cout << "\nOption 4 - Crossing\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (*set1 * *set2) << endl;
                break;
            case 5:
                cout << "\nOption 5 - Subtraction (first set - second set)\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (*set1 - *set2) << endl;
                break;
            case 6:
                cout << "\nOption 6 - Subtraction (second set - first set)\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (*set2 - *set1) << endl;
                break;
            case 7:
                cout << "\nOption 7 - Subset inclusion check (second set in first set)\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (set1->CheckSubset(set2) ? "Second set is in first set" : "Second set is not in first set") << endl;
                break;
            case 8:
                cout << "\nOption 8 - Subset inclusion check (first set in second set)\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << (set2->CheckSubset(set1) ? "First set is in second set" : "First set is not in second set") << endl;
                break;
            case 9:
                cout << "\nOption 9 - Equality check\n";

                if (set1->GetLength() == 0) {
                    cout << "First set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                if (set2->GetLength() == 0) {
                    cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                    break;
                }
                cout << ((*set1 == *set2) ? "Sets are equals" : "Sets are not equal") << endl;
                break;
            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);
}

int main() {
//    srand(time(NULL));

    int mode;

    auto *setInt1 = new Set<int>;
    auto *setInt2 = new Set<int>;
    int nInt;

    auto *setFloat1 = new Set<float>;
    auto *setFloat2 = new Set<float>;
    float nFloat;

    auto *setString1 = new Set<string>;
    auto *setString2 = new Set<string>;
    string nString;

    auto *set1 = new Set<Person>;
    auto *set2 = new Set<Person>;
    Person nPerson;

    int menu = 0, menu2 = 0;
    do {

        menu = dialog(MENU_MAIN, MENU_MAIN_SIZE);

        switch (menu) {
            case 0: //Отмена
                break;
            case 1: {//integer
                do {
                    menu2 = dialog(MENU_SECOND, MENU_SECOND_SIZE);
                    mode = 0;
                    nInt = 0;
                    switch (menu2) {
                        case 0:
                            menu = 0;
                            menu2 = 0;
                            break;
                        case 1:
                            setInt1->Clear();
                            setInt2->Clear();
                            menu2 = 0;
                            break;
                        case 2:
                            if (setInt1->GetLength() != 0) setInt1->Clear();
                            cout << "Input number of elements: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setInt1->Generate(nInt, randomInt);
                            cout << "Generated first set:\n" << *setInt1 << endl;
                            break;
                        case 3:
                            if (setInt2->GetLength() != 0) setInt2->Clear();
                            cout << "Input number of elements: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setInt2->Generate(nInt, randomInt);
                            cout << "Generated second set:\n" << *setInt2 << endl;
                            break;

                        case 4:
                            cout << "Input element: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            setInt1->Insert(nInt);
                            cout << "Success!\n" << *setInt1 << endl;
                            break;
                        case 5:
                            cout << "Input element: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            setInt2->Insert(nInt);
                            cout << "Success!\n" << *setInt2 << endl;
                            break;
                        case 6: //next step
                            second_menu(setInt1, setInt2);
                            break;
                        default:
                            printf("***Error, please try again***\n");
                            break;
                    }
                } while (menu2 != 0);
            }

            case 2: {//double
                do {
                    menu2 = dialog(MENU_SECOND, MENU_SECOND_SIZE);
                    mode = 0;
                    nInt = 0;
                    switch (menu2) {
                        case 0:
                            menu = 0;
                            menu2 = 0;
                            break;
                        case 1:
                            setFloat1->Clear();
                            setFloat2->Clear();
                            menu2 = 0;
                            break;
                        case 2:
                            if (setFloat1->GetLength() != 0) setFloat1->Clear();
                            cout << "Input number of elements: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setFloat1->Generate(nInt, randomFloat);
                            cout << "Generated first set:\n" << *setFloat1 << endl;
                            break;
                        case 3:
                            if (setInt2->GetLength() != 0) setInt2->Clear();
                            cout << "Input number of elements: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setFloat2->Generate(nInt, randomFloat);
                            cout << "Generated second set:\n" << *setFloat2 << endl;
                            break;

                        case 4:
                            cout << "Input element: ";
                            mode = readFloat(nFloat);
                            if (mode != 0) {
                                break;
                            }
                            setFloat1->Insert(nFloat);
                            cout << "Success!\n" << *setFloat1 << endl;
                            break;
                        case 5:
                            cout << "Input element: ";
                            mode = readFloat(nFloat);
                            if (mode != 0) {
                                break;
                            }
                            setFloat2->Insert(nFloat);
                            cout << "Success!\n" << *setFloat2 << endl;
                            break;
                        case 6: //next step
                            second_menu(setFloat1, setFloat2);
                            break;
                        default:
                            printf("***Error, please try again***\n");
                            break;
                    }
                } while (menu2 != 0);
            }

            case 3: {//string
                do {
                    menu2 = dialog(MENU_SECOND, MENU_SECOND_SIZE);
                    mode = 0;
                    nInt = 0;
                    switch (menu2) {
                        case 0:
                            menu = 0;
                            menu2 = 0;
                            break;
                        case 1:
                            setString1->Clear();
                            setString2->Clear();
                            menu2 = 0;
                            break;
                        case 2:
                            if (setString1->GetLength() != 0) setString1->Clear();
                            cout << "Input number of elements: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setString1->Generate(nInt, randomString);
                            cout << "Generated first set:\n" << *setString1 << endl;
                            break;
                        case 3:
                            if (setString2->GetLength() != 0) setString2->Clear();
                            cout << "Input number of pieces: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            setString2->Generate(nInt, randomString);
                            cout << "Generated second set:\n" << *setString2 << endl;
                            break;

                        case 4:
                            cout << "Input element: ";
                            mode = readString(nString);
                            if (mode != 0) {
                                break;
                            }
                            setString1->Insert(nString);
                            cout << "Success!\n" << *setString1 << endl;
                            break;
                        case 5:
                            cout << "Input element: ";
                            mode = readString(nString);
                            if (mode != 0) {
                                break;
                            }
                            setString2->Insert(nString);
                            cout << "Success!\n" << *setString2 << endl;
                            break;
                        case 6: //next step
                            second_menu(setString1, setString2);
                            break;
                        default:
                            printf("***Error, please try again***\n");
                            break;
                    }
                } while (menu2 != 0);
            }

            case 4: {//person
                do {
                    menu2 = dialog(MENU_SECOND, MENU_SECOND_SIZE);
                    mode = 0;
                    nInt = 0;
                    switch (menu2) {
                        case 0:
                            menu = 0;
                            menu2 = 0;
                            break;
                        case 1:
                            setInt1->Clear();
                            setInt2->Clear();
                            menu2 = 0;
                            break;
                        case 2:
                            if (set1->GetLength() != 0) set1->Clear();
                            cout << "Input number of pieces: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            set1->Generate(nInt, randomPerson);
                            cout << "Generated first set:\n" << *set1 << endl;
                            break;
                        case 3:
                            if (set2->GetLength() != 0) set2->Clear();
                            cout << "Input number of pieces: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            if (nInt <= 0) {
                                cout << "The number must be positive.\n";
                                break;
                            }
                            set2->Generate(nInt, randomPerson);
                            cout << "Generated second set:\n" << *set2 << endl;
                            break;

                        case 4:
                            cout << "Input element: ";
                            mode = readPerson(nPerson);
                            if (mode != 0) {
                                break;
                            }
                            set1->Insert(nPerson);
                            cout << "Success!\n" << *set1 << endl;
                            break;
                        case 5:
                            cout << "Input element: ";
                            mode = readPerson(nPerson);
                            if (mode != 0) {
                                break;
                            }
                            set2->Insert(nPerson);
                            cout << "Success!\n" << *set2 << endl;
                            break;
                        case 6: //next step
                            second_menu(set1, set2);
                            break;
                        default:
                            printf("***Error, please try again***\n");
                            break;
                    }
                } while (menu2 != 0);
            }

            default:
                printf("***Error, please try again***\n");
            break;

        }
    } while (menu != 0);
}