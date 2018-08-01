template<typename T>
class Node {
public:
	T e;
	Node<T> *next;

	public Node(T e, Node<T> *next) {
		this->e = e;
		this->next = next;
	}

	public Node(T e) {
		this->e = e;
		this->next = nullptr;
	}

	public Node() {
		this->next = nullptr;
	}
};
template<typename T>
class LinkedListQueue{

private:
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	LinkedListQueue() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}

	bool isEmpty() {
		return this->size == 0;
	}

	void enqueue(T e) {
		if (this->tail == null) {	
			tail = new Node(e);
			head = tail;
		}
		else {
			tail.next = new Node(e);
			tail = tail.next;
		}
		size++;
	}
	`
	@Override
		public E dequeue() {
		if (isEmpty())
			throw new IllegalArgumentException("Cannot dequeue from an empty queue.");

		Node retNode = head;
		head = head.next;
		retNode.next = null;
		if (head == null)
			tail = null;
		size--;
		return retNode.e;
	}

	@Override
		public E getFront() {
		if (isEmpty())
			throw new IllegalArgumentException("Queue is empty.");
		return head.e;
	}

	@Override
		public String toString() {
		StringBuilder res = new StringBuilder();
		res.append("Queue: front ");

		Node cur = head;
		while (cur != null) {
			res.append(cur + "->");
			cur = cur.next;
		}
		res.append("NULL tail");
		return res.toString();
	}

	public static void main(String[] args) {

		LinkedListQueue<Integer> queue = new LinkedListQueue<>();
		for (int i = 0; i < 10; i++) {
			queue.enqueue(i);
			System.out.println(queue);

			if (i % 3 == 2) {
				queue.dequeue();
				System.out.println(queue);
			}
		}
	}
}
