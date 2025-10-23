#include <iostream>
#include <string>
using namespace std;

class CircularQueue{
	private:
	static const int MAX=5;
	string songs[MAX];
	int front, rear, count;
	public:
	CircularQueue(){
		front=0;
		rear=-1;
		count=0;
	}
	bool isEmpty(){ 
		return (count==0); 
	}
    bool isFull() { 
		return (count==MAX); 
	}
	void enqueue(string s){
		if (isFull()) {
            front = (front + 1) % MAX;
        } 
		else {
            count++;
        }
        rear = (rear + 1) % MAX;
        songs[rear] = s;

        cout << "Song added: " << s << endl;
	}
	string dequeue(){
		if (isEmpty()) {
            cout << "Playlist is empty!" << endl;
            return "";
        }
        string s = songs[front];
        front = (front + 1) % MAX;
        count--;

        cout << "Now playing: " << s << endl;
        display();

        return s;
	} 
	void display() {
        if (isEmpty()) {
            cout << "Playlist is empty!" << endl << endl;
            return;
        }
		cout << "Current Playlist:" << endl;
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX;
            cout << i + 1 << ". " << songs[index] << endl;
        }
        cout << endl;
    }
};

int main()
{
	CircularQueue c;
	c.enqueue("Despacito");
	c.enqueue("Dynamite");
	c.enqueue("Dreamers");
	c.enqueue("Demons");
	c.enqueue("DayLight");
	cout<<endl;
	c.display();
	c.enqueue("Fein");
	c.display();
	c.dequeue();
    c.dequeue();
	c.display();
	return 0;
}
