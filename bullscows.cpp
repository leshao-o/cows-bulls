#include <iostream>
#include <ctime>

using namespace std;

bool checkArrayForMatches (int arr[]) {
 
  // выявление совпадающих цифр
  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {

      if (arr[i] == arr[j] && i != j) {
        return false;
      }
 
    }

  }

}

void getRandomNumber(int arr[]) {

  srand(time(0));
  bool flag = true;

  while (flag) {

    // заполнить массив рандомными числами
    for (int i = 0; i < 4; i++) {

      arr[i] = rand() % 10;

      if (arr[0] == 0) {
       arr[0] = rand() % 10;
      }

    }

    // проверить загаданное число на совпадающие цифры
    if (!checkArrayForMatches(arr)) {
      flag = true;
    }
    else {
      flag = false;
    }

  }

}

void fromIntToArr(int num, int arr[]) {  

  arr[0] = num / 1000;
  arr[1] = (num / 100) % 10;
  arr[2] = (num / 10) % 10;
  arr[3] = num % 10; 

}

void inputNumber(int arr[]) {

  int num;
  bool flag = true;

  while(flag) {

    cout << "\nВведите ваше число: ";

    cin >> num;

    fromIntToArr(num, arr);

    // проверить введенное число на совпадающие цифры и на ноль
    if (!checkArrayForMatches(arr)) {
        cout << "\nЧисло должно быть без одинаковых цифр\n";
    }
    else if (arr[0] == 0) {
      cout << "\nЧисло не должно начинаться на ноль\n";
    }
    else {
      flag = false;
    }

  }

}

bool endStartGame () {

  int flag = true;
  int continueGame = 0;

  cout << "\nНачать заново - 1";
  cout << "\nЗакончить игру - 2\n";
  cin >> continueGame;

  // начать игру заново или закончить играть
  switch(continueGame) {

    case 1:
      flag = true;
      cout << "\nИгра началась\n";
      break;

    case 2:
      flag = false;
      cout << "\nИгра окончена\n";
      break;

    default:
      cout << "\nВведите 1 или 2\n";
      break;

  }

  return flag;
}

bool gameLogic(int arr[], int arr2[]) {

  bool flag = true;
  int cows = 0;
  int bulls = 0;

  // поиск коров в введеном числе
  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {

      if (arr[i] == arr2[j]) { 
        cows++;
      }

    }

  }

  // поиск быков в введеном числе
  for (int i = 0; i < 4; i++) {
    if (arr[i] == arr2[i]) { 
      bulls++;
    }
  }

  cout << "\n╔══════════╗\n";
  cout << "║ Коров: " << cows << " ║" <<endl;
  cout << "║ Быков: " << bulls << " ║" <<endl;
  cout << "╚══════════╝\n";

  for (int l = 0; l < 4; l++)
    cout << arr2[l];

  // условие победы в игре
  if (bulls == 4) {
    cout << "\nТы победил!\n"; 
    flag = false;
  }
  else {
    flag = true;
  }

  return flag;
}

int main(int argc, const char * argv[]) {

  bool game = true;

  cout << "\nИгра началась\n";

  int guessNumber[4];
  getRandomNumber(guessNumber);

  while(game) {
    
    int enteredNumber[4];
    inputNumber(enteredNumber);

    game = gameLogic(enteredNumber, guessNumber);
    
    if (!game) {
      getRandomNumber(guessNumber);
      game = endStartGame();
    }

  }

  cout << endl;
  return 0;
}
