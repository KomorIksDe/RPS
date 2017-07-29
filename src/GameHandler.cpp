#include "GameHandler.hpp"
#include <conio.h>
#include <windows.h>

GHandler::GHandler() {
    player1 = std::make_pair(nullptr, 0);
    player2 = std::make_pair(nullptr, 0);
}

GHandler::~GHandler() {
    delete player1.first;
    delete player2.first;
}

void GHandler::mainMenu() {
    system("cls");
    std::cout<<"Rock, Paper, Scissors. I guess you know this game, so I won't explain it's rules."<<std::endl;
    std::cout<<"[1].Start a new game"<<std::endl;
    std::cout<<"[2].Credits"<<std::endl;
    std::cout<<"[3].Exit game"<<std::endl;

    switch(getch()) {
        case '1':
            prepareForGame();
            runMainGame();
            break;
        case '2':
            showCredits();
            mainMenu();
            break;
        case '3':
            exit(0);
            break;
        default:
            std::cout<<std::endl<<"There's no such an option";
            Sleep(2000);
            mainMenu();
            break;
    }
}

void GHandler::showCredits() {
    system("cls");
    std::cout<<"Made by Pawel Kupczak on 29th July 2017";
    Sleep(3000);
}

void GHandler::loadPlayers(std::string name1, std::string name2) {
    player1.first = new Player(name1);
    player2.first = new Player(name2);
}

void GHandler::prepareForGame() {
    std::string n1, n2;

    system("cls");
    std::cout<<"Player 1's name: "; std::getline(std::cin, n1);
    std::cout<<"Player 2's name: "; std::getline(std::cin, n2);

    loadPlayers(n1, n2);
}

void GHandler::runMainGame() {
    while(!hasWon()) {
        system("cls");
        startRound();
    }

    system("cls");
    if(player1.second == 3)
        std::cout<<player1.first->name<<" has won!"<<std::endl;
    else
        std::cout<<player2.first->name<<" has won!"<<std::endl;
}

bool GHandler::hasWon() {
    if((player1.second == 3) || (player2.second == 3))
        return true;
    else
        return false;
}

void GHandler::setShapeFor(Player* player) {
    std::cout<<"[1].Rock"<<std::endl;
    std::cout<<"[2].Paper"<<std::endl;
    std::cout<<"[3].Scissors"<<std::endl;

    switch(getch()) {
        case '1':
            player->shape = new Rock();
            break;
        case '2':
            player->shape = new Paper();
            break;
        case '3':
            player->shape = new Scissors();
            break;
    }
}

void GHandler::startRound() {
    system("cls");

    std::cout<<player1.first->name<<" | Score: "<<player1.second<<std::endl;
    setShapeFor(player1.first);

    std::cout<<std::endl;

    std::cout<<player2.first->name<<" | Score: "<<player2.second<<std::endl;
    setShapeFor(player2.first);

    std::cout<<std::endl;

    if(getResult() == 1) {
        player1.second++;
        std::cout<<player1.first->name<<" has destroyed "<<player2.first->name<<"'s "<<player2.first->shape->getName()<<" with his "<<player1.first->shape->getName()<<"!";
        Sleep(2000);
    }
    else if(getResult() == 2) {
        player2.second++;
        std::cout<<player2.first->name<<" has destroyed "<<player1.first->name<<"'s "<<player1.first->shape->getName()<<" with his "<<player2.first->shape->getName()<<"!";
        Sleep(2000);
    }
    else {
        std::cout<<"DRAW!";
        Sleep(2000);
    }
}

int GHandler::getResult() {
    if(player1.first->shape->doesBeat(player2.first->shape) == WINS)
        return 1;
    else if(player1.first->shape->doesBeat(player2.first->shape) == LOSES)
        return 2;
    else
        return 0;
}
