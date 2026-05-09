#include <iostream>
#include "PlayerNode.h"
using namespace std;

class CircularPlayerList
{
private:
    PlayerNode *head;
    PlayerNode *tail;
    PlayerNode *current;
    int playerCount;

public:
    CircularPlayerList()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        playerCount = 0;
    }

    // 1. Add a new player
    void addPlayer(int id, int score)
    {
        PlayerNode *newPlayer = new PlayerNode(id, score);

        if (head == NULL)
        {
            head = newPlayer;
            tail = newPlayer;
            current = newPlayer;
            tail->next = head;
        }
        else
        {
            tail->next = newPlayer;
            tail = newPlayer;
            tail->next = head;
        }

        playerCount++;
        cout << "Player added successfully.\n";
    }

    // 2. Remove a player if they quit
    void removePlayer(int id)
    {
        if (head == NULL)
        {
            cout << "No players in the game.\n";
            return;
        }

        PlayerNode *temp = head;
        PlayerNode *prev = tail;

        do
        {
            if (temp->playerID == id)
            {
                // Case 1: only one player
                if (head == tail)
                {
                    cout << "Player " << temp->playerID << " removed.\n";
                    delete temp;

                    head = NULL;
                    tail = NULL;
                    current = NULL;
                    playerCount = 0;
                    return;
                }

                // If removing head
                if (temp == head)
                {
                    head = head->next;
                    tail->next = head;
                }

                // If removing tail
                else if (temp == tail)
                {
                    tail = prev;
                    tail->next = head;
                }

                // If removing middle/current node
                else
                {
                    prev->next = temp->next;
                }

                // If current player quits, move turn to next player
                if (current == temp)
                {
                    current = temp->next;
                }

                cout << "Player " << temp->playerID << " removed.\n";

                delete temp;
                playerCount--;

                checkWinner();
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "Player not found.\n";
    }

    // 3. Move to next player's turn
    void nextTurn()
    {
        if (current == NULL)
        {
            cout << "No players available.\n";
            return;
        }

        cout << "Current Player: " << current->playerID << endl;

        current = current->next;

        cout << "Next turn goes to Player: " << current->playerID << endl;
    }

    // 4. Skip a player
    void skipPlayer()
    {
        if (current == NULL)
        {
            cout << "No players available.\n";
            return;
        }

        if (playerCount == 1)
        {
            cout << "Only one player left. Cannot skip.\n";
            return;
        }

        cout << "Player " << current->playerID << " is skipped.\n";

        current = current->next;

        cout << "Turn goes to Player: " << current->playerID << endl;
    }

    // 5. End game when only one player remains
    void checkWinner()
    {
        if (playerCount == 1 && head != NULL)
        {
            cout << "\nGame Over!\n";
            cout << "Winner is Player " << head->playerID << endl;
            cout << "Final Score: " << head->score << endl;
        }
    }

    void displayPlayers()
    {
        if (head == NULL)
        {
            cout << "No players to display.\n";
            return;
        }

        PlayerNode *temp = head;

        cout << "\n----- Players in Game -----\n";

        do
        {
            cout << "Player ID: " << temp->playerID << endl;
            cout << "Score: " << temp->score << endl;
            cout << "---------------------------\n";

            temp = temp->next;

        } while (temp != head);
    }
};
