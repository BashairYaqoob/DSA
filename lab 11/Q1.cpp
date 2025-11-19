#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Node
{
public:
    string key;
    string value;
    Node *next;
};
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }
    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += key[i];
        }
        return sum % SIZE;
    }
    void insert(string key, string value)
    {
        int index = hashFunction(key);
        Node *n = new Node;
        n->key = key;
        n->value = value;
        n->next = NULL;
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            cout << endl;
        }
    }
};
int main()
{
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    return 0;
}
