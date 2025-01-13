//// Final_Project_with_Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <ctime>
//#include <string>
//#include <windows.h>
//using namespace std;
//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//
//void Generate_P1_Board(int [100][100],int);
//void Generate_P2_Board(int [100][100],int);
//void Change_Num_on_Board(int [100][100], int [100][100], int,int );
//void Checking_Win_Condition(int [100][100], int [100][100],int , int&, int&);
//int main()
//{
//    srand(time(0));
//    int gameid, Player1Game[100][100] = { 0 }, Player2Game[100][100] = { 0 }, turn;
//    int choice, k = 0, Player1Score = 0, Player2Score = 0;
//    int size;
//    bool Player1Win = false, Player2Win = false;
//    string Player1Name, Player2Name;
//     
//    cout << "Enter the size of the game:";
//    cin >> size;
//    gameid = 1000 + rand() % 9000;
//    // Cards
//    for (int j = 0; j < size; j++) {
//        for (int i = 0; i < size; i++) {
//            Player1Game[j][i] = 1 + rand() % (size*size);
//            for (int k = 0; k <= j; k++) {                     // Loop for checking of uniqueness
//                for (int l = 0; l < size; l++) {
//                    while ((Player1Game[k][l] == Player1Game[j][i]) && (j != k || i != l)) {
//                        Player1Game[j][i] = 1 + rand() % (size*size);
//                        k = 0;
//                        l = -1;
//                    }
//                }
//            }
//        }
//    }
//    for (int j = 0; j < size; j++) {
//        for (int i = 0; i < size; i++) {
//            Player2Game[j][i] = 1 + rand() % (size*size);
//            for (int k = 0; k <= j; k++) {
//                for (int l = 0; l < size; l++) {
//                    while ((Player2Game[k][l] == Player2Game[j][i]) && (j != k || i != l)) {
//                        Player2Game[j][i] = 1 + rand() % (size*size);
//                        k = 0;
//                        l = -1;
//                    }
//                }
//            }
//        }
//    }
//
//    cin.ignore();
//    SetConsoleTextAttribute(h, 2);             //for green colour
//    cout << "Enter Player 1 Name:";
//    getline(cin, Player1Name);
//    cout << "Enter Player 2 Name:";
//    getline(cin, Player2Name);
//    cout << endl;
//    turn = rand() % 2;
//    SetConsoleTextAttribute(h, 14);
//    cout << "Game Id:" << gameid << endl;;
//    while (true) {
//        if (turn == 0) {
//            Generate_P1_Board(Player1Game,size);
//            SetConsoleTextAttribute(h, 14);             //For yellow colour
//            cout << Player1Name << " select any number from the card:";
//            cin >> choice;
//            while (choice == 0) {
//                SetConsoleTextAttribute(h, 4);         //red colour for errors
//                cout << "Invalid input:Please try again\n";
//                cin >> choice;
//            }
//            Change_Num_on_Board(Player1Game, Player2Game, choice,size);
//            Checking_Win_Condition(Player1Game, Player2Game,size, Player1Score, Player2Score);
//            
//            if (Player1Score == 5) {
//                Player1Win = true;
//                break;
//            }
//            else if (Player2Score == 5) {
//                Player2Win = true;
//                break;
//            }
//            Player1Score = 0;
//            Player2Score = 0;
//            Generate_P2_Board(Player2Game,size);
//            SetConsoleTextAttribute(h, 14);            //for yellow
//            cout << Player2Name << " select any number from the card:";
//            cin >> choice;
//            while (choice == 0) {
//                SetConsoleTextAttribute(h, 4);        //for red
//                cout << "Invalid input:Please try again\n";
//                cin >> choice;
//            }
//
//            Change_Num_on_Board(Player1Game, Player2Game, choice,size);
//            Checking_Win_Condition(Player1Game,Player2Game,size,Player1Score,Player2Score);
//            
//            if (Player2Score == 5) {
//                Player2Win = true;
//                break;
//            }
//            else if (Player1Score == 5) {
//                Player1Win = true;
//                break;
//            }
//            Player1Score = 0;
//            Player2Score = 0;
//
//        }
//        else if (turn == 1) {
//            Generate_P2_Board(Player2Game,size);
//            SetConsoleTextAttribute(h, 14);
//            cout << Player2Name << " select any number from the card:";
//            cin >> choice;
//            while (choice == 0) {
//                SetConsoleTextAttribute(h, 4);
//                cout << "Invalid input:Please try again\n";
//                cin >> choice;
//            }
//            Change_Num_on_Board(Player1Game, Player2Game, choice, size);
//            Checking_Win_Condition(Player1Game, Player2Game,size , Player1Score, Player2Score);
//            
//            if (Player2Score == 5) {
//                Player2Win = true;
//                break;
//            }
//            else if (Player1Score == 5) {
//                Player1Win = true;
//                break;
//            }
//            Player1Score = 0;
//            Player2Score = 0;
//            Generate_P1_Board(Player1Game, size);
//            SetConsoleTextAttribute(h, 14);
//            cout << Player1Name << " select any number from the card:";
//            cin >> choice;
//            while (choice == 0) {
//                SetConsoleTextAttribute(h, 4);
//                cout << "Invalid input:Please try again\n";
//                cin >> choice;
//            }
//
//            Change_Num_on_Board(Player1Game, Player2Game, choice, size);
//            Checking_Win_Condition(Player1Game, Player2Game,size, Player1Score, Player2Score);
//            
//            if (Player1Score == 5) {
//                Player1Win = true;
//                break;
//            }
//            else if (Player2Score == 5) {
//                Player2Win = true;
//                break;
//            }
//            Player1Score = 0;
//            Player2Score = 0;
//
//        }
//    }
//    SetConsoleTextAttribute(h, 2);
//    if (Player1Win) {
//        cout << Player1Name << " won!\n";
//    }
//    else if (Player2Win) {
//        cout << Player2Name << " won!\n";
//    }
//}
//void Generate_P1_Board(int Player1Game[100][100],int size) {
//    SetConsoleTextAttribute(h, 3);
//    for (int j = 0; j < size; j++) {
//        if (size < 18) {
//            cout << "\t\t\t\t";
//        }
//        for (int i = 0; i < size; i++) {
//            if (Player1Game[j][i] <10) {
//                cout << "|  " << Player1Game[j][i] << "|";
//            }else if (Player1Game[j][i] < 100) {
//                cout << "| " << Player1Game[j][i] << "|";
//            }
//            else {
//                cout << "|" << Player1Game[j][i] << "|";
//            }
//        }
//        cout << endl;
//    }
//}
//void Generate_P2_Board(int Player2Game[100][100],int size) {
//    SetConsoleTextAttribute(h, 3);
//    for (int j = 0; j < size; j++) {
//        if (size < 18) {
//            cout << "\t\t\t\t";
//        }
//        for (int i = 0; i < size; i++) {
//            if (Player2Game[j][i] / 10 == 0) {
//                cout << "|  " << Player2Game[j][i] << "|";
//            }else if (Player2Game[j][i] < 100) {
//                cout << "| " << Player2Game[j][i] << "|";
//            }
//            else {
//                cout << "|" << Player2Game[j][i] << "|";
//            }
//        }
//        cout << endl;
//    }
//}
//void Change_Num_on_Board(int Player1Game[100][100], int Player2Game[100][100], int choice,int size) {
//    int present1 = 0;
//    for (int j = 0; j < size; j++) {
//        for (int i = 0; i < size; i++) {
//            if (Player1Game[j][i] == choice && choice != 0) {
//                Player1Game[j][i] = 0;
//            }
//            else {
//                present1++;
//                if (present1 == size*size) {
//                    SetConsoleTextAttribute(h, 4);
//                    cout << "Error:Invalid input,try again\n";
//                    cin >> choice;
//                    j = 0;
//                    i = -1;
//                    present1 = 0;
//                }
//            }
//            if (Player2Game[j][i] == choice) {
//                Player2Game[j][i] = 0;
//            }
//        }
//    }
//}
//void Checking_Win_Condition(int Player1Game[100][100], int Player2Game[100][100],int size, int& Player1Score, int& Player2Score) {
//    int Tempcount = 0;
//    for (int j = 0; j < size; j++) {           //for rows
//        for (int i = 0; i < size; i++) {
//            if (Player1Game[j][i] == 0) {
//                Tempcount++;
//            }
//        }
//        if (Tempcount == size) {
//            Player1Score++;
//        }
//        Tempcount = 0;
//    }
//    Tempcount = 0;
//    for (int j = 0; j < size; j++) {              //for columns
//        for (int i = 0; i < size; i++) {
//            if (Player1Game[i][j] == 0) {
//                Tempcount++;
//            }
//        }
//        if (Tempcount == size) {
//            Player1Score++;
//        }
//        Tempcount = 0;
//    }
//    Tempcount = 0;
//    for (int i = 0; i < size; i++) {            //for main diagonal
//        if (Player1Game[i][i] == 0) {
//            Tempcount++;
//        }
//    }
//    if (Tempcount == size) {
//        Player1Score++;
//    }
//    Tempcount = 0;
//    for (int i = size-1; i >= 0; i--) {          //for secondary diagnal
//        if (Player1Game[(size-1) - i][i] == 0) {
//            Tempcount++;
//        }
//    }
//    if (Tempcount == size) {
//        Player1Score++;
//    }
//    Tempcount = 0;
//    for (int j = 0; j < size; j++) {          //for rows
//        for (int i = 0; i < size; i++) {
//            if (Player2Game[j][i] == 0) {
//                Tempcount++;
//            }
//        }
//        if (Tempcount == size) {
//            Player2Score++;
//        }
//        Tempcount = 0;
//    }
//    Tempcount = 0;
//    for (int j = 0; j < size; j++) {           //for columns
//        for (int i = 0; i < size; i++) {
//            if (Player2Game[i][j] == 0) {
//                Tempcount++;
//            }
//        }
//        if (Tempcount == size) {
//            Player2Score++;
//        }
//        Tempcount = 0;
//    }
//    Tempcount = 0;
//    for (int i = 0; i < size; i++) {         //for main diagonal
//        if (Player2Game[i][i] == 0) {
//            Tempcount++;
//        }
//    }
//    if (Tempcount == size) {
//        Player2Score++;
//    }
//    Tempcount = 0;
//    for (int i = size-1; i >= 0; i--) {      //for secondary diagonal
//        if (Player2Game[(size-1) - i][i] == 0) {
//            Tempcount++;
//        }
//    }
//    if (Tempcount == size) {
//        Player2Score++;
//    }
//}
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
