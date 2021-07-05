#include <iostream>
#include <ctime>
#include "./set/set.h"
#include "./set/set.tpp"
#include "extrafunctions/extrafunctions.h"
#include "./person/person.h"

//#include "complex.h"
using namespace std;

const char *MSGS_TYPE[] = {"Which type of function do you need?",
                           "0. Quit",
                           "1. Make integer sets",
                           "2. Make float sets",
                           "3. Make complex sets",
                           "4. Make string sets",
                           "5. Make person sets",
};
const int MSGS_TYPE_SIZE = sizeof(MSGS_TYPE) / sizeof(MSGS_TYPE[0]);

const char *MSGS[] = {"What do you want to do?",
                      "0. Quit",
                      "1. To previous step",
                      "2. First set generate (max n elements)",
                      "3. Second set generate (max n elements)",
                      "4. First set max value",
                      "5. Second set max value",
                      "6. First set insert value",
                      "7. Second set insert value",
                      "8. Union",
                      "9. Crossing",
                      "10. Subtraction (first set - second set)",
                      "11. Subtraction (second set - first set)",
                      "12. Subset inclusion check (second set in first set)",
                      "13. Subset inclusion check (first set in second set)",
                      "14. Equality check",
};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        cout << error << endl;
        error = "Incorrect input. Please, enter one positive integer number.\n";
        for (int i = 0; i < n; ++i) {
            cout << msgs[i] << endl;
        }
        cout << "Make your choice: ";
        choice = getchar() - '0';
        char c = getchar();
        while (c != '\n') {
            if (0 <= (int)c - '0' && (int)c - '0' <= 9)
                choice = choice * 10 + (c - '0');
            c = getchar();
        }
    } while (choice < 0 || choice >= n);
    return choice;
}

