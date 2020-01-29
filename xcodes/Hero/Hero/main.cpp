//  main.cpp
//  Hero
//  Created by Adams Daouda on 1/16/20.
//  Copyright © 2020 Adams Daouda. All rights reserved.
// Labin 7

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Classes

class Hero
{
private:
    string name;
    string item;
    int position;
    int strength;
public:
    Hero(){ name = ""; item = ""; position = 0; strength = 0; }
    Hero(string n, string i, int p, int s) { name = n; item = i; position = p, strength = s; }
    void setName(string n) { name = n; }
    void setItem(string i) { item = i; }
    void setStrength(int s) { strength = s; }
    void setPosition(int p) { position = p; }
    string getName() { return name; }
    string getItem() { return item; }
    int getStrength() { return strength; }
    int getPosition(){ return position; }
};


class Monsters
{
private:
    string name;
    string type;
    string toughness;
    int position;
    int strength;



public:
    Monsters() { name = ""; type = ""; toughness = ""; position = 0; strength = 0; }
    Monsters(string n, string tg, string t, int s, int p) { name = n; type = t, toughness = tg, strength = s, position = p; }
    void setName(string n) { name = n; }
    void setPosition(int p) { position = p; }
    void setType(string t) { type = t; }
    void setToughness(string tg) { toughness = tg; }
    void setStrength(int s) { strength = s; }
    string getName() { return name; }
    string getToughness() { return toughness; }
    int getPosition(){ return position; }
    int getStrength() { return strength; }
    string getType() { return type; }
};

class Item
{
private:
    string name;
    string type;
    int position;
public:
    Item() { name = ""; type = ""; position = 0; }
    Item(string n, string t, int p) { name = n; type = t, position = p; }
    void setName(string n) { name = n; }
    void setPosition(int p) { position = p; }
    void setType(string t) { type = t; }
    string getName() { return name; }
    int getPosition(){ return position; }
    string getType() { return type; }

};


class Road
{
private:
    vector<int> road;
    

public:
    void makeRoad(int N);
    void showRoad(Monsters Wolf, Monsters Bear, Monsters Dragon, Item Sword, Item Shield, Item Potion, Hero Goku);
    unsigned long int getsize() { return road.size(); }
    
};


void Road::makeRoad(int N)
{
    srand(time(NULL));

    //Adds values to each "road tile" to later give a terrain type
    road.resize(N);
    

    for (int i = 0; i < road.size(); i++)
    {
        road.at(i) = (rand() % 3) + 1;
        
    }
}
void Road::showRoad(Monsters Wolf, Monsters Bear, Monsters Dragon, Item Sword, Item Shield, Item Potion, Hero Goku)
{
    int grass, forrest, montain;
    for (int i = 0; i < road.size(); i++)
    {
        
        grass = 0;
        forrest = 0;
        montain = 0;
        //Display Tile Number
        cout << "Tile: " << i;

        //Determines Terrain type for each tile
        if (road.at(i) == 1)
        {
            cout << " - Grass";
            grass = 1;

        }
        else if (road.at(i) == 2)
        {
            cout << " - Forest";
            forrest = 1;
        }
        else if (road.at(i) == 3)
        {
            cout << " - Mountain";
            montain = 1;
        }
        //If Hero is on the tile, displays Hero and the stats
        if (i == Goku.getPosition())
            cout << " - " << Goku.getName() << "(Strength:" << Goku.getStrength() << ")" << "(Item:" << Goku.getItem() << ")";

        //If there is a monster on the tile, displays name and type
        if (i == Wolf.getPosition())
        {
            cout << " - " << Wolf.getName() << "(" << Wolf.getType() << "/" << "Strength:" << Wolf.getStrength() << ")";
            if (grass == 1)
                Wolf.setToughness("Grass");
        }
        if (i == Bear.getPosition())
        {
            cout << " - " << Bear.getName() << "(" << Bear.getType() << "/" << "Strength:" << Bear.getStrength() << ")";
            if (forrest == 1)
                    Wolf.setToughness("Forrest");
        }
        if (i == Dragon.getPosition())
        {
            cout << " - " << Dragon.getName() << "(" << Dragon.getType() << "/" << "Strength:" << Dragon.getStrength() << ")";
            if (montain == 1)
                Wolf.setToughness("Montain");
        }
        //If there is a Item on the tile, displays name and type
        if (i == Sword.getPosition())
            cout << " - " << Sword.getName() << "(Type:" << Sword.getType() << ")";
        if (i == Shield.getPosition())
            cout << " - " << Shield.getName() << "(Type:" << Shield.getType() << ")";
        if (i == Potion.getPosition())
            cout << " - " << Potion.getName() << "(Type:" << Potion.getType() << ")";
            cout << endl;

    }


}


