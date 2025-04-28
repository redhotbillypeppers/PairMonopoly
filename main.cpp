// g++ monopolyworkspace/clionmonopolygame.cpp -o monopolyworkspace/clionmonopolygame && ./monopolyworkspace/clionmonopolygame

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <limits>
#include "playerAndPositionClass.h"


//this function is a simple wrapper to clear the cin terminals,
//first it clears the terminal then ignores any errors in the terminal.
void cinClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayBoard(int playerPosition, Player dec[], int plyrcount) {
    // function is used in choice 4 of the game to summon the board and gives you the player position too

    //Prototypes:
    // no homes 7 spaces
    //(h       ) 1 house
    //(h h     ) 2 homes
    //(h h  h  ) 3 homes
    //(h h  h h) 4 homes
    //( hotel  ) hotel
    std::string homeTier[6] = {"          ", "(h       )", "(h h     )","(h h  h  )", "(h h  h h)","( hotel  )"};


    std::string p[20];
    for (int i = 0; i < 20; i++) {
        p[i] = homeTier[squareStats[i].propertyHouse];
    }

    //initialize the piece slots
    char t[20][4];

    //this loop wipes the piece indicators and makes them all blank (' ')
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j++) {
                t[i][j] = ' ';
        }
    }

    //this loop assigns the token indicator to the correct spot in the board below.
    for (int i = 0; i < plyrcount; i++) {
        for (int j = 0; j < 4; j++) {
            if (t[dec[i].position][j] == ' ') {
                t[dec[i].position][j] = dec[i].pieceIndicator;
                break;
            }
        }
    }


    //this is the creation of the board with each variable, house stats and where each token is.

    std::cout << "                "<<t[1][0]<<" "<<t[1][1]<<"  "<<t[1][2]<<" "<<t[1][3]<<"    "<<t[2][0]<<" "<<t[2][1]<<"  "<<t[2][2]<<" "<<t[2][3]<<"    "<<t[3][0]<<" "<<t[3][1]<<"  "<<t[3][2]<<" "<<t[3][3]<<"    "<<t[4][0]<<" "<<t[4][1]<<"  "<<t[4][2]<<" "<<t[4][3]<<"                 \n" ;
    std::cout <<             "   ________________$50_________$75_________$150________$100________________  "          << "\n" ;
    std::cout << t[0][0] <<  "  |"<<p[0]<<"||"<<p[1]<<"||"<<p[2]<<"||"<<p[3]<<"||"<<p[4]<<"||"<<p[5]<<"|  " << t[5][0] << "\n" ;
    std::cout << t[0][1] <<  "  |   Go     ||  Broad   ||  Manton  ||  Water   || Hartford ||  Prison  |  " <<  t[5][1] << "\n" ;
    std::cout << t[0][2] <<  "  |  ---->   ||  Street  ||  Ave     ||  Utility ||  Ave     ||          |  " << t[5][2] << "\n" ;
    std::cout << t[0][3] <<  "  |___$325___||__________||__________||__________||__________||___$125___|  " << t[5][3] << "\n" ;
    std::cout << t[19][0] << "  |"<<p[19]<<"|                                                |"<<p[6]<<"|  " << t[6][0] << "\n" ;
    std::cout << t[19][1] << "  | Newport  |                                                |Chalkstone|  " << t[6][1] << "\n" ;
    std::cout << t[19][2] << "  | Mansions |                                                |    Ave   |  " << t[6][2] << "\n" ;
    std::cout << t[19][3] << "  |___$300___|                                                |__________|  " << t[6][3] << "\n" ;
    std::cout << t[18][0] << "  |"<<p[18]<<"|                                                |"<<p[7]<<"|  " << t[7][0] << "\n" ;
    std::cout << t[18][1] << "  |  Brown   |                                                |  Chance  |  " << t[7][1] << "\n" ;
    std::cout << t[18][2] << "  |University|                                                |          |  " << t[7][2] << "\n" ;
    std::cout << t[18][3] << "  |__________|                                                |___$150___|  " << t[7][3] << "\n" ;
    std::cout << t[17][0] << "  |"<<p[17]<<"|                                                |"<<p[8]<<"|  " << t[8][0] << "\n" ;
    std::cout << t[17][1] << "  |Community |                                                |  Branch  |  " << t[8][1] << "\n" ;
    std::cout << t[17][2] << "  |  Chest   |                                                |  Ave     |  " << t[8][2] << "\n" ;
    std::cout << t[17][3] << "  |___$275___|                                                |___$175___|  " << t[8][3] << "\n" ;
    std::cout << t[16][0] << "  |"<<p[16]<<"|                                                |"<<p[9]<<"|  " << t[9][0] << "\n" ;
    std::cout << t[16][1] << "  |  Block   |                                                |  Mount   |  " << t[9][1] << "\n" ;
    std::cout << t[16][2] << "  |  Island  |                                                | Pleasant |  " << t[9][2] << "\n" ;
    std::cout << t[16][3] << "  |__________|___$250____ ___$150____ ___$225____ ___$200____ |__________|  " << t[9][3] << "\n" ;
    std::cout << t[15][0] << "  |"<<p[15]<<"||"<<p[14]<<"||"<<p[13]<<"||"<<p[12]<<"||"<<p[11]<<"||"<<p[10]<<"|  " << t[10][0] << "\n" ;
    std::cout << t[15][1] << "  |  Go To   || Jewelry  || Electric ||  Thayer  ||Wickenden || Vacation |  " << t[10][1] << "\n" ;
    std::cout << t[15][2] << "  |  Prison  || District || Utility  ||  Street  ||  Street  ||          |  " << t[10][2] << "\n" ;
    std::cout << t[15][3] << "  |__________||__________||__________||__________||__________||__________|  " << t[10][3] << "\n" ;
    std::cout << "                "<<t[14][0]<<" "<<t[14][1]<<"  "<<t[14][2]<<" "<<t[14][3]<<"    "<<t[13][0]<<" "<<t[13][1]<<"  "<<t[13][2]<<" "<<t[13][3]<<"    "<<t[12][0]<<" "<<t[12][1]<<"  "<<t[12][2]<<" "<<t[12][3]<<"    "<<t[11][0]<<" "<<t[11][1]<<"  "<<t[11][2]<<" "<<t[11][3]<<"                \n\n";

    std::cout << "Current Player Position: " << playerPosition << "\n";

}

