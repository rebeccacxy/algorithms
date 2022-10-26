/*
Insert Delete GetRandom O(1) - Duplicates NOT allowed

Implement the RandomizedSet class:
- RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
- bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
- int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

-----------------------------------------------------------------------
Decide on data structure. 

      insertion   removal    getRandom
LL      O(1)        O(N)
array   O(N)-mid    O(N)        O(1)

array: O(1) insert at end, but searching O(N). Need some additional data structure to locate array index for removal -> hashmap <index, value>

Time: O(1) getRandom. 
O(1) insert & delete, O(N) worst case when operation exceed capacity of current array / hashmap
Space: O(N)
*/

class RandomizedSet {
    private List<Integer> nums;
    private Map<Integer, Integer> numIndex;
    private Random random;  

    public RandomizedSet() {
        nums = new ArrayList<>();
        numIndex = new HashMap();
        random = new Random();
    }
    
    public boolean insert(int val) {
        if (numIndex.containsKey(val)) {
            return false;
        }
        numIndex.put(val, nums.size());
        nums.add(nums.size(), val);
        return true;
    }
    
    public boolean remove(int val) {
        if (!numIndex.containsKey(val)) {
            return false;
        }
        // move last element to place index of element to delete
        int lastElement = nums.remove(nums.size() - 1);
        int index = numIndex.remove(val);
        if (val != lastElement) {
            nums.set(index, lastElement);
            numIndex.put(lastElement, index);
        }
        return true;
    }
    
    public int getRandom() {
        return nums.get(random.nextInt(nums.size())); // gives a number from 0 to nums.size() - 1
    }
}




/*
Insert Delete GetRandom O(1) - Duplicates ALLOWED

RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also removing a random element.

Implement the RandomizedCollection class:
    RandomizedCollection() Initializes the empty RandomizedCollection object.
    bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
    bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
    int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of same values the multiset contains.

You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.

-----------------------------------------------------------------------
Decide on data structure. 

      insertion   removal    getRandom
LL      O(1)        O(N)
array   O(N)-mid    O(N)        O(1)

array: O(1) insert at end, but searching O(N). Need some additional data structure to locate array index for removal -> hashmap to map values to all indices with those values <value, set<indices>>

removal: switch with last element in array, then delete that last element

Time: O(N) total, each operation O(1)
Space: O(N)
*/

class RandomizedCollection {
    private List<Integer> nums;
    private Map<Integer, Set<Integer>> numIndex;
    private Random random;

    public RandomizedCollection() {
        nums = new ArrayList<>();
        numIndex = new HashMap();
        random = new Random();
    }
    
    public boolean insert(int val) {
        nums.add(val);
        if (!numIndex.containsKey(val)) {
            numIndex.put(val, new HashSet<>());
        }
        numIndex.get(val).add(nums.size() - 1); // keep record of index of newly inserted value
        return numIndex.get(val).size() == 1;
    }
    
    public boolean remove(int val) {
        // get index for val, then switch with last element in array, then delete last element from array
        if (!numIndex.containsKey(val) || numIndex.get(val).isEmpty()) {
            return false;
        }
        int removeIndex = numIndex.get(val).iterator().next();
        numIndex.get(val).remove(removeIndex);

        int lastNum = nums.get(nums.size() - 1);
        nums.set(removeIndex, lastNum); // update lastNum index, have alr removed last index for lastNum and need to add new index for it
        numIndex.get(lastNum).remove(nums.size() - 1); // remove then add, avoids misoperation about updating numIndex map (if add then remove, then will accidentally delete what we don't want to remove)
        if (removeIndex < nums.size() - 1) {
            numIndex.get(lastNum).add(removeIndex);
        }

        nums.remove(nums.size() - 1);
        return true;
    }
    
    public int getRandom() {
        return nums.get(random.nextInt(nums.size())); // gives a number from 0 to nums.size() - 1
    }
}











