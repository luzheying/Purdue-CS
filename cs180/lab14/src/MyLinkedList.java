/**
 * Representation of a linked list.
 *
 * <p>Lab -- Dynamic Data Structures</p>
 *
 * @author Logan Kulinski
 * @param <T> the type of the values of the linked list
 */
public final class MyLinkedList<T> {
    /**
     * The head entry of the linked list.
     */
    //TODO declare headEntry field
    private Entry<T> headEntry;
    /**
     * The size of the linked list.
     */
    //TODO declare size field
    private int size;
    /**
     * Constructs a newly allocated {@code MyLinkedList} object with an initial value of {@code null} for {@code headEntry}, and zero for {@code size}.
     */
    public MyLinkedList() {
        //TODO implement constructor
        this.headEntry = null;
        this.size = 0;
    } //MyLinkedList

    /**
     * Adds the specified value to the back of the linked list.
     *
     * @param value the value to be added to the back of the linked list
     */
    public void add(T value) {
     	//TODO implement add(T value) method
        if (this.headEntry == null) {
            this.headEntry = new Entry<>(value);
            size++;
            return;
        }
        Entry<T> temp;
        temp = this.headEntry;
        while(temp.getNextEntry() != null) {
            temp = temp.getNextEntry();
        }
        Entry<T> newEnd = new Entry<>(value);
        temp.setNextEntry(newEnd);
        size++;
    } //add

    /**
     * Adds the specified value to the front of the linked list.
     *
     * @param value the value to be added to the front of the linked list
     */
    public void addFront(T value) {
     	//TODO implement addFront(T value) method
        if (this.headEntry == null) {
            this.headEntry = new Entry<>(value);
            size++;
            return;
        }
        Entry<T> newHead = new Entry<>(value , this.headEntry);
        this.headEntry = newHead;
        size++;
    } //addFront

    /**
     * Gets the index of the first occurrence of the specified value in the linked list, or {@code -1} if it was not found.
     *
     * @param value the value to be searched for in the linked list
     * @return the index of the first occurrence of the specified value in the linked list, or {@code -1} if it was not found
     */
    public int indexOf(T value) {
       //TODO implement indexOf(T value) method
        if (headEntry == null) {
            return -1;
        }
        int count = 0;
        Entry<T> temp = this.headEntry;
        for (int i = 0; i < this.size; i++) {
            if(temp.getValue() == value) {
                return count;
            }
            temp = temp.getNextEntry();
            count++;
        }
       return -1;
    } //indexOf

    /**
     * Clears the linked list by setting {@code headEntry} equal to {@code null}, and {@code size} to zero.
     */
    public void clear() {
        //TODO implement clear() method
        this.headEntry = null;
        this.size = 0;
    } //clear

    /**
     * Gets the value at the specified index in the linked list.
     *
     * @param index the index of the value to retrieve in the linked list
     * @return the value at the specified index in the linked list
     * @throws IndexOutOfBoundsException if the argument is out of bounds {@code (index < 0 || index >= this.size)}
     */
    public T get(int index) throws IndexOutOfBoundsException {
        //TODO implement get(int index) method
        if ( index < 0 || index >= this.size) {
            throw new IndexOutOfBoundsException();
        }
        int count = 0;
        Entry<T> temp;
        temp = this.headEntry;
        while(true) {
            if(count == index) {
                break;
            }
            temp = temp.getNextEntry();
            count++;
        }
     	return temp.getValue();
    } //get

    /**
     * Determines whether or not the linked list is empty.
     *
     * @return whether or not the linked list is empty
     */
    public boolean isEmpty() {
     	//TODO implement isEmpty() method
        if (this.size == 0) {
            return true;
        }
     	return false;
    } //isEmpty

    /**
     * Gets the number of values in the linked list.
     *
     * @return the number of values in the linked list
     */
    public int size() {
     	//TODO implement size() method
     	return this.size;
    } //size

    /**
     * Gets a {@code String} representation of the linked list.
     *
     * <p>If a {@code MyLinkedList<Integer>} object holds the values {@code 1}, {@code 2}, and {@code 3}, {@code toString()} would return {@code "[1, 2, 3]"}.</p>
     *
     * @return a {@code String} representation of the linked list
     */
    @Override
    public String toString() {
     	//TODO implement toString() method
     StringBuilder outStr = new StringBuilder("[");
     Entry<T> currentEntry = this.headEntry;

     while (currentEntry!=null) {
         outStr.append(currentEntry.getValue());
         outStr.append(", ");
         currentEntry = currentEntry.getNextEntry();
     }

     if (outStr.length() > 1) {
         outStr.delete(outStr.length()-2 , outStr.length());
     }

     outStr.append("]");
     	return outStr.toString();
    } //toString
}