#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    Node *left;
    Node *right;
    char character;
    int value;
    Node(char c, int v, Node* l=nullptr, Node* r=nullptr){
        left = l;
        right = r;
        character = c;
        value = v;
    }
    ~Node(){
        delete right;
        delete left;
    }
    bool isLeaf(){
        return character != '\0';
    }
};

struct comparator{
    bool operator() (Node *a, Node *b){
        if(a->value != b->value)
            return a->value > b->value;
        if(!a->isLeaf() && b->isLeaf())
            return false;
        if(!b->isLeaf() && a->isLeaf())
            return true;
        if(a->isLeaf() && b->isLeaf())
            return a->character > b->character;
                return true;
    }
};

Node * createHuffmanTree(string line)
{
    map<char, int> counter;
    for(char c:line)
        counter[c] = (counter.find(c) == counter.end()) ? 1 : counter[c] + 1;

    priority_queue<Node*, vector<Node*>, comparator> nodes;

    for(auto entry : counter)
        nodes.push(new Node(entry.first, entry.second));

    Node *root;
    while(nodes.size() > 1)
    {
        Node *n1 = nodes.top();
        nodes.pop();
        Node *n2 = nodes.top();
        nodes.pop();
        if(n1->value == n2->value && !n1->isLeaf())
        {
            Node *pom = n1;
            n1 = n2;
            n2 = pom;
        }
        root = new Node('\0', n1->value + n2->value, n1, n2);
        nodes.push(root);
    }
    return root;
}

void encodeNodes(Node *node, string val, map<char, string> *map)
{
    if(node == nullptr) return;
    if(node->isLeaf())
    {
        cout<<node->character<<" : " + val<<endl;
        map->insert({node->character, val});
    }
    encodeNodes(node->left, val + '0', map);
    encodeNodes(node->right, val + '1', map);
}

string decode(Node *root, string encoded)
{
    string decoded = "";
    Node *currentNode = root;
    for(char c : encoded)
    {
        if(c == '0')
        {
            if(currentNode->left->isLeaf())
            {
                decoded += currentNode->left->character;
                currentNode = root;
            }
            else
                currentNode = currentNode->left;
        }
        else
        {
            if(currentNode->right->isLeaf())
            {
                decoded += currentNode->right->character;
                currentNode = root;
            }
            else
                currentNode = currentNode->right;
        }
    }
    return decoded;
}

int main()
{
    cout << "Kodowanie Huffmana. Podaj tekst, ktory chcesz zakodowac:" << endl;
    string line;
    getline(cin, line);

    Node *root = createHuffmanTree(line);

    cout<< "Oto tablica kodowania Huffmana:" << endl;
    map<char, string> encodedValues;
    encodeNodes(root, "", &encodedValues);


    string encodedLine = "";
    for(char c : line)
        encodedLine  += encodedValues[c];

    cout << "Oto twoj tekst po zakodowaniu: " << encodedLine << endl;

    cout << "Oto tekst po odkodowaniu: " << decode(root, encodedLine) << endl;

    delete root;
    return 0;
}
