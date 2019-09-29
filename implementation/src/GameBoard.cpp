#include "CardTypes.h"
#include "GameBoard.h"
#include <iostream>
#include <vector>
#include "Stack.h"
#include "CardStack.h"




// private methods
BoardT::BoardT(std::vector<CardT> deck) {

    
    if (!(two_decks(init_seq(10),init_seq(8),Stack<CardT>(deck),Stack<CardT>())))
        throw std::invalid_argument("");
    else {


    std::vector<CardT> temp1;
    for (int i = 0; i < 40; i++){
        temp1.push_back(deck[i]);
    }
    this->T = tab_deck(temp1);
    
    this->W = Stack<CardT>();

    this->F = init_seq(8);

    for(int x = 40; x < 104; x++){
        this->D.push(deck[x]);
    }
    }
    
}





bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1){

    
    if (c == Tableau){
        if (!(is_valid_pos(Tableau,n0) && is_valid_pos(Tableau,n1))) {
            throw std::out_of_range("");
        }
        return valid_tab_tab(n0,n1);
    }    
    else if (c == Foundation) {
        if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Foundation, n1))) {
            throw std::out_of_range("");
        }
        return valid_tab_foundation(n0,n1);
    }
    else return false;
}

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n){
    if (this->W.size() == 0) throw std::invalid_argument("");
    if (c == Tableau && !(is_valid_pos(Tableau,n))) throw std::out_of_range("");
    if (c == Foundation && !(is_valid_pos(Foundation,n))) throw std::out_of_range("");
    
    if (c == Tableau) return valid_waste_tab(n);
    else if (c == Foundation) return valid_waste_foundation(n);
    else return false;
    
}

bool BoardT::is_valid_deck_mv(){
    return (this->D.size() > 0);
}

void BoardT::tab_mv(CategoryT c, unsigned int n0, unsigned int n1) {
    if (!(is_valid_tab_mv(c,n0,n1))) throw std::invalid_argument("");
    if (c == Tableau){
    this->T[n1] = this->T[n1].push(this->T[n0].top());
    this->T[n0] = this->T[n0].pop();
    }

    if (c == Foundation){
    this->F[n1] = this->F[n1].push(this->T[n0].top());
    this->T[n0] = this->T[n0].pop();
    }
}

void BoardT::waste_mv(CategoryT c, unsigned int n){
    if (!(is_valid_waste_mv(c,n))) throw std::invalid_argument("");

    if (c == Tableau) {
        this->T[n] = this->T[n].push(this->W.top());
        this->W = this->W.pop();
    }
    if (c == Foundation) {
        this->F[n] = this->F[n].push(this->W.top());
        this->W = this->W.pop();
    }
}

void BoardT::deck_mv(){
    if (!(is_valid_deck_mv())) throw std::invalid_argument("");
    this->W = this->W.push(this->D.top());
    this->D = this->D.pop();
}

CardStackT BoardT::get_tab(unsigned int i){
    if (!(is_valid_pos(Tableau,i))) throw std::out_of_range("");
    return this->T[i];
}

CardStackT BoardT::get_foundation(unsigned int i){
    if (!(is_valid_pos(Foundation,i))) throw std::out_of_range("");
    return this->F[i];
}

CardStackT BoardT::get_deck() {
    return this->D;
}

CardStackT BoardT::get_waste() {
    return this->W;
}

bool BoardT::valid_mv_exists(){
    
    if (valid_tab_mv())
        return true;
    if (valid_waste_mv())
        return true;
    if (is_valid_deck_mv())
        return true;
    return false;
}

bool BoardT::is_win_state(){
    for (int i = 0; i < 8; i++) {
        if (!((this->F[i].size() > 0 ) && (this->F[i].top().r == KING)))
            return false;
    return true;

  

    }
}


//Local Functions

bool BoardT::two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W) {
    const SuitT suit[] = {SuitT::Heart, SuitT::Diamond, SuitT::Club, SuitT::Spade };
    for ( SuitT st : suit) {
        for (RankT rk = ACE; rk <= KING; rk++){
            CardT f = {st,rk};
            if (cnt_cards(T,F,D,W,f) != 2)
                return false;
        }

    }
    return true;
} 

