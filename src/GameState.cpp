#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include "DEFINITIONS.hpp"

namespace DAi
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
    }

    bool isCardADominium(int cardName)
    {
        if ((cardName >= 20 && cardName <= 22) || (cardName >= 33 && cardName <= 35) || (cardName >= 46 && cardName <= 48) || (cardName >= 59 && cardName <= 61) || (cardName == 10 || cardName == 23 || cardName == 36 || cardName == 49))
        {
            return true;
        }
        return false;
    }

    int GameState::whatDominium()
    {
        switch (this->_dominiumPile.top().getCardName())
        {
            //Jack
        case 20:
        case 33:
        case 46:
        case 59:
            return 1;
            break;
            //Queen
        case 21:
        case 34:
        case 47:
        case 60:
            return 2;
            break;
            //King
        case 22:
        case 35:
        case 48:
        case 61:
            return 3;
            break;
            //Ace
        case 10:
        case 23:
        case 36:
        case 49:
            return 4;
            break;

        default:
            break;
        }
    }
    void GameState::calculateOutcome()
    {
        switch (this->whatDominium())
        {
        case JACK:
            break;
        case QUEEN:
            break;
        case KING:
            break;
        case ACE:
            break;
        default:
            break;
        }
    }

    void GameState::updateDominiumSprite()
    {
        this->_playedDominium.setTexture(this->_data->assets.getTexture(std::to_string(this->_dominiumPile.top().getCardName())));
        this->_playedDominium.setScale(0.5, 0.5);
        this->_playedDominium.setPosition((SCREEN_WIDTH / 2) - (this->_playedDominium.getGlobalBounds().width * 1.8), (SCREEN_HEIGHT / 2) - (this->_playedDominium.getGlobalBounds().height / 2));
    }

    void GameState::slideCards(bool isFPTurn, int index)
    {
        if (isFPTurn)
        {
            std::vector<sf::Sprite> tempSprites;
            for (int i = 0; i < 4; i++)
            {
                if (index != i)
                {
                    tempSprites.push_back(this->_FPHsprites[i]);
                }
            }
            this->_FPHsprites.clear();
            this->_FPHsprites = tempSprites;
            this->_FPHsprites.push_back(this->dummy);
            for (int i = 0; i < 4; i++)
            {
                this->_FPHsprites.at(i).setPosition((SCREEN_WIDTH / 2) - (this->_FPHsprites.at(i).getGlobalBounds().width * 2) + (this->_FPHsprites.at(i).getGlobalBounds().width * i) + (15 * i / i), (SCREEN_HEIGHT) - (this->_FPHsprites.at(i).getGlobalBounds().height));
            }
        }
        else
        {
            std::vector<sf::Sprite> tempSprites;
            for (int i = 0; i < 4; i++)
            {
                if (index != i)
                {
                    tempSprites.push_back(this->_SPHsprites[i]);
                }
            }
            this->_SPHsprites.clear();
            this->_SPHsprites = tempSprites;
            this->_SPHsprites.push_back(this->dummy);
            for (int i = 0; i < 4; i++)
            {
                this->_SPHsprites.at(i).setPosition((SCREEN_WIDTH / 2) - (this->_SPHsprites.at(i).getGlobalBounds().width * 2) + (this->_SPHsprites.at(i).getGlobalBounds().width * i) + (15 * i / i), (SCREEN_HEIGHT) - (this->_SPHsprites.at(i).getGlobalBounds().height));
            }
        }
    }

    void GameState::playCard(int index, std::vector<Card> playerHand)
    {
        this->_field.push_back(playerHand[index]);
        if (!isCardADominium(playerHand[index].getCardName()))
        {

            if (this->firstPlayerTurn)
            {
                this->_fieldSprites[0].setTexture(this->_data->assets.getTexture(std::to_string(this->_field[0].getCardName())));
                this->_fieldSprites[0].setScale(0.5, 0.5);
                this->_fieldSprites[0].setPosition((SCREEN_WIDTH / 2) - (this->_fieldSprites[0].getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_fieldSprites[0].getGlobalBounds().height / 2));
            }
            else
            {
                this->_fieldSprites[1].setTexture(this->_data->assets.getTexture(std::to_string(this->_field[1].getCardName())));
                this->_fieldSprites[1].setScale(0.5, 0.5);
                this->_fieldSprites[1].setPosition((SCREEN_WIDTH / 2) - (this->_fieldSprites[1].getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_fieldSprites[1].getGlobalBounds().height / 2));
            }
        }
        else
        {

            this->_dominiumPile.push(playerHand[index]);
            this->updateDominiumSprite();
        }

        std::vector<Card> tempHand;
        for (int i = 0; i < 4; i++)
        {
            if (index != i)
            {
                tempHand.push_back(playerHand[i]);
            }
        }

        playerHand.clear();

        playerHand = tempHand;

        this->slideCards(this->firstPlayerTurn, index);
        this->calculateOutcome();
        if (!this->firstPlayerTurn)
        {
            this->_field.clear();
        }
        this->turnCardDraw();
        this->firstPlayerTurn = !this->firstPlayerTurn;
    }

    void GameState::turnCardDraw()
    {
        this->_firstPlayerHand.push_back(this->_deck.getTopCard());
        this->_secondPlayerHand.push_back(this->_deck.getTopCard());

        this->_data->assets.loadTexture(std::to_string(this->_firstPlayerHand.back().getCardName()), this->_firstPlayerHand.back().getFilePath());
        this->_FPHsprites.back().setTexture(this->_data->assets.getTexture(std::to_string(this->_firstPlayerHand.back().getCardName())));
        this->_FPHsprites.back().setScale(0.5, 0.5);
        this->_FPHsprites.back().setPosition((SCREEN_WIDTH / 2) - (this->_FPHsprites.back().getGlobalBounds().width * 2) + (this->_FPHsprites.back().getGlobalBounds().width * 3) + (15 * 3 / 3), (SCREEN_HEIGHT) - (this->_FPHsprites.back().getGlobalBounds().height));

        this->_data->assets.loadTexture(std::to_string(this->_secondPlayerHand.back().getCardName()), this->_secondPlayerHand.back().getFilePath());
        this->_SPHsprites.back().setTexture(this->_data->assets.getTexture(std::to_string(this->_secondPlayerHand.back().getCardName())));
        this->_SPHsprites.back().setScale(0.5, 0.5);
        this->_SPHsprites.back().setPosition((SCREEN_WIDTH / 2) - (this->_SPHsprites.back().getGlobalBounds().width * 2) + (this->_SPHsprites.back().getGlobalBounds().width * 3) + (15 * 3 / 3), (SCREEN_HEIGHT) - (this->_SPHsprites.back().getGlobalBounds().height));
    }

    void GameState::findADominium()
    {
        this->_dominiumPile.push(this->_deck.getFirstDominium());
        this->_data->assets.loadTexture(std::to_string(this->_dominiumPile.top().getCardName()), this->_dominiumPile.top().getFilePath());
        this->updateDominiumSprite();
    }

    void GameState::initialCardDraw()
    {
        this->_deck.shuffleDeck();
        this->_deck.shuffleDeck();
        this->_firstPlayerHand.clear();
        this->_secondPlayerHand.clear();

        for (int i = 0; i < 4; i++)
        {
            this->_firstPlayerHand.push_back(this->_deck.getTopCard());
            this->_secondPlayerHand.push_back(this->_deck.getTopCard());
        }

        this->findADominium();

        for (int i = 0; i < 4; i++)
        {
            this->_data->assets.loadTexture(std::to_string(this->_firstPlayerHand.at(i).getCardName()), this->_firstPlayerHand.at(i).getFilePath());
            this->_FPHsprites.at(i).setTexture(this->_data->assets.getTexture(std::to_string(this->_firstPlayerHand.at(i).getCardName())));
            this->_FPHsprites.at(i).setScale(0.5, 0.5);
            this->_FPHsprites.at(i).setPosition((SCREEN_WIDTH / 2) - (this->_FPHsprites.at(i).getGlobalBounds().width * 2) + (this->_FPHsprites.at(i).getGlobalBounds().width * i) + (15 * i / i), (SCREEN_HEIGHT) - (this->_FPHsprites.at(i).getGlobalBounds().height));

            this->_data->assets.loadTexture(std::to_string(this->_secondPlayerHand.at(i).getCardName()), this->_secondPlayerHand.at(i).getFilePath());
            this->_SPHsprites.at(i).setTexture(this->_data->assets.getTexture(std::to_string(this->_secondPlayerHand.at(i).getCardName())));
            this->_SPHsprites.at(i).setScale(0.5, 0.5);
            this->_SPHsprites.at(i).setPosition((SCREEN_WIDTH / 2) - (this->_SPHsprites.at(i).getGlobalBounds().width * 2) + (this->_SPHsprites.at(i).getGlobalBounds().width * i) + (15 * i / i), (SCREEN_HEIGHT) - (this->_SPHsprites.at(i).getGlobalBounds().height));
        }
    }

    void GameState::init()
    {
        this->_data->assets.loadTexture("Card Back", CARD_BACK_SPRITE);
        this->_cardBack.setTexture(this->_data->assets.getTexture("Card Back"));
        this->_background.setTexture(this->_data->assets.getTexture("Background"));
        this->_cardBack.setScale(0.5, 0.5);
        this->_cardBack.setPosition((SCREEN_WIDTH / 2) + (this->_cardBack.getGlobalBounds().width / 1.3), (SCREEN_HEIGHT / 2) - (this->_cardBack.getGlobalBounds().height / 2));

        this->initialCardDraw();
    }

    void GameState::handleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if (this->_data->input.isKeyPressed(sf::Keyboard::Return, event, this->_data->window))
            {
                if (this->_deck.isEmpty())
                {
                    this->_deck.reInit();
                    this->_deck.shuffleDeck();
                    this->_deck.shuffleDeck();
                }
                this->initialCardDraw();
            }

            if (firstPlayerTurn)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (this->_data->input.isSpriteClicked(this->_FPHsprites.at(i), sf::Mouse::Left, this->_data->window))
                    {
                        this->playCard(i, this->_firstPlayerHand);
                    }
                }
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    if (this->_data->input.isSpriteClicked(this->_SPHsprites.at(i), sf::Mouse::Left, this->_data->window))
                    {
                        this->playCard(i, this->_secondPlayerHand);
                    }
                }
            }

            // this->setTop = true;
            // this->_topCard = this->_deck.getTopCard();
            // this->_data->assets.loadTexture(std::to_string(_topCard.getCardName()), _topCard.getFilePath());

            // if (this->_data->input.isKeyPressed(sf::Keyboard::Space, event, this->_data->window))
            // {
            //     std::cout << this->_topCard.getCardName() << std::endl;
            // }
        }
    }

    void GameState::update(float dt)
    {
        if (dt == 1)
        {
            std::cout << dt << std::endl;
        }
        //     if (this->setTop)
        //     {
        //         if (isCardADominium(this->_topCard.getCardName()))
        //         {
        //             this->_playedDominium.setTexture(this->_data->assets.getTexture(std::to_string(_topCard.getCardName())));
        //             this->_playedDominium.setPosition((SCREEN_WIDTH / 2) - (this->_playedDominium.getGlobalBounds().width * 1.8), (SCREEN_HEIGHT / 2) - (this->_playedDominium.getGlobalBounds().height / 2));
        //         }
        //         else
        //         {
        //             this->_playedCard.setTexture(this->_data->assets.getTexture(std::to_string(_topCard.getCardName())));
        //             this->_playedCard.setPosition((SCREEN_WIDTH / 2) - (this->_playedCard.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playedCard.getGlobalBounds().height / 2));
        //         }
        //     }
    }

    void GameState::draw(float dt)
    {
        if (dt == 1)
        {
            std::cout << dt << std::endl;
        }
        this->_data->window.clear();

        this->_data->window.draw(this->_background);
        if (!this->_deck.isEmpty())
        {
            this->_data->window.draw(this->_cardBack);
        }
        this->_data->window.draw(this->_playedDominium);
        if (firstPlayerTurn)
        {
            for (int i = 0; i < 4; i++)
            {
                this->_data->window.draw(this->_FPHsprites.at(i));
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                this->_data->window.draw(this->_SPHsprites.at(i));
            }
        }
        for (int i = 0; i < 2; i++)
        {
            this->_data->window.draw(this->_fieldSprites[i]);
        }

        this->_data->window.display();
    }
}