// Function to calculate the cost of buying a house on a property
int costToBuyHouse(boardSquare &square) {
    // Example logic to determine the cost of buying a house
    return square.propertyHouse * 100; // Assuming each house costs 100 units (adjust as needed)
}

int calculateRent(int propertyValue, int propertyHouse) { // function used to calculate rent and is used for rent logic later
    return propertyValue * (1 + propertyHouse);  // Rent formula
}

//this function allows the user to be able to select their token from a predetermined list of them.
void playerSelectTokenFunction(Player dec[], int plyrcount) {
    char s[4] = {'P','T','S','Z'}; // player token symbols to be used in the board
    std::vector<std::string> playerToken = {"Peter Griffin" ,"Taylor Swift","Submarine","Pizza Strip"}; //the 4 different player tokens
    for (int i=0; i < plyrcount; i++) { // function will iterated based on the amount of players the user entered
        auto tokenPrinter = [&](){//'lambda' function that prints list of tokens
            std::cout << "Player " << i+1 << ", select your player token!";
            for (int j=0; j < playerToken.size(); j++) { // this will print the list of tokens, is a vector because we were hoping to implement the user making tokens but we didn't have enough time
                std::cout << "\n" << j+1 <<  ". " << playerToken[j];
            }
            std::cout << std::endl;
        };
        tokenPrinter();
        int choice = 0;
        std::cout << std::endl;
        std::cin >> (choice);

        while (std::cin.fail() || choice < 1 || choice > playerToken.size() || playerToken[choice-1] == "Taken!") { // invalid input code
            if (playerToken[choice-1] == "Taken!") {// originally I had this condition as a separate while statement like this one. But because if a user were to try to take a taken token then enter something like 'easd'
                                                    // the game would enter into an unbreakable loop. So I combined the two.
                std::cout << "That token is being used, please select another one!" << std::endl;
            } else {
                std::cout << "You have inputted an invalid response.\n";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            tokenPrinter();
            std::cin >> choice;
        }
        std::cout << "You have chosen: " << playerToken[(choice-1)] << "!" << std::endl;

        dec[i].pieceIndicator = s[choice-1]; // assigns the correct token indicator
        dec[i].piece = playerToken[(choice-1)]; //assigns the token the user wanted
        playerToken[(choice-1)] = "Taken!"; // makes the token = taken so that others won't be able to use it

    }
}

int playerCount () {
    int plyrcount;
    std::cout << "---------------------------\n| Welcome to RI MONOPOLY! |\n---------------------------\n";
    std::cout <<  "Please enter the # of players from 2 to 4: ";
    std::cin >> plyrcount;

    while(std::cin.fail() || plyrcount < 2 || plyrcount > 4) {
        std::cout << "\nYou have entered an invalid amount of players.\nPlease enter a # of players from 2 to 4: ";
        cinClear();
        plyrcount = 0;
        std::cin >> plyrcount;
    }

    std::cout << "You have entered " << plyrcount << " players!\n" << std::endl;
    return plyrcount;
}

void buyProperty(Player &player, boardSquare &square) { // property buying function used later!
    if (player.money >= square.propertyValue) {
        std::string choice;
        std::cout << "You have landed on " << square.propertyName << ". Would you like to buy it for $" << square.propertyValue << "? (Yes/No): ";
        std::cin >> choice;

        if (choice == "Yes" || choice == "yes") {
            player.money -= square.propertyValue;  // Deduct the money
            square.propertyOwner = player.piece;   // Assign the property to the player
            std::cout << "Congratulations! You bought " << square.propertyName << " for $" << square.propertyValue << "\nYou now have " << player.money << " dollars left!\n";
        } else {
            std::cout << "You chose not to buy " << square.propertyName << ".\n";
        }
    } else {
        std::cout << "You don't have enough money to buy " << square.propertyName << ".\n";
    }
}

void drawChanceCard(Player &player) { // function that draws a chance card whenever a player lands on a chance card space
    int card = (rand() % 7) + 1;
    std::cout << "You drew a Chance card!\n";

    switch (card) {
        case 1:
            std::cout << "It is your birthday, Collect $20!" << std::endl;
            player.money += 20;
            break;
        case 2:
            std::cout << "Get out of jail free card." << std::endl;
            player.pardonCards++;
            break;
        case 3:
            std::cout << "Mugged at Kennedy Plaza, lose 50 dollars." << std::endl;
            player.money -= 50;
            break;
        case 4:
            std::cout << "Advance to Newport Mansions." << std::endl;
            player.position = 20;
            break;
        case 5:
            std::cout << "Advance to the Electric utility." << std::endl;
            player.position = 14;
            break;
        case 6:
            std::cout << "Advance to Go." << std::endl;
            player.position = 1;
            break;
        case 7:
            std::cout << "Bank pays dividend of 45 dollars." << std::endl;
            player.money += 45;
            break;
    }
}

void drawCommunityCard(Player &player) { //function that is called whenever a player lands on a community card space
    int card = (rand() % 7) + 1;
    std::cout << "You drew a Community Chest card. You rolled: " << card << "\n";

    switch (card) {
        case 1:
            std::cout << "Italian uncle gives you 100 dollars." << std::endl;
            player.money += 100;
            break;
        case 2:
            std::cout << "You pay your Dominican barber 40 dollars." << std::endl;
            player.money -= 40;
            break;
        case 3:
            std::cout << "Found 20 dollars on the floor." << std::endl;
            player.money += 20;
            break;
        case 4:
            std::cout << "Get out of jail free card." << std::endl;
            player.pardonCards++;
            break;
        case 5:
            std::cout << "Police busts you for working with mafia, go straight to jail." << std::endl;
            player.isInJail = true;
            break;
        case 6:
            std::cout << "Get 60 dollars selling stock." << std::endl;
            player.money += 60;
            break;
        case 7:
            std::cout << "Mom gives you 10 dollars." << std::endl;
            player.money += 10;
            break;
    }
}

void save(Player dec[],int plyrcount,int lastPlayerTurn) {
    std::ofstream monopolyData("monopolyData.txt"); // open/create the monopoly data file
    if (monopolyData.is_open()) { //if file is open then do this
        monopolyData << plyrcount << '\n'; // saves the player count in the first line
        for (int i = 0; i < plyrcount; i++) { // saves data in this order repeating for the amount of players
            monopolyData << dec[i].position << '\n';
            monopolyData << dec[i].piece << '\n';
            monopolyData << dec[i].pieceIndicator << '\n';
            monopolyData << dec[i].money << '\n';
            monopolyData << dec[i].pardonCards << '\n';
            monopolyData << dec[i].isBankrupt << '\n';
            monopolyData << dec[i].isInJail << '\n';
        }
        for (int i = 0; i < 20; i++) { // loop that iterates and saves transmutable values
            monopolyData << squareStats[i].propertyOwner << '\n';
            monopolyData << squareStats[i].propertyHouse << '\n';
        }
    }else {
        std::cout << "Error: monopolyData.txt not open" << std::endl; // error message to indicate the file was not opened
    }
    monopolyData << lastPlayerTurn;
    monopolyData.close();
}

bool initialize(Player dec[],int& plyrcount, int &lastPlayerTurn) {
    std::string bucket; // temp variable used to hold data
    std::ifstream monopolyData("monopolyData.txt"); // open file i stream
    try {
        std::getline(monopolyData,bucket); // if this throws an invalid argument then return true to initialize new game
        plyrcount = std::stoi(bucket); // get the amount of players
    } catch (std::invalid_argument) {
        return true;
    }
    if (std::stoi(bucket) > 1 || std::stoi(bucket) < 5) {
        for (int i = 0; i < plyrcount; i++) {
            std::getline(monopolyData, bucket); // get position data
            dec[i].position = std::stoi(bucket);

            std::getline(monopolyData, dec[i].piece); // get piece data

            std::getline(monopolyData, bucket); // piece indicator data
            dec[i].pieceIndicator = bucket[0];

            std::getline(monopolyData, bucket); // get money data
            dec[i].money = std::stoi(bucket);

            std::getline(monopolyData, bucket); // get pardon card amount data
            dec[i].pardonCards = std::stoi(bucket);

            std::getline(monopolyData, bucket); // get if bankrupt condition
            dec[i].isBankrupt = std::stoi(bucket);

            std::getline(monopolyData, bucket); // get if in jail data
            dec[i].isInJail = std::stoi(bucket);
        }
        for (int i = 0; i < 20; i++) {
            try {
                std::getline(monopolyData, bucket); // this one gets the data for the squares and iterates for them
                squareStats[i].propertyOwner = bucket;

                std::getline(monopolyData, bucket);
                squareStats[i].propertyHouse = std::stoi(bucket);
            } catch (std::invalid_argument) {
                std::cout << "invalid argument error at " << i << std::endl;
                exit(1);
            }
        }

        std::getline(monopolyData, bucket); // get the last player turn for the game so the game could start at the right spot from the save
        lastPlayerTurn =  std::stoi(bucket);
    } else {
        std::cout << "Not enough saved players indicated in data index... Restarting game." << std::endl;
        return true;
    }

    monopolyData.close();
    std::cout << "Welcome back to RHODE ISLAND MONOPOLY!\n";
    return false;
}

void monopolyGame() {
    std::string plyrpropinput; //variables used much later
    int plyrchoice; // menu function input variable
    int plyrcount; // gets the player count from the player count function
    int lastPlayerTurn = 0; //used for save function, gets the player turn of the last game
    std::string bankruptcyChoice;


    Player dec[plyrcount]; //array creation for the players

    if (initialize(dec, plyrcount, lastPlayerTurn)) {
        plyrcount = playerCount();
        playerSelectTokenFunction(dec, plyrcount);  // Call to set up players' token names
        for (int i = 0; i < plyrcount; i++) { // sets up the tokens including all of their parameters
            dec[i].money = 1250;
            dec[i].position = 0;
            dec[i].pardonCards = 0;
            dec[i].isBankrupt = false;
            dec[i].isInJail = false;
        }
    }

    bool gameRunning = true; // gamerunning logic that ends the game if less than 2 players are active
    bool setPlayer = true; // this bool allows for an if to run once in a loop
    while (gameRunning) {
        int activePlayerCount = 0;  // Counter to track active players

        for (int i = 0; i < plyrcount; i++) {
            if (!dec[i].isBankrupt) {
                activePlayerCount++;
            }
        }

        if (activePlayerCount == 1) {
            for (int i = 0; i < plyrcount; i++) {
                if (!dec[i].isBankrupt) {
                    std::cout << "\nCongratulations! " << dec[i].piece << " is the winner!\n";
                    std::ofstream monopolyData("monopolyData.txt");
                    monopolyData << " ";
                    monopolyData.close();
                    gameRunning = false;  // End the game
                    break;
                }
            }
        }

        if (!gameRunning) break; // logic for the game running which checks specific parameters

        for (int i = 0; i < plyrcount; i++) {
            if (setPlayer == true) { // this small if statement sets the player turn to the last player that was saved, if I were to put
                i = lastPlayerTurn;// it like int i = lastPlayerTurn, its possible that some players turns will be skipped.
                setPlayer = false;
            }

            if (dec[i].money < 0) {
                dec[i].isBankrupt = true;
            }
            if (dec[i].isBankrupt) continue;
            bool endTurn = false;
            while (!endTurn) {

              if (dec[i].isInJail) {

              std::cout << "\n" << dec[i].piece << " is in jail.\n";

              // Check if the player has a pardon card, jail logic starts here --------------
              char choice;

    if (dec[i].isInJail) {
    if (dec[i].pardonCards) {
        bool validInput = false;

        while (!validInput) {
            std::cout << "\nYou have a pardon card! Would you like to use it to get out of jail? (Y/N): ";
            std::cin >> choice;

            while (std::cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')) {
                std::cout << "Invalid input, please enter Y or N: ";
                cinClear();
                std::cin >> choice;
            }

            if (choice == 'Y' || choice == 'y') {
                dec[i].isInJail = false;
                std::cout << "You used your pardon card to get out of jail!\n";
                endTurn = true;
                validInput = true;
            } else if (choice == 'N' || choice == 'n') {
                int diceRoll = dec[i].diceRollFunction();

                if (diceRoll % 2 == 0) {
                    std::cout << "You rolled an even number! You are out of jail.\n\n";
                    dec[i].isInJail = false;
                } else {
                    std::cout << "You did not roll an even number. You remain in jail.\n\n";
                }

                endTurn = true;
                validInput = true;
            } else {
                std::cout << "Invalid choice. Please enter Y or N.\n";
            }
        }
    } else {
        std::cout << "You don’t have any pardon cards!\n";
        int diceRoll = dec[i].diceRollFunction();

        if (diceRoll % 2 == 0) {
            std::cout << "You rolled an even number! You are out of jail.\n\n";
            dec[i].isInJail = false;
        } else {
            std::cout << "You did not roll an even number. You remain in jail.\n\n";
        }

        endTurn = true; // jail logic ends here ---------
    }
}
                    } else if (!dec[i].isInJail && !endTurn) {
                  std::cout << "\nIt is now " << dec[i].piece << "'s turn! \n - Enter 1 to roll the die, \n - Enter 2 to manage your properties, \n - Enter 3 to declare bankruptcy, \n - Enter 4 to view the board,\n - Enter 5 to exit the game!\n";
                  std::cin >> plyrchoice;

                while (plyrchoice != 1 && plyrchoice != 2 && plyrchoice != 3 && plyrchoice != 4 && plyrchoice != 5) {
                        std::cout << "Invalid input, please type a valid integer. \n\n Please enter 1 to roll the die, \n - Enter 2 to manage your properties, \n - Enter 3 to declare bankruptcy, \n - Enter 4 to view the board,\n - Enter 5 to exit the game!\n ";
                        cinClear();
                        std::cin >> plyrchoice;
                    }



                  std::string bankruptcyChoice; // Declare the variable here, outside the switch statement
                    }
            switch (plyrchoice) {
    case 1:
    dec[i].position += dec[i].diceRollFunction(); // Add dice roll to position
        if (dec[i].position > 19) {
            dec[i].money += 225;
            dec[i].position -= 20;
            continue;
        }
                displayBoard(dec[i].position, dec, plyrcount);

                if (dec[i].position == 7) {  // from here below are special cases for spots that call different functions ---------
        drawChanceCard(dec[i]);
    }
    else if (dec[i].position == 17) {
      drawCommunityCard(dec[i]);
    }
    else if (dec[i].position == 15) {
      std::cout << dec[i].piece <<  " has landed on " << squareStats[15].propertyName; std::cout << "\nBeing sent to jail...\n\n";
      dec[i].position = 5;

      dec[i].isInJail = true;
    }

    else if (squareStats[dec[i].position].propertyPosition == squareStats[5].propertyPosition) {
      std::cout << dec[i].piece <<  " has landed on prison visitation! (Point and laugh at anyone still in jail!)\n";
    }

    else if (squareStats[dec[i].position].propertyPosition == squareStats[10].propertyPosition) {
      std::cout << dec[i].piece <<  " has landed on a vacation square! Take a break!\n";
    }

    else if (squareStats[dec[i].position].propertyOwner == "Ownerless" && !squareStats[dec[i].position].isCardSquare){ //code overwritten here
      std::cout << dec[i].piece <<  " has landed on " << squareStats[dec[i].position].propertyName;
      std::cout << "\n\nWould you like to buy this property for $" << squareStats[dec[i].position].propertyValue << "? (Yes or No)\n";
      std::cin >> plyrpropinput;

        while (plyrpropinput != "Yes" && plyrpropinput != "No") {
            std::cout << "Invalid input, please type Yes or No: ";
            std::cin >> plyrpropinput;
        }

        if (plyrpropinput == "Yes") {
            dec[i].money -= squareStats[dec[i].position].propertyValue;

            std::cout << dec[i].piece <<  " has bought " << squareStats[dec[i].position].propertyName << "\n";

            squareStats[dec[i].position].propertyOwner = dec[i].piece;

            std::cout << "\nYou have " << dec[i].money << " dollars left!\n";
        }

        if (plyrpropinput == "Yes") {
          dec[i].money -= squareStats[dec[i].position].propertyValue;

          std::cout << dec[i].piece <<  " has bought " << squareStats[dec[i].position].propertyName << "\n";

          squareStats[dec[i].position].propertyOwner = dec[i].piece;

          std::cout << "\nYou have " << dec[i].money << " dollars left!\n";
        }
      } else if (squareStats[dec[i].position].propertyOwner != "Ownerless" &&
         squareStats[dec[i].position].propertyOwner != dec[i].piece) {

        std::string ownerName = squareStats[dec[i].position].propertyOwner;

        // Find the owner player in the player array
        int ownerIndex = -1;
        for (int j = 0; j < plyrcount; j++) {
            if (dec[j].piece == ownerName) {
                ownerIndex = j;
                break;
            }
        }

        if (ownerIndex != -1) { //rent logic for game
            if (ownerName != dec[i].piece) {
                std::cout << "You landed on " << squareStats[dec[i].position].propertyName
                    << ", which is owned by " << ownerName << "! You owe $" << (squareStats[dec[i].position].propertyValue) * (1 + squareStats[dec[i].position].propertyHouse) << " in rent.\n";

                dec[i].money -= (squareStats[dec[i].position].propertyValue) * (1 + squareStats[dec[i].position].propertyHouse);
                dec[ownerIndex].money += (squareStats[dec[i].position].propertyValue) * (1 + squareStats[dec[i].position].propertyHouse);

                std::cout << "You now have $" << dec[i].money << ". "
                        << ownerName << " now has $" << dec[ownerIndex].money << ".\n";
                        }
            else if (ownerName == dec[i].piece) {
                std::cout << "You landed on your own property! Nothing happens." << std::endl;
            }
        }
    }

    endTurn = true;
    break;
case 2: {
    std::cout << "\nManaging properties for " << dec[i].piece << "...\n\n";

    // Checking if the current player owns any properties
    bool ownsProperty = false;
    std::string ownerToCheck = dec[i].piece;  // Checks the active player

    // Iterate over properties to check if the player owns any
    for (const auto &square : squareStats) {
        if (square.propertyOwner == ownerToCheck) {
            if (!ownsProperty) {
                std::cout << "\n\nYou currently have $" << dec[i].money << "\n";
                std::cout << ownerToCheck << " owns the following properties:\n";
                ownsProperty = true;

            }
            std::cout << "- " << square.propertyName << " ($" << square.propertyValue << ")\n";
        }
    }

    if (!ownsProperty) {
        std::cout << ownerToCheck << " doesn't own any properties yet.\n";
    } else {
        // Ask if the player wants to buy houses for any of their properties
        std::cout << "Would you like to buy a house for any of your properties? (Yes/No): \n";
        std::cin >> plyrpropinput;

        while (plyrpropinput != "Yes" && plyrpropinput != "No") {
            std::cout << "Invalid input, please type Yes or No: ";
            cinClear();
            std::cin >> plyrpropinput;
        }

        if (plyrpropinput == "Yes") {
            // Iterate over the owned properties to allow the player to manage them
            for (auto &square : squareStats) {
                if (square.propertyOwner == ownerToCheck) {
                    // Show the property and ask if they want to buy a house
                    std::cout << "Would you like to buy a house for " << square.propertyName << "? It costs: "
                              << (square.propertyValue * 0.5) * (1 + square.propertyHouse) << "\n";
                    std::cout << "Current houses: " << square.propertyHouse << " (Max: 4)\n";
                    std::cout << "Enter 'Yes' to buy a house or 'No' to skip: ";
                    std::cin >> plyrpropinput;

                    while (plyrpropinput != "Yes" && plyrpropinput != "No") {
                        std::cout << "Invalid input, please type Yes or No: ";
                        cinClear();
                        std::cin >> plyrpropinput;
                    }

                    if (plyrpropinput == "Yes") {
                        if (square.propertyHouse < 4) {
                            // Deduct money from the player and increase the house count
                            int houseCost = (square.propertyValue * 0.5) * (1 + square.propertyHouse);
                            if (dec[i].money >= houseCost) {
                                dec[i].money -= houseCost;
                                square.propertyHouse++; // Increase house count
                                std::cout << "Bought a house on " << square.propertyName << " for $" << houseCost << ".\n";
                            } else {
                                std::cout << "Not enough money to buy a house.\n";
                            }
                        } else {
                            std::cout << "You already have the maximum number of houses on this property.\n";
                        }
                    } else {
                        std::cout << "Skipping house purchase for " << square.propertyName << ".\n";
                    }
                }
            }
        }
    }
    break;
}
    case 3: // makes bankruptcy bool true for current player
        std::cout << "\nAre you sure you want to file for bankruptcy? (Yes or No)\n";
        std::cin >> bankruptcyChoice;

                    while (bankruptcyChoice != "Yes" && bankruptcyChoice != "No") {
                        std::cout << "Invalid input, please type Yes or No: ";
                        cinClear();
                        std::cin >> bankruptcyChoice;
                    }

        if (bankruptcyChoice == "Yes") {
            std::cout << "\nYou have filed for bankruptcy and are now eliminated from the game!\n";
            dec[i].money = 0;
            dec[i].isBankrupt = true;
            endTurn = true;
        } else if (bankruptcyChoice == "No") {
            std::cout << "You have decided not to file for bankruptcy, the bank has gotten angry at you for wasting their time and is now skipping your turn.\n\n";
            endTurn = true;
        }
        break;

    case 4: // choice 4 brings up the display board with a function giving the player position parameter
        std::cout << "\n";
        displayBoard(dec[i].position, dec, plyrcount);
        break;

                case 5: // if player choice is 5 it ends the game
        save(dec,plyrcount, i);
        std::cout << "\nExiting the game... Thanks for playing!\n";
        exit(0);  // Terminates the program immediately
    }
}
        }
      }
}

int main () {

  monopolyGame(); //runs the monopoly game

  return 0;
}