unsigned int BoardT::cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W, CardT f ) {
    int cards = 0;
    cards += cnt_cards_seq(T,f) + cnt_cards_seq(F,f) + cnt_cards_stack(D, f) + cnt_cards_stack(W, f);
    return cards;
}

unsigned int BoardT::cnt_cards_stack(CardStackT S, CardT f) {
    unsigned int x = 0;
    for (int i = 0; i < S.size(); i++){
     if (S.toSeq()[i].s == f.s && S.toSeq()[i].r == f.r) {
         x = x + 1;
     }
    }
    return x;
}

unsigned int BoardT::cnt_cards_seq(SeqCrdStckT S, CardT f) {
    unsigned int count = 0;
    for(int stackNum = 0; stackNum < S.size(); stackNum ++) {
        count = count + cnt_cards_stack(S[stackNum], f);
    }
    return count;

    }







SeqCrdStckT BoardT::tab_deck(std:: vector<CardT> deck) {
    SeqCrdStckT initTab;
    for (int i = 0; i < 10; i++) {
            std::vector<CardT> temp;
            for (int x = (4*i); x < (4*(i + 1)); x++) {
                temp.push_back(deck[x]);
            }
            initTab.push_back(Stack<CardT>(temp));
    }
    return initTab;
        
}

SeqCrdStckT BoardT::init_seq(unsigned int n) {
    SeqCrdStckT initFoundation;
    for (int i = 0; i < n; i++) {
        std::vector<CardT> temp;
        initFoundation.push_back(Stack<CardT>(temp));
    }
    return initFoundation;
} 

bool BoardT::valid_tab_tab(unsigned int n0, unsigned int n1) {
    if (this->T[n0].size() > 0) {
        if (this->T[n1].size() > 0) {
            return tab_placeable(this->T[n0].top(),this->T[n1].top());
        }
        else return true; 
        }
    else return false;
}

bool BoardT::valid_tab_foundation(unsigned int n0, unsigned int n1) {
    if (this->T[n0].size() > 0) {
        if (this->F[n1].size() > 0) {
            return foundation_placeable(this->T[n0].top(),this->F[n1].top());
        }
        else 
            return (this->T[n0].top().r == ACE);
        }
    else return false;
}

bool BoardT::tab_placeable(CardT c, CardT d) {
    return (c.s == d.s && c.r == d.r-1);
}

bool BoardT::foundation_placeable(CardT c, CardT d) {
    return (c.s == d.s && c.r == d.r+1);
}

bool BoardT::is_valid_pos(CategoryT c, unsigned int n) {
    if (c == Tableau && n <= 9) 
        return true;
    else if (c == Foundation && n <= 7) 
        return true;
    else return false;
}

bool BoardT::valid_waste_tab(unsigned int n){
    if (this->T.size() > 0) 
        return tab_placeable(this->W.top(), this->T[n].top());
    else 
        return true;
}

bool BoardT::valid_waste_foundation(unsigned int n){
    if (this->F[n].size() > 0)
        return foundation_placeable(this->W.top(), this->F[n].top());
    else 
        return (this->W.top().r == ACE);
}

bool BoardT::valid_tab_mv(){
    CategoryT category[] = {Tableau, Foundation};
    unsigned int size[] = {10,8};
    for(int i = 0; i < 2; i++){
        CategoryT c = category[i];
        for (int n0 = 0; n0 < 10; n0++) {
            for(int j = 0; j < 2; j ++){    
                for(int n1 = 0; n1 < size[j]; n1++){
                    if (is_valid_pos(Tableau,n0) && is_valid_pos(c,n1)){
                        if (is_valid_tab_mv(c,n0,n1) == true)
                            return true;
                    }
                }
            }
        }    

    }
    return false;
}

bool BoardT::valid_waste_mv(){
    if (this->W.size() == 0)
        return false;
    CategoryT category[] = {Tableau, Foundation};
    unsigned int size[] = {10,8};
    for(int i = 0; i < 2; i++){
        CategoryT c = category[i];
            for(int j = 0; j < 2; j ++){    
                for(int n = 0; n < size[j]; n++){
                    if (is_valid_pos(c,n)) {
                        if (is_valid_waste_mv(c,n) == true) 
                            return true;
                            
                    }
                }
            }
    }
    return false;
}
                    
                
                
            