//Function Prototypes
void placeMonsters(Road road, Monsters & Wolf, Monsters & Bear, Monsters & Dragon);
void placeItems(Road road, Item & Sword, Item & Shield, Item & Potion);
void makeHero(Hero & Goku);
void moveHero(Hero & Goku, char & redo);
void gameTime(Hero & Goku, Monsters & Wolf, Monsters & Bear, Monsters & Dragon);
void pickItem(Hero & Goku, Item & Sword, Item & Shield, Item & Potion);


int main()
{
    int N = 10;
    Road road;
    Monsters Wolf("wolfy", "Wolf"," ",3, 0);
    Monsters Bear("teddy", "Bear", " ", 5, 0);
    Monsters Dragon("Ryu", "dragon", " ", 7, 0);
    Hero Goku("Son Goku","", 0, 4);
    Item Sword("Excalibur","Sword",0);
    Item Shield("Ares's Shoulder", "Shield", 0);
    Item Potion("RedBull", "Potion", 0);
    char redo;


    road.makeRoad(N);
    placeMonsters(road, Wolf, Bear, Dragon);
    placeItems(road, Sword, Shield, Potion);
    road.showRoad(Wolf, Bear, Dragon, Sword, Shield, Potion,Goku);

    //Loops the move function until user wishes to stop

    do
    {
        
        moveHero(Goku, redo);

        gameTime(Goku, Wolf, Bear, Dragon);

        pickItem(Goku, Sword, Shield, Potion);

        if (Goku.getStrength() < 0)
            Goku.setStrength(0);

        road.showRoad(Wolf, Bear, Dragon, Sword, Shield, Potion, Goku);
        
        if ((Goku.getStrength() > 0) && ((Wolf.getStrength() >= 0) && (Bear.getStrength() >= 0) && (Dragon.getStrength() >= 0)))
        {
            cout << endl << "***---------------------------------------------***" << endl << endl;
            cout << "Do you wish to move again? (Y/N)";
            cin >> redo;
        }
        else if((Goku.getStrength() == 0) || ((Wolf.getStrength() == 0) && (Bear.getStrength() == 0) && (Dragon.getStrength() == 0)))
            redo = 'N';
        

    } while ((redo == 'y') || (redo == 'Y'));

    road.showRoad(Wolf, Bear, Dragon, Sword, Shield, Potion, Goku);

    cout << endl << "***------------GAME------------***" << endl << endl;

    cout << endl << "***------------OVER------------***" << endl << endl;
    return 0;
}


void placeMonsters(Road road, Monsters & Wolf, Monsters & Bear, Monsters & Dragon)
{
    int N;
    N = road.getsize();
    //Randomly assigns a position for each Monster
    srand(time(NULL));
    do {
        Dragon.setPosition((rand() % N - 1));
        do {
            Bear.setPosition((rand() % N - 1));
        } while (Bear.getPosition() > Dragon.getPosition());
        do {
            Wolf.setPosition((rand() % N - 1));
        } while (Wolf.getPosition() > Bear.getPosition());
        //Makes sure that, if any values are equal, to rerun the loop until they are all unique values
        if ((Wolf.getPosition() == Bear.getPosition()) || (Bear.getPosition() == Dragon.getPosition()))
        {
            Wolf.setPosition(0);
        }
    } while (Wolf.getPosition() < 1);
}
void placeItems(Road road, Item & Sword, Item & Shield, Item & Potion)
{
    int N;
    N = road.getsize();
    //Randomly assigns a position for each Monster
    srand(time(NULL));
    
        Sword.setPosition((rand() % N - 1));
        Shield.setPosition((rand() % N - 1));
        Potion.setPosition((rand() % N - 1));
        
    
}

void pickItem(Hero & Goku, Item & Sword, Item & Shield, Item & Potion)
{
    char ans = 'N';
    if (Goku.getPosition() == Sword.getPosition())
    {
        cout << "Pick up the sword??" << endl;
        cin >> ans;
        if ((ans == 'y') || (ans == 'Y'))
            Goku.setItem(Sword.getName());
    }
    if (Goku.getPosition() == Shield.getPosition())
    {
        cout << "Pick up the shield??" << endl;
        cin >> ans;
        if ((ans == 'y') || (ans == 'Y'))
            Goku.setItem(Shield.getName());
    }
    if (Goku.getPosition() == Potion.getPosition())
    {
        cout << "Pick up the potion??" << endl;
        cin >> ans;
        if ((ans == 'y') || (ans == 'Y'))
            Goku.setItem(Potion.getName());
    }


}

