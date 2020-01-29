//  main.cpp
//  Target
//  Created by Adams Daouda on 1/16/20.
//  Copyright © 2020 Adams Daouda. All rights reserved.
//Displaying the Targets as many times as desired

int main()
{
  //Variable Declaration/Initialization
  int card1 = 0;   //Random # for card1
  int card2 = 0;   //Random # for card2
  int cardScore = 0;   //score accumulated for both scores
  int x = 0;     //x-coord where leftmost card is displayed
  int y = 0;     //y-coord where leftmost card is displayed
  
  
  //Display graphics
  displayGraphics();

  //Deal the cards
  deal(card1,card2);
  

  //Get the coords for the cards
  getCoords(x,y);

  //Display the 1st card
  displayCard(card1,x,y);

  //Display 2nd card
  displayCard(card2,x+150, y);

  //Compute the score
  cardScore = computeScore(card1,card2);

  //Display the score even with leftmost card at y-coord = 400
  displayResults(x,400,cardScore);

  return 0;
}

//Implement all functions here
void getCoords(int& x, int& y)
{
    cout<<"Enter x/y coordinates: ";
    cin >> x >> y;
}


void deal(int& card1, int& card2)
{
    srand(time(0));

    card1 = rand()%13 + 2;
    do
    {
        card2 = rand()%13 + 2;
    }while(card1 == card2);
}

int displayCard(int card,int x, int y)
{
    if (card == 2)
    {
        displayBMP("h2.bmp",x,y);
    }
    else if (card == 3)
    {
        displayBMP("h3.bmp",x,y);
    }
    else if (card == 4)
    {
        displayBMP("h4.bmp",x,y);
    }
    else if (card == 5)
    {
        displayBMP("h5.bmp",x,y);
    }
    else if (card == 6)
    {
        displayBMP("h6.bmp",x,y);
    }
    else if (card == 7)
    {
        displayBMP("h7.bmp",x,y);
    }
    else if (card == 8)
    {
        displayBMP("h8.bmp",x,y);
    }
    else if (card == 9)
    {
        displayBMP("h9.bmp",x,y);
    }
    else if (card == 10)
    {
        displayBMP("h10.bmp",x,y);
    }
    else if (card == 11)
    {
        displayBMP("hj.bmp",x,y);
    }
    else if (card == 12)
    {
        displayBMP("hq.bmp",x,y);
    }
    else if (card == 13)
    {
        displayBMP("hk.bmp",x,y);
    }
    else
    {
        displayBMP("ha.bmp",x,y);
    }

    return(card, x, y);
}

int computeScore(int card1, int card2)
{
    int cardScore;
if ((card1 == 10) || (card1 == 11) || (card1 == 12) || (card1 == 13))
{
    card1 = 10;
}
if (card1 == 14)
{
    card1 = 11;
}
if  ((card2 == 10) || (card2 == 11) || (card2 == 12) || card2 == 13)
{
    card2 = 10;
}
if (card2 == 14)
{
    card2 = 11;
}
    cardScore = card1 + card2;
        
    return(card1 + card2);
        
}
void displayResults(int x, int y, int cardScore)
{
    gout<< setPos(x,400) << "Total Score is: " << cardScore << endg;
    if (cardScore == 21)
    {
        gout << setPos(x,410) << "BlackJack!!!" <<endg;
    }

}
