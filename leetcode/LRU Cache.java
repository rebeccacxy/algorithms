/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

-----------------------------------------------------------------------
Edge case: If cache size > 0

Double LL --> tail is LRU key value.
HashMap<key, node> --> for get api, get corresponding node based on key of hashmap, then update LL. For put, put key and value into hashmap, update LL. 

Time: O(1) for put and get
Space: O(N)
*/

class LRUCache {

	private class Node {
		public int key;
		public int value;
		public Node prev;
		public Node next;
		public Node(int key, int value) {
			this.key = key;
			this.value = value;
		}
	}

	private Map<Integer, Node> map;
	private int capacity;
	private Node head;

    public LRUCache(int capacity) {
    	map = new HashMap<>();
    	this.capacity = capacity;
    	head = null;
    }

    private void detach(Node node) {
    	if (node.next == node) { // if only 1 node in LL
    		head = null;
    		return;
    	}
    	if (node == head) {
    		head = node.next; // reset head
    	}
    	node.prev.next = node.next;
    	node.next.prev = node.prev;
    }

    private void attach(Node node) { // add new node after head
    	if (head == null) {
    		node.next = node;
    		node.prev = node;
    		head = node;
    		return;
    	}
    	node.next = head;
    	node.prev = head.prev;
    	head.prev.next = node;
    	head.prev = node;
    	head = node;
    }
    
    public int get(int key) {
    	if (!map.containsKey(key)) {
    		return -1;
    	}
    	Node node = map.get(key);
    	detach(node);
    	attach(node);
    	return node.value;
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
        	Node node = map.get(key);
        	node.value = value;
        	detach(node);
        	attach(node);
        	return;
        } // otherwise don't have key value in hashmap, make new node
        Node node = new Node(key, value);
        map.put(key, node);
        attach(node);
        if (map.size() > capacity) {
        	Node removeNode = head.prev;
        	detach(removeNode); // tail node (LRU node)
        	map.remove(removeNode.key);
        }
    }
}















