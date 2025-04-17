#include <vector>
#include <string>
#include <iostream>


class Card {
public:
    friend class Deck;
    Card(std::string text) {
        this->text = text;
    }

    Card() : Card("Clear card") {};
private:
    std::string text;
    
};

class Deck {
public:
    friend class Card;
    void push_to_deck(Card new_card) {
        deck.push_back(new_card);
    }

    size_t get_size_of_deck() {
        return deck.size();
    }
    void print_cards() {
        for (std::vector<Card>::iterator it = deck.begin(); it != deck.end(); it++) {
            std::cout << (*it).text << std::endl;
        }
    }
private:
    std::vector<Card> deck;
};



int main() {
    Card new_card;
    Card new_card_2("Boss card");
    Deck mydeck;
    mydeck.push_to_deck(new_card);
    mydeck.push_to_deck(new_card_2);
    mydeck.print_cards();

}