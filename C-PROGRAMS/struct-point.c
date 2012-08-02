#include <stdio.h>

struct card {                           
   char *face; 
   char *suit; 
   int value;
};

int main()
{ 
   struct card aCard; 
   struct card *cardPtr;

   aCard.face = "Ace";   
   aCard.suit = "Spades";
   aCard.value = 100;

   cardPtr = &aCard;

   printf( "%s%s%s\n%s%s%s\n%s%s%s\n%d%s%d\n", aCard.face, " of ", aCard.suit,
      cardPtr->face, " of ", cardPtr->suit,                           
      ( *cardPtr ).face, " of ", ( *cardPtr ).suit, cardPtr->value, " of ", aCard.value );
   
   return 0;
}
