/**
 * \file GameBoard.h
 * \brief An abstract data type (ADT) for representing the state of a game of FreeCell Solitaire.
 * \author Christopher W. Schankula, MacID: schankuc
*/

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include <vector>

#include "CardTypes.h"
#include "CardStack.h"

/**
 *  \brief Class for representing the gameboard of a game of 40 theives
 */
class BoardT {
    private:
        CardStackT W;
        CardStackT D;
        SeqCrdStckT T;
        SeqCrdStckT F;
        SeqCrdStckT init_seq(unsigned int n);
        SeqCrdStckT tab_deck(std::vector<CardT> deck);
        bool valid_tab_tab(unsigned int n0, unsigned int n1);
        bool tab_placeable(CardT c, CardT d);
        bool valid_tab_foundation(unsigned int n0, unsigned int n1);
        bool foundation_placeable(CardT c, CardT d);
        bool is_valid_pos(CategoryT c, unsigned int n);
        bool valid_waste_tab(unsigned int n);
        bool valid_waste_foundation(unsigned int n);
        bool valid_tab_mv();
        bool valid_waste_mv();
        bool two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W);
        unsigned int cnt_cards_seq(SeqCrdStckT S, CardT f );
        unsigned int cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W, CardT f);
        unsigned int cnt_cards_stack(CardStackT s, CardT f);

    public:

    	/**
		 *  \brief Constructs a new game of 40 thieves
		 *  \param deck Sequence of cards from two decks to be used to play 40 thieves
		 */
        BoardT(std:: vector<CardT> deck);

    	/**
		 *  \brief Returns whether a card can be moved from a tableau
		 *  \param c The category where the card is to be moved to
         *  \param n1 The idenitifer of which number tableau the card is to be moved from
         *  \param n2 The identifier of which number of the type of category the card is to be placed on
         *  \return true is move is possible and false if not
		 */
        bool is_valid_tab_mv(CategoryT c, unsigned int n1, unsigned int n2);

        /**
		 *  \brief Returns whether a card can be moved from the waste pile
		 *  \param c The category where the card is to be moved to
         *  \param no The idenitifer of which number Category the card is to be moved to
         *  \return true is move is possible and false if not
		 */
        bool is_valid_waste_mv(CategoryT c, unsigned int n);
        
        /**
		 *  \brief Returns whether a card can be moved from the deck
         *  \return true is move is possible and false if not
		 */
        bool is_valid_deck_mv();

        /**
		 *  \brief Moves card from tableau to desired category
		 *  \param c The category where the card is to be moved to
		 *  \param n0 The number of which tableau the card is to be moved from
		 *  \param n1 The identifier of which number category the card is to be moved to
		 */
        void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);
        
        /**
		 *  \brief Moves card from waste to desired category
		 *  \param c The category where the card is to be moved to
		 *  \param n1 The identifier of which number category the card is to be moved to
		 */
        void waste_mv(CategoryT c, unsigned int n);

        /**
		 *  \brief Moves card from deck to waste 
		 */
        void deck_mv();


        /**
		 *  \brief Returns a tableau
		 *  \param i The identifier of which number tableau to return
         *  \return The desired tableau
		 */
        CardStackT get_tab(unsigned int i);

        /**
		 *  \brief Returns a chosen foundation
		 *  \param i The identifier of which number foundatoin to return
         *  \return The desired foundation
		 */
        CardStackT get_foundation(unsigned int i);

        /**
		 *  \brief Returns the cards in the deck
         *  \return The stack of cards in the deck
		 */
        CardStackT get_deck();

        /**
		 *  \brief Returns the cards in the waste stack
         *  \return The stack of cards in the waste pile
		 */
        CardStackT get_waste();

        /**
		 *  \brief Checks if there is an available move in the current game state
         *  \return true is a move can be made and false if not
		 */
        bool valid_mv_exists();

        /**
		 *  \brief Checks if the game has been won
         *  \return true if the game has been beat and false if not
		 */
        bool is_win_state();
        
};




#endif
