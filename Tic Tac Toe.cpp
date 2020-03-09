#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int close = 1;

void enter_sign(char sign_position[3][3], int position_col, int  position_poem , char turn);

void XandO_board_drawing(char fields[3][3])
{
    cout << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "W, A, S, D => navigating the blackboard\n";
    cout << "Enter => confirmation of the X or O character in the field we are currently on\n";
    cout << "E => Exit\n";
    cout << "--------------------------------------------------------------------------------------\n";
    cout << endl;
    cout << endl;
    cout << "\t\t_________________________" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[0][0] << "   |   " << fields[0][1] << "   |   " << fields[0][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[1][0] << "   |   " << fields[1][1] << "   |   " << fields[1][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[2][0] << "   |   " << fields[2][1] << "   |   " << fields[2][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
    cout << endl;
    //cout << ":"<<fields[1][0] << endl;
}

void WHERE_board_drawing(char fields[3][3])
{
    cout << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "W, A, S, D => navigating the blackboard\n";
    cout << "Enter => confirmation of the X or O character in the field we are currently on\n";
    cout << "E => Exit\n";
    cout << "--------------------------------------------------------------------------------------\n";
    cout << endl;
    cout << endl;
    cout << "\t\t_________________________" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[0][0] << "   |   " << fields[0][1] << "   |   " << fields[0][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[1][0] << "   |   " << fields[1][1] << "   |   " << fields[1][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
    cout << "\t\t|       |       |       |" << endl;
    cout << "\t\t|   " << fields[2][0] << "   |   " << fields[2][1] << "   |   " << fields[2][2] << "   |" << endl;
    cout << "\t\t|_______|_______|_______|" << endl;
}

void initializing_variables(char fields[3][3])
{
    for (int col = 0; col < 3; col++) {

        for (int poem = 0; poem < 3; poem++) {

            fields[col][poem] = ' ';
        }
    }
}



void move(char fields_position[3][3] , char sign_position[3][3], char turn)
{
    const char left = 'A', right = 'D', up = 'W', down = 'S', enter = 13;
    char choice;

    initializing_variables(fields_position);
    int position_col = 1, position_poem = 1;
    fields_position[position_col][position_poem] = '#';

    


    while (true) {

        choice = _getch();
        switch (toupper(choice)) {

        case left:
            if (position_poem == 0) {
                cout << "You are on the edge" << endl;
            }
            else {
                system("cls");

                fields_position[position_col][position_poem] = ' ';
                position_poem = position_poem - 1;
                fields_position[position_col][position_poem] = '#';

                WHERE_board_drawing(fields_position);
                Sleep(150);
                system("cls");
                XandO_board_drawing(sign_position);

            }
            continue;

        case right:
            if (position_poem == 2) {
                cout << "You are on the edge" << endl;
            }
            else {
                system("cls");
                fields_position[position_col][position_poem] = ' ';
                position_poem = position_poem + 1;
                fields_position[position_col][position_poem] = '#';
                WHERE_board_drawing(fields_position);
                Sleep(150);
                system("cls");
                XandO_board_drawing(sign_position);
            }
            continue;

        case up:
            if (position_col == 0) {
                cout << "You are on the edge" << endl;
            }
            else {
                system("cls");
                fields_position[position_col][position_poem] = ' ';
                position_col = position_col - 1;
                fields_position[position_col][position_poem] = '#';
                WHERE_board_drawing(fields_position);
                Sleep(150);
                system("cls");
                XandO_board_drawing(sign_position);

            }
            continue;

        case down:
            if (position_col == 2) {
                cout << "You are on the edge" << endl;
            }
            else {
                system("cls");
                fields_position[position_col][position_poem] = ' ';
                position_col = position_col + 1;
                fields_position[position_col][position_poem] = '#';
                WHERE_board_drawing(fields_position);
                Sleep(150);
                system("cls");
                XandO_board_drawing(sign_position);
            }
            continue;
            

        case enter:
            cout << "Enter" << endl;

            if (sign_position[position_col][position_poem] == ' ') {

                sign_position[position_col][position_poem] = turn;
            }
            else {
                cout << "There is a sign\n";
                cout << "Change field!\n";
                continue;
            }

            break;
        case 'E':
            cout << "Closing the game...\n";
            close = 0;
            Sleep(1000);
            break;
        default:
            cout << "I do not recognize this sign" << endl;
            continue;
        }

        break;
    }
}



int main()
{
    const int col = 3, poem = 3;
    
    char fields_position[col][poem]; // do pozycji 

    char sign_position[col][poem];  //do X i O

    initializing_variables(fields_position);
    initializing_variables(sign_position);
   

    //MEUE
    while (close) {

        char turn;
       

        turn = 'X';
        XandO_board_drawing(sign_position);
        move(fields_position, sign_position , turn);
        system("cls");

        
        turn = 'O';
        XandO_board_drawing(sign_position);
        move(fields_position, sign_position, turn);
        system("cls");

    }
}


