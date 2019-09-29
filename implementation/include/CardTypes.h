/**
 * \file CardTypes.h
 * \author Ali Kariapper
 * \brief Contains enumerated types for representing a card or stack of cards
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

#define TOTAL_CARDS   104


/**
 * \brief Enumerated type representing the four possible suits of a card
*/
enum SuitT {Heart, Diamond, Club, Spade};

/**
 * \brief Enumerated type representing the four possible suits of a card
*/
enum CategoryT {Tableau, Foundation, Deck, Waste};


/**
 * \brief Type type representing the suit and rank of a card
*/
struct CardT {
  SuitT s;
  RankT r;
} ;





#endif