void moveHero(Hero & Goku, char & redo)
{
    char move, test;
    int loss;
    cout << "Press the 's' key to progress; Press the 'w' key to retreat." << endl;

    //Moves the hero based on the user's decision
    do
    {
        cin >> move;
        if (move == 's')
        {
            if (Goku.getPosition() < 9)
                Goku.setPosition(Goku.getPosition() + 1);
            else
            {
                cout << "You Have reached the end of the road you can only go back... " << endl;
                cout << "Enter (w/W) if  you want to go back. " << endl;
                cout << "Enter (N/n) if you want to stay: " << endl;
                cin >> test;
                if ((test == 'W') || (test == 'w'))
                    move = 'w';
                else
                    redo = 'N';

            }

        }

    } while ((move != 's') && (move != 'w'));
    //Has a chance for Hero to lose 1 strength when moving backwards
    srand(time(NULL));
    if (move == 'w')
    {
        Goku.setPosition(Goku.getPosition() - 1);
        loss = (rand() % 2);
        if (loss == 1)
            Goku.setStrength(Goku.getStrength() - 1);
    }
}
void gameTime(Hero & Goku, Monsters & Wolf, Monsters & Bear, Monsters & Dragon)
{
    //Initializing temp variables
    int heroStrength = Goku.getStrength();
    int wolfStrength = Wolf.getStrength();
    int BearStrength = Bear.getStrength();
    int DragonStrength = Dragon.getStrength();
    int wounds, defeated = 0;
    int temp = 0;
    int strengthTemp1, strengthTemp2;
    char revenge = 'N';
    int runAway = 0;

    do
    {
        do
        {
            revenge = 'N';
            runAway = 0;

            //Checking hero's position is equal to wolf's
            if ((Goku.getPosition() == Wolf.getPosition()) && (Wolf.getStrength() >= 0))
            {
                strengthTemp1 = rand() % Goku.getStrength() + 1;
                strengthTemp2 = rand() % Wolf.getStrength() + 1;

                //Doing battle
                if ((strengthTemp1 > strengthTemp2) && (Goku.getStrength() > 0))
                {
                
                    if ((Wolf.getToughness() == "Grass") && (strengthTemp1 > strengthTemp2 +1))
                    {
                    cout << endl;
                    cout << Wolf.getName() << " is too tough in" << Wolf.getToughness()<<"but you can handle it" << endl;
                    Wolf.setStrength(0);
                    Goku.setStrength((strengthTemp1)+2);

                    cout << "The wolf " << Wolf.getName() << " strength has fallen to 0" << endl;
                    cout << "You have killed the Wolf!!! You Absorb the its life force and gain +2 strength... " << endl;
                    cout << "Leaving " << Wolf.getName() << " carcass behind..." << endl;
                    cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                    runAway = 0;
                    
                    }
                    

                    else if ((Wolf.getToughness() == "Grass") && (strengthTemp1  < strengthTemp2 +1))
                    {
                        cout << Wolf.getName() <<" is too tough for you to handle" << endl;
                        cout << "Would you like to challenge " << Wolf.getName() << ", or run like the coward you seem to be ? " << endl;
                        cout << "(Y / N)" << endl;
                        cin >> revenge;
                        // if user trying to run activate the chase rule
                        if ((revenge == 'N') || (revenge == 'n') && (Goku.getStrength() > 0))
                        {
                            temp = rand() % 2;
                            Goku.setPosition(Goku.getPosition() - 1);

                            if (temp == 0)
                            {
                                defeated = 0;
                                Wolf.setPosition(Wolf.getPosition() - 1);
                                runAway = 1;
                                cout << Wolf.getName() << " isnt done with you coward! " << endl;
                            }
                        }
                    }
                    else if (Wolf.getToughness() != "Grass")
                    {
                        cout << endl;
                        Wolf.setStrength(0);
                        Goku.setStrength((strengthTemp1)+2);

                        cout << "The wolf " << Wolf.getName() << " strength has fallen to 0" << endl;
                        cout << "You have killed the Wolf!!! You Absorb the its life force and gain +2 strength... " << endl;
                        cout << "Leaving " << Wolf.getName() << " carcass behind..." << endl;
                        cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                        runAway = 0;
                    }

                    
                }
                else if ((strengthTemp1 == strengthTemp2) && (Goku.getStrength() > 0))
                {
                    cout << "Your strength and " << Wolf.getName() << " are evenly matched" << endl;
                    cout << "Would you like to challenge " << Wolf.getName() << ", or run like the coward you seem to be ? " << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;


                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || (revenge == 'n') && (Goku.getStrength() > 0))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;
                            
                            Wolf.setPosition(Wolf.getPosition() - 1);
                            runAway = 1;
                            cout << Wolf.getName() << " isnt done with you coward! " << endl;
                        }

                    }
                }

                else if ((strengthTemp1 < strengthTemp2) && (Goku.getStrength() > 0))
                {
                    defeated = 1;
                    wounds = strengthTemp2 - strengthTemp1;
                    Goku.setStrength(Goku.getStrength() - wounds);
                    cout << endl;
                    cout << "You put your best effort but fell short, " << Wolf.getName() << " is gnawing your bones!!!" << endl;
                    cout << "This humiliating defeat inflicts  -" << wounds << " to your strength... " << endl;
                    cout << "Your strength is " << Goku.getStrength() << endl;
                    cout << "Would you like to try and get your honor back or run like the coward you seem to be?" << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;
                    runAway = 0;

                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || (revenge == 'n') && (Goku.getStrength() > 0))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;
                            Wolf.setPosition(Wolf.getPosition() - 1);
                            runAway = 1;
                            cout << Wolf.getName() << " isnt done with you coward! " << endl;
                        }

                    }

                }

            }

        
            //Checking hero's position is equal to bear's
            if ((Goku.getPosition() == Bear.getPosition()) && (Bear.getStrength() >= 0))
            {
                strengthTemp1 = rand() % Goku.getStrength() + 1;
                strengthTemp2 = rand() % Bear.getStrength() + 1;

                //Doing battle
                if ((strengthTemp1 > strengthTemp2) && (Goku.getStrength() > 0))
                {

                    if ((Bear.getToughness() == "Forrest") && (strengthTemp1 > strengthTemp2 +1))
                    {
                        cout << endl;
                        cout << Bear.getName() << " is too tough in" << Bear.getToughness() << "but you can handle it" << endl;
                        Bear.setStrength(0);
                        Goku.setStrength((strengthTemp1)+2);
                        cout << "The Bear " << Bear.getName() << " strength has fallen to 0" << endl;
                        cout << "You have killed the Wolf!!! You Absorb the its life force and gain +2 strength... " << endl;
                        cout << "Leaving " << Bear.getName() << " carcass behind..." << endl;
                        cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                        runAway = 0;

                    }

                    else if ((Bear.getToughness() == "Montaine") && (strengthTemp1 < strengthTemp2 +1))
                    {
                        cout << Bear.getName() << " is too tough for you to handle" << endl;
                        cout << "Would you like to challenge " << Bear.getName() << ", or run like the coward you seem to be ? " << endl;
                        cout << "(Y / N)" << endl;
                        cin >> revenge;
                    }
                    else if (Bear.getToughness() != "Montain")
                    {
                        cout << endl;
                        Bear.setStrength(0);
                        Goku.setStrength((strengthTemp1)+2);

                        cout << "The Bear " << Bear.getName() << " strength has fallen to 0" << endl;
                        cout << "You have killed the Bear!!! You Absorb the its life force and gain +2 strength... " << endl;
                        cout << "Leaving " << Bear.getName() << " carcass behind..." << endl;
                        cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                        runAway = 0;
                    }


                }
                else if ((strengthTemp1 == strengthTemp2) && (Goku.getStrength() > 0))
                {
                    cout << "Your strength and " << Bear.getName() << " are evenly matched" << endl;
                    cout << "Would you like to challenge " << Bear.getName() << ", or run like the coward you seem to be ? " << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;


                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || ((revenge == 'n') && (Goku.getStrength() > 0)))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;

                            Bear.setPosition(Bear.getPosition() - 1);
                            runAway = 1;
                            cout << Bear.getName() << " isnt done with you coward! " << endl;
                        }

                    }
                }

                else if ((strengthTemp1 < strengthTemp2) && (Goku.getStrength() > 0))
                {
                    defeated = 1;
                    wounds = strengthTemp2 - strengthTemp1;
                    Goku.setStrength(Goku.getStrength() - wounds);
                    cout << endl;
                    cout << "You put your best effort but fell short, " << Bear.getName() << " is gnawing your bones!!!" << endl;
                    cout << "This humiliating defeat inflicts  -" << wounds << " to your strength... " << endl;
                    cout << "Your strength is " << Goku.getStrength() << endl;
                    cout << "Would you like to try and get your honor back or run like the coward you seem to be?" << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;
                    runAway = 0;

                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || ((revenge == 'n') && (Goku.getStrength() > 0)))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;
                            Bear.setPosition(Bear.getPosition() - 1);
                            runAway = 1;
                            cout << Bear.getName() << " isnt done with you coward! " << endl;
                        }
                    }
                }
            }

            //Checking hero's position is equal to Dragon's
            if ((Goku.getPosition() == Dragon.getPosition()) && (Dragon.getStrength() >= 0))
            {
                strengthTemp1 = rand() % Goku.getStrength() + 1;
                strengthTemp2 = rand() % Dragon.getStrength() + 1;

                //Doing battle
                if ((strengthTemp1 > strengthTemp2) && (Goku.getStrength() > 0))
                {

                    if ((Dragon.getToughness() == "Forrest") && (strengthTemp1 > strengthTemp2 +1))
                    {
                        cout << endl;
                        cout << Dragon.getName() << " is too tough in" << Dragon.getToughness() << "but you can handle it" << endl;
                        Bear.setStrength(0);
                        Goku.setStrength((strengthTemp1)+2);
                        cout << "The Dragon " << Dragon.getName() << " strength has fallen to 0" << endl;
                        cout << "You have killed the Dragon!!! You Absorb the its life force and gain +2 strength... " << endl;
                        cout << "Leaving " << Dragon.getName() << " carcass behind..." << endl;
                        cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                        runAway = 0;

                    }

                    else if ((Dragon.getToughness() == "Montaine") && (strengthTemp1 < strengthTemp2 +1))
                    {
                        cout << Dragon.getName() << " is too tough for you to handle" << endl;
                        cout << "Would you like to challenge " << Dragon.getName() << ", or run like the coward you seem to be ? " << endl;
                        cout << "(Y / N)" << endl;
                        cin >> revenge;
                    }
                    else if (Dragon.getToughness() != "Montain")
                    {
                        cout << endl;
                        Dragon.setStrength(0);
                        Goku.setStrength((strengthTemp1)+2);

                        cout << "The Dragon " << Dragon.getName() << " strength has fallen to 0" << endl;
                        cout << "You have killed the Wolf!!! You Absorb the its life force and gain +2 strength... " << endl;
                        cout << "Leaving " << Dragon.getName() << " carcass behind..." << endl;
                        cout << "You walk away stronger than ever before with your strength level " << Goku.getStrength() << endl;
                        runAway = 0;
                    }


                }
                else if ((strengthTemp1 == strengthTemp2) && (Goku.getStrength() > 0))
                {
                    cout << "Your strength and " << Dragon.getName() << " are evenly matched" << endl;
                    cout << "Would you like to challenge " << Dragon.getName() << ", or run like the coward you seem to be ? " << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;


                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || (revenge == 'n') && (Goku.getStrength() > 0))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;

                            Dragon.setPosition(Dragon.getPosition() - 1);
                            runAway = 1;
                            cout << Dragon.getName() << " isnt done with you coward! " << endl;
                        }

                    }
                }

                else if ((strengthTemp1 < strengthTemp2) && (Goku.getStrength() > 0))
                {
                    defeated = 1;
                    wounds = strengthTemp2 - strengthTemp1;
                    Goku.setStrength(Goku.getStrength() - wounds);
                    cout << endl;
                    cout << "You put your best effort but fell short, " << Dragon.getName() << " is gnawing your bones!!!" << endl;
                    cout << "This humiliating defeat inflicts  -" << wounds << " to your strength... " << endl;
                    cout << "Your strength is " << Goku.getStrength() << endl;
                    cout << "Would you like to try and get your honor back or run like the coward you seem to be?" << endl;
                    cout << "(Y / N)" << endl;
                    cin >> revenge;
                    runAway = 0;

                    // if user trying to run activate the chase rule
                    if ((revenge == 'N') || (revenge == 'n') && (Goku.getStrength() > 0))
                    {
                        temp = rand() % 2;
                        Goku.setPosition(Goku.getPosition() - 1);

                        if (temp == 0)
                        {
                            defeated = 0;
                            Dragon.setPosition(Dragon.getPosition() - 1);
                            runAway = 1;
                            cout << Dragon.getName() << " isnt done with you coward! " << endl;
                        }
                    }
                }
            }
            //resetting variables
            strengthTemp1 = 0;
            strengthTemp2 = 0;

        }while (runAway == 1);

    } while (((revenge == 'Y') || (revenge == 'y')) && (Goku.getStrength() > 0));

    if ((defeated == 1) && (Goku.getPosition() != 0))
        Goku.setPosition(Goku.getPosition() - 1);


}