int main() {
    srand(time(NULL));
    int cmd = 0;
    int cmd_action = 0;

    int mode;

    auto *setInt1 = new Set<int>;
    auto *setInt2 = new Set<int>;
    int nInt;

    auto *setFloat1 = new Set<float>;
    auto *setFloat2 = new Set<float>;
    float nFloat;

//    Set<Complex> *setComplex1 = new Set<Complex>;
//    Set<Complex> *setComplex2 = new Set<Complex>;
//    Complex nComplex;

    auto *setString1 = new Set<string>;
    auto *setString2 = new Set<string>;
    string nString;

    auto *set1 = new Set<Person>;
    auto *set2 = new Set<Person>;
    Person nPerson;

    cout << "Hello! I've made a little program for working with sets. You are welcome :)\n";
    do {
        cmd = dialog(MSGS_TYPE, MSGS_TYPE_SIZE);
        switch(cmd) {
            case 0:
                cout << "Goodbye! :)";
                break;
            case 1:
                cout << "\nOption 1 - Integer sets\n";
                cmd_action = 0;
                do {
                    cmd_action = dialog(MSGS, MSGS_SIZE);
                    mode = 0;
                    nInt = 0;
                    switch (cmd_action) {
                        case 0:
                            cout << "Goodbye! :)";
                            cmd = 0;
                            cmd_action = 0;
                            break;
                        case 1:
                            setInt1->Clear();
                            setInt2->Clear();
                            cmd_action = 0;
                            break;
                        case 2:
                            cout << "\nOption 2 - First set generate (max n elements)\n";

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
                            cout << "\nOption 3 - Second set generate (max n elements)\n";

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
                            cout << "\nOption 4 - First set max value\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setInt1->GetMax();
                            break;
                        case 5:
                            cout << "\nOption 5 - Second set max value\n";

                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setInt2->GetMax();
                            break;
                        case 6:
                            cout << "\nOption 6 - First set insert value\n";

                            cout << "Input elemet: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            setInt1->Insert(nInt);
                            cout << "Success!\n" << *setInt1 << endl;
                            break;
                        case 7:
                            cout << "\nOption 7 - Second set insert value\n";

                            cout << "Input elemet: ";
                            mode = readInt(nInt);
                            if (mode != 0) {
                                break;
                            }
                            setInt2->Insert(nInt);
                            cout << "Success!\n" << *setInt2 << endl;
                            break;
                        case 8:
                            cout << "\nOption 8 - Union\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setInt1 + *setInt2) << endl;
                            break;
                        case 9:
                            cout << "\nOption 9 - Crossing\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setInt1 * *setInt2) << endl;
                            break;
                        case 10:
                            cout << "\nOption 10 - Subtraction (first set - second set)\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setInt1 - *setInt2) << endl;
                            break;
                        case 11:
                            cout << "\nOption 11 - Subtraction (second set - first set)\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setInt2 - *setInt1) << endl;
                            break;
                        case 12:
                            cout << "\nOption 12 - Subset inclusion check (second set in first set)\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setInt1->CheckSubset(setInt2) ? "Second set is in first set" : "Second set is not in first set") << endl;
                            break;
                        case 13:
                            cout << "\nOption 13 - Subset inclusion check (first set in second set)\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setInt2->CheckSubset(setInt1) ? "First set is in second set" : "First set is not in second set") << endl;
                            break;
                        case 14:
                            cout << "\nOption 14 - Equality check\n";

                            if (setInt1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setInt2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << ((*setInt1 == *setInt2) ? "Sets are equels" : "Sets are not equels") << endl;
                            break;
                    }
                } while(cmd_action != 0);
                break;
            case 2:
                cout << "\nOption 2 - Float sets\n";
                cmd_action = 0;
                do {
                    cmd_action = dialog(MSGS, MSGS_SIZE);
                    switch (cmd_action) {
                        case 0:
                            cout << "Goodbye! :)";
                            cmd = 0;
                            cmd_action = 0;
                            break;
                        case 1:
                            setFloat1->Clear();
                            setFloat2->Clear();
                            cmd_action = 0;
                            break;
                        case 2:
                            cout << "\nOption 2 - First set generate (max n elements)\n";

                            if (setFloat1->GetLength() != 0) setFloat1->Clear();
                            cout << "Input number of pieces: ";
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
                            cout << "\nOption 3 - Second set generate (max n elements)\n";

                            if (setFloat2->GetLength() != 0) setFloat2->Clear();
                            cout << "Input number of pieces: ";
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
                            cout << "\nOption 4 - First set max value\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setFloat1->GetMax();
                            break;
                        case 5:
                            cout << "\nOption 5 - Second set max value\n";

                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setFloat2->GetMax();
                            break;
                        case 6:
                            cout << "\nOption 6 - First set insert value\n";

                            cout << "Input elemet: ";
                            mode = readFloat(nFloat);
                            if (mode != 0) {
                                break;
                            }
                            setFloat1->Insert(nFloat);
                            cout << "Success!\n" << *setFloat1 << endl;
                            break;
                        case 7:
                            cout << "\nOption 7 - Second set insert value\n";

                            cout << "Input elemet: ";
                            mode = readFloat(nFloat);
                            if (mode != 0) {
                                break;
                            }
                            setFloat2->Insert(nFloat);
                            cout << "Success!\n" << *setFloat2 << endl;
                            break;
                        case 8:
                            cout << "\nOption 8 - Union\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setFloat1 + *setFloat2) << endl;
                            break;
                        case 9:
                            cout << "\nOption 9 - Crossing\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setFloat1 * *setFloat2) << endl;
                            break;
                        case 10:
                            cout << "\nOption 10 - Subtraction (first set - second set)\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setFloat1 - *setFloat2) << endl;
                            break;
                        case 11:
                            cout << "\nOption 11 - Subtraction (second set - first set)\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setFloat2 - *setFloat1) << endl;
                            break;
                        case 12:
                            cout << "\nOption 12 - Subset inclusion check (second set in first set)\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setFloat1->CheckSubset(setFloat2) ? "Second set is in first set" : "Second set is not in first set") << endl;
                            break;
                        case 13:
                            cout << "\nOption 13 - Subset inclusion check (first set in second set)\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat1->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setFloat2->CheckSubset(setFloat1) ? "First set is in second set" : "First set is not in second set") << endl;
                            break;
                        case 14:
                            cout << "\nOption 14 - Equality check\n";

                            if (setFloat1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setFloat2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << ((*setFloat1 == *setFloat2) ? "Sets are equels" : "Sets are not equels") << endl;
                            break;
                    }
                } while(cmd_action != 0);
                break;
            case 3:
                cout << "\nOption 3 - Complex sets\n";
                cmd_action = 0;
                do {
                    cmd_action = dialog(MSGS, MSGS_SIZE);
                    switch (cmd_action) {
                        case 0:
                            cout << "Goodbye! :)";
                            cmd = 0;
                            cmd_action = 0;
                            break;
                        case 1:
//                            setComplex1->Clear();
//                            setComplex2->Clear();
//                            cmd_action = 0;
                            break;
                        case 2:
//                            cout << "\nOption 2 - First set generate (max n elements)\n";
//
//                            if (setComplex1->GetLength() != 0) setComplex1->Clear();
//                            cout << "Input number of pieces: ";
//                            mode = readInt(nInt);
//                            if (mode != 0) {
//                                break;
//                            }
//                            if (nInt <= 0) {
//                                cout << "The number must be positive.\n";
//                                break;
//                            }
//                            setComplex1->Generate(nInt, randomComplex);
//                            cout << "Generated first set:\n" << *setComplex1 << endl;
                            break;
                        case 3:
//                            cout << "\nOption 3 - Second set generate (max n elements)\n";
//
//                            if (setComplex2->GetLength() != 0) setComplex2->Clear();
//                            cout << "Input number of pieces: ";
//                            mode = readInt(nInt);
//                            if (mode != 0) {
//                                break;
//                            }
//                            if (nInt <= 0) {
//                                cout << "The number must be positive.\n";
//                                break;
//                            }
//                            setComplex2->Generate(nInt, randomComplex);
//                            cout << "Generated second set:\n" << *setComplex2 << endl;
                            break;
                        case 4:
//                            cout << "\nOption 4 - First set max value\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << setComplex1->GetMax();
                            break;
                        case 5:
//                            cout << "\nOption 5 - Second set max value\n";
//
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << setComplex2->GetMax();
                            break;
                        case 6:
//                            cout << "\nOption 6 - First set insert value\n";
//
//                            cout << "Input elemet: ";
//                            mode = readComplex(nComplex);
//                            if (mode != 0) {
//                                break;
//                            }
//                            setComplex1->Insert(nComplex);
//                            cout << "Success!\n" << *setComplex1 << endl;
                            break;
                        case 7:
//                            cout << "\nOption 7 - Second set insert value\n";
//
//                            cout << "Input elemet: ";
//                            mode = readComplex(nComplex);
//                            if (mode != 0) {
//                                break;
//                            }
//                            setComplex2->Insert(nComplex);
//                            cout << "Success!\n" << *setComplex2 << endl;
                            break;
                        case 8:
//                            cout << "\nOption 8 - Union\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (*setComplex1 + *setComplex2) << endl;
                            break;
                        case 9:
//                            cout << "\nOption 9 - Crossing\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (*setComplex1 * *setComplex2) << endl;
                            break;
                        case 10:
//                            cout << "\nOption 10 - Subtraction (first set - second set)\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (*setComplex1 - *setComplex2) << endl;
                            break;
                        case 11:
//                            cout << "\nOption 11 - Subtraction (second set - first set)\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (*setComplex2 - *setComplex1) << endl;
                            break;
                        case 12:
//                            cout << "\nOption 12 - Subset inclusion check (second set in first set)\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (setComplex1->CheckSubset(setComplex2) ? "Second set is in first set" : "Second set is not in first set") << endl;
                            break;
                        case 13:
//                            cout << "\nOption 13 - Subset inclusion check (first set in second set)\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << (setComplex2->CheckSubset(setComplex1) ? "First set is in second set" : "First set is not in second set") << endl;
                            break;
                        case 14:
//                            cout << "\nOption 14 - Equality check\n";
//
//                            if (setComplex1->GetLength() == 0) {
//                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            if (setComplex2->GetLength() == 0) {
//                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
//                                break;
//                            }
//                            cout << ((*setComplex1 == *setComplex2) ? "Sets are equels" : "Sets are not equels") << endl;
                            break;
                    }
                } while(cmd_action != 0);
                break;
            case 4:
                cout << "\nOption 4 - String sets\n";
                cmd_action = 0;
                do {
                    cmd_action = dialog(MSGS, MSGS_SIZE);
                    switch (cmd_action) {
                        case 0:
                            cout << "Goodbye! :)";
                            cmd = 0;
                            cmd_action = 0;
                            break;
                        case 1:
//                            setComplex1->Clear();
//                            setComplex2->Clear();
//                            cmd_action = 0;
                            break;
                        case 2:
                            cout << "\nOption 2 - First set generate (max n elements)\n";

                            if (setString1->GetLength() != 0) setString1->Clear();
                            cout << "Input number of pieces: ";
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
                            cout << "\nOption 3 - Second set generate (max n elements)\n";

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
                            cout << "\nOption 4 - First set max value\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setString1->GetMax();
                            break;
                        case 5:
                            cout << "\nOption 5 - Second set max value\n";

                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << setString2->GetMax();
                            break;
                        case 6:
                            cout << "\nOption 6 - First set insert value\n";

                            cout << "Input elemet: ";
                            mode = readString(nString);
                            if (mode != 0) {
                                break;
                            }
                            setString1->Insert(nString);
                            cout << "Success!\n" << *setString1 << endl;
                            break;
                        case 7:
                            cout << "\nOption 7 - Second set insert value\n";

                            cout << "Input elemet: ";
                            mode = readString(nString);
                            if (mode != 0) {
                                break;
                            }
                            setString2->Insert(nString);
                            cout << "Success!\n" << *setString2 << endl;
                            break;
                        case 8:
                            cout << "\nOption 8 - Union\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setString1 + *setString2) << endl;
                            break;
                        case 9:
                            cout << "\nOption 9 - Crossing\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setString1 * *setString2) << endl;
                            break;
                        case 10:
                            cout << "\nOption 10 - Subtraction (first set - second set)\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setString1 - *setString2) << endl;
                            break;
                        case 11:
                            cout << "\nOption 11 - Subtraction (second set - first set)\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (*setString2 - *setString1) << endl;
                            break;
                        case 12:
                            cout << "\nOption 12 - Subset inclusion check (second set in first set)\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setString1->CheckSubset(setString2) ? "Second set is in first set" : "Second set is not in first set") << endl;
                            break;
                        case 13:
                            cout << "\nOption 13 - Subset inclusion check (first set in second set)\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << (setString2->CheckSubset(setString1) ? "First set is in second set" : "First set is not in second set") << endl;
                            break;
                        case 14:
                            cout << "\nOption 14 - Equality check\n";

                            if (setString1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (setString2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << ((*setString1 == *setString2) ? "Sets are equels" : "Sets are not equels") << endl;
                            break;
                    }
                } while(cmd_action != 0);
                break;
            case 5:
                cout << "\nOption 5 - Person sets\n";
                cmd_action = 0;
                do {
                    cmd_action = dialog(MSGS, MSGS_SIZE);
                    switch (cmd_action) {
                        case 0:
                            cout << "Goodbye! :)";
                            cmd = 0;
                            cmd_action = 0;
                            break;
                        case 1:
                            set1->Clear();
                            set2->Clear();
                            cmd_action = 0;
                            break;
                        case 2:
                            cout << "\nOption 2 - First set generate (max n elements)\n";

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
                            cout << "\nOption 3 - Second set generate (max n elements)\n";

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
                            cout << "\nOption 4 - First set max value\n";

                            if (set1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << set1->GetMax();
                            break;
                        case 5:
                            cout << "\nOption 5 - Second set max value\n";

                            if (set2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << set2->GetMax();
                            break;
                        case 6:
                            cout << "\nOption 6 - First set insert value\n";

                            cout << "Input elemet: ";
                            mode = readPerson(nPerson);
                            if (mode != 0) {
                                break;
                            }
                            set1->Insert(nPerson);
                            cout << "Success!\n" << *set1 << endl;
                            break;
                        case 7:
                            cout << "\nOption 7 - Second set insert value\n";

                            cout << "Input elemet: ";
                            mode = readPerson(nPerson);
                            if (mode != 0) {
                                break;
                            }
                            set2->Insert(nPerson);
                            cout << "Success!\n" << *set2 << endl;
                            break;
                        case 8:
                            cout << "\nOption 8 - Union\n";

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
                        case 9:
                            cout << "\nOption 9 - Crossing\n";

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
                        case 10:
                            cout << "\nOption 10 - Subtraction (first set - second set)\n";

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
                        case 11:
                            cout << "\nOption 11 - Subtraction (second set - first set)\n";

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
                        case 12:
                            cout << "\nOption 12 - Subset inclusion check (second set in first set)\n";

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
                        case 13:
                            cout << "\nOption 13 - Subset inclusion check (first set in second set)\n";

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
                        case 14:
                            cout << "\nOption 14 - Equality check\n";

                            if (set1->GetLength() == 0) {
                                cout << "First set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            if (set2->GetLength() == 0) {
                                cout << "Second set is empty.\n Please use generate or keyboard input.\n";
                                break;
                            }
                            cout << ((*set1 == *set2) ? "Sets are equels" : "Sets are not equels") << endl;
                            break;
                    }
                } while(cmd_action != 0);
                break;
        }
    } while (cmd != 0);

    return 0;
}