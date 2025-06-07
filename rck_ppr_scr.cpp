#include <iostream>
#include <stdlib.h>
#include <string>


char takeChoice(){
  std::cout << "Enter your choice as in 'r', 'p' and 's' : ";
  char userChoice;
  std::cin >> userChoice;
  return userChoice;
}

char setCodes(){
  char compChoice;
  srand(time(0));
  auto randomNum = rand()%8;
  if(randomNum >= 0 && randomNum < 3){
    compChoice = 'r';
  }
  else if(randomNum >= 3 && randomNum < 6){
    compChoice = 'p';
  }
  else if(randomNum >= 6 && randomNum < 9){
    compChoice = 's';
  }
  else{
    std::cout << "An error occurred" << '\n';
  }
  return compChoice;
}

void game(char& uC, char& cC){
  //TIE
  if(uC == cC) std::cout << "TIE";
  //WIN
  else if(uC == 'r' && cC == 's' || uC == 'p' && cC == 'r' || uC == 's' && cC == 'p') std::cout << "VICTORY";
  //LOSS
  else std::cout << "LOST";
}

void welcomeToCasinnoz(){
  std::string choice;
  std::cout << "Welcome to THE CASINNOZ!" << std::endl;
  std::cout << "To start the game please type 'start' : ";
  std::getline(std::cin, choice);
  for(int i = 0; choice[i] != '\0'; ++i){
    choice[i] = toupper(choice[i]);
  }
  if(choice == "START"){
    char uC = takeChoice();
    char cC = setCodes();
    game(uC, cC);
  }
}

int main(){
  welcomeToCasinnoz();
  return 0;
}