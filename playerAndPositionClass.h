
class Player {
public:
    int position;
    std::string piece;
    int money;
    int pardonCards;
    bool isBankrupt;
    bool isInJail;

    int diceRollFunction() {
        std::srand(time(NULL));
        int randomRoll = (rand() % 6) + 1;
        std::cout << "You rolled a " << randomRoll << std::endl;
        return randomRoll;
    }

    int cardRollFunction() {
        std::srand(time(NULL));
        int randomRoll = (rand() % 7);  // Randomly select a card
        return randomRoll;
    }
};

class boardSquare {
public:
    std::string propertyName;
    int propertyValue;
    int propertyPosition;
    int propertyHouse = 0;  // Number of houses (starts at 0)
    std::string propertyOwner;
    bool isCardSquare;  // Flag for Chance/Community card square

    // Constructor
    boardSquare(std::string n, int v, int p, std::string o, bool card = false, int h = 0) {
        propertyName = n;
        propertyValue = v;
        propertyPosition = p;
        propertyOwner = o;
        isCardSquare = card;
    }
};
// name price house
// Defining an array of properties
boardSquare squareStats[] = {
    boardSquare("Starting Square", 0, 1, "Ownerless", true, 0),
    boardSquare("Broad St.", 50, 2, "Ownerless", 0),
    boardSquare("Manton Ave.", 75, 3, "Ownerless", 0),
    boardSquare("Water Utility", 150, 4, "Ownerless", 0),
    boardSquare("Hartord Ave", 100, 5, "Ownerless", 0),
    boardSquare("Prison", 0, 6, "Ownerless", true, 0),
    boardSquare("Chance Card", 0, 7, "Ownerless", true, 0),
    boardSquare("Chalkstone Ave.", 125, 8, "Ownerless", 0),
    boardSquare("Branch Ave.", 150, 9, "Ownerless", 0),
    boardSquare("Mount Pleasant", 175, 10, "Ownerless", 0),
    boardSquare("Vacation", 0, 11, "Ownerless", true, 0),
    boardSquare("Wickenden St.", 200, 12, "Ownerless", 0),
    boardSquare("Thayer St.", 225, 13, "Ownerless", 0),
    boardSquare("Electric Utility", 150, 14, "Ownerless", 0),
    boardSquare("Jewelry District", 250, 15, "Ownerless", 0),
    boardSquare("Go to prison", 0, 16, "Ownerless", true, 0),
    boardSquare("Block Island", 275, 17, "Ownerless", 0),
    boardSquare("Community Card", 0, 18, "Ownerless", true, 0),
    boardSquare("Brown University", 300, 19, "Ownerless", 0),
    boardSquare("Newport Mansions", 325, 20, "Ownerless", 0)
};

