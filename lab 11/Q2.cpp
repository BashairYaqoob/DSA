#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;

class Node
{
public:
	string key;
	string value;
	Node *next;
};
class ASCIIDictionary
{
private:
	Node *table[SIZE];

public:
	ASCIIDictionary()
	{
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
	void Add_Record(string key, string value)
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
	void Word_Search(string key)
	{
		int index = hashFunction(key);
		Node *temp = table[index];

		while (temp != NULL)
		{
			if (temp->key == key)
			{
				cout << "Found (" << temp->key << ", " << temp->value << ") at index " << index << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Error: '" << key << "' not found in dictionary." << endl;
	}
	void Print_Dictionary()
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
		}
	}
};
int main()
{
	ASCIIDictionary d;
	d.Add_Record("AB", "FASTNU");
	d.Add_Record("CD", "CS");
	d.Word_Search("AB");
	d.Word_Search("EF");
	d.Print_Dictionary();
	return 0;
}
