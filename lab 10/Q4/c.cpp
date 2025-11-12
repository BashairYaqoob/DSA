int main(){
	MinHeap h;
	
	h.insert(2);
	h.printHeap();
	h.insert(4);
	h.printHeap();
	h.insert(5);
	h.printHeap();
	h.insert(10);
	h.printHeap();
	h.insert(8);
	h.printHeap();
	h.insert(6);
	h.printHeap();
	h.insert(9);
	h.printHeap();
	h.removeMin();
	h.printHeap();
	return 0;
}
