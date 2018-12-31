#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct node {
    node* _prev;
    node* _next;
    unsigned long data;
};

class Marbles {
private:
    node* _curr = nullptr;

public:
    void ins(unsigned long data) {
        node* _node = new node;

        _node->data = data;
        if (_curr == nullptr) {
            _node->_prev = _node->_next = _node;
        } else {
            _node->_prev = _curr->_prev;
            _node->_next = _curr;
            _node->_prev->_next = _node->_next->_prev = _node;
        }
        _curr = _node;
    }

    unsigned long remove() {
        unsigned long data = _curr->data;

        _curr->_prev->_next = _curr->_next;
        _curr->_next->_prev = _curr->_prev;
        delete exchange(_curr, _curr->_next);

        return data;
    }

    void advance() {
        _curr = _curr->_next->_next;
    }

    void back() {
        int pos{7};
        while (pos--)
            _curr = _curr->_prev;
    }
};

unsigned long maxVal(int amountOfMarbles, int amountOfPlayers) {
    int currentPos{0}, currentPlayer{0};
    Marbles marbles;
    map<int, unsigned long> score;

    marbles.ins(0);
    for (unsigned long i = 1; i <= amountOfMarbles; i++) {
        currentPlayer = (currentPlayer % amountOfPlayers) + 1;
        if (i % 23) {
            marbles.advance();
            marbles.ins(i);
        } else {
            marbles.back();
            score[currentPlayer] += i + marbles.remove();
        }
    }

    auto some = max_element(score.begin(), score.end(),
                              [](const pair<int, int>& pair0, const pair<int, int>& pair1) {
                                  return pair0.second < pair1.second; });

    return some->second;
}

int main() {
    int Players{477};
    int Marbles{70851};

    cout << "Solution of part 1: " << maxVal(Marbles, Players) << endl;
    cout << "Solution of part 2: " << maxVal(Marbles * 100, Players) << endl;
}
