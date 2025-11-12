int main(){
	MinHeap h;
	h.removeMin();
	h.insert(7);
	h.printHeap();
	h.insert(3);
	h.printHeap();
	h.insert(10);
	h.printHeap();
	h.insert(2);
	h.printHeap();
	return 0;
}
