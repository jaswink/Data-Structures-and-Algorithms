#include <string>
#include <iostream>
#include <algorithm>        
#include <ctime>        
#include <cstdlib>
#include "deck.h"

Deck::Deck()
{//This creates a Deck of 52 cards and we represent the deck as a vector called deckOfCards.
  Card c;
  for(int i=c.SPADES;i<=c.DIAMONDS;i++)
  {
    for(int j=c.ACE;j<=c.KING;j++)
    {
      c.set_value(j, i);
      this->deckOfCards.push_back(c);
    }
  }
  totalNoOfCards=deckOfCards.size();
}
  
Deck::~Deck()
{
  deckOfCards.clear();
}
  
void Deck::deal_hand(int sets, int cards)
{//We distribute/deal the equal number of cards : cards into the given sets :sets. 
//This function also print the cards each set has after distribution.
  int count=cards;
  int i,j;
  int startCount=0;
  for(i=0;i<sets;i++)
  {
    cout<<"Set "<<i+1<<" Cards ";
    for(j=startCount;j<cards;j++)
    {
      deckOfCards[j].print();
    }
    if(j==cards)
    {
        startCount=j;
        cards+=count;
    }
    cout<<endl;
  }
}
  
void Deck::print_deck()
{ 
// This function prints the entire deck of 52 cards and each suit cards are in different line.
  for(int i=0;i<totalNoOfCards;i++)
  {
    Card cardToBePrinted=deckOfCards[i];
    cardToBePrinted.print();
    //After printing of each suit cards, print the next suit cards in the next line.
    if((i+1)%13==0)
      cout<<endl;
  }
}

void Deck::shuffle(int seed)
{
  //srand (time(NULL)); //srand(seed);
	// std::shuffle(deckOfCards.begin(),deckOfCards.end(),default_random_engine(seed));
  //Seed the random number generator
  srand(seed);  
  for(int i=0;i<totalNoOfCards;i++)
  {
    //Generate a random number and swap it with the card starting from the first one, second one and so on...
    //It is possible to have the random number or index for deckOfCards for swapping to be the same.
    int randCard = i + (rand()%(52-i));
    swap(deckOfCards[i],deckOfCards[randCard]);
  }
}

void Deck::sort()
{
  //Implemented Selection Sort for now, we can implement more optimized algorithms given the time constraints.

  //Sorting by suit SPADES>HEARTS>CLUBS>DIAMONDS
  int maxIndex,startIndex;
  int maxSuit;
  for (startIndex = 0; startIndex < totalNoOfCards; startIndex++)
  {
    maxIndex = startIndex;
    maxSuit = deckOfCards[startIndex].get_suit();
    for (int i = startIndex + 1; i < totalNoOfCards; i++)
    {
      if (deckOfCards[i].get_suit()<maxSuit)
      {
        maxSuit=deckOfCards[i].get_suit();
        maxIndex=i;
      }
    }
    swap(deckOfCards[maxIndex],deckOfCards[startIndex]);
  }
  //Sorting by face value King,Queen,Jack,10,9,8,7,6,5,4,3,2,Ace
  int suitRow=4;
  int startIndexVal=0;
  int endIndexVal=13;
  while(suitRow--) 
  {
    for (startIndex = startIndexVal; startIndex < endIndexVal; startIndex++)
    {
      maxIndex = startIndex;
      maxSuit = deckOfCards[startIndex].get_value();
      for (int i = startIndex + 1; i < endIndexVal; i++)
      {
        if (deckOfCards[i].get_value()>maxSuit)
        {
          maxSuit=deckOfCards[i].get_value();
          maxIndex=i;
        }
      }
      swap(deckOfCards[maxIndex],deckOfCards[startIndex]);
    }
    startIndexVal=endIndexVal;
    endIndexVal+=13;
  }
}