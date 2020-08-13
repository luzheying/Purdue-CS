/**
 * Representation of an entry in a linked list.
 *
 * <p>Lab -- Dynamic Data Structures</p>
 *
 * @author Logan Kulinski
 * @param <T> the type of the value of the entry
 */
public final class Entry<T> {
    /**
     * The value of the entry.
     */
    private T value;

    /**
     * The next entry of the entry.
     */
    private Entry<T> nextEntry;

    /**
     * Constructs a newly allocated {@code Entry} object.
     *
     * @param value the value of the entry
     * @param nextEntry the next entry of the entry
     */
    public Entry(T value, Entry<T> nextEntry) {
        this.value = value;
        this.nextEntry = nextEntry;
    } //Entry

    /**
     * Constructs a newly allocated {@code Entry} object with an initial value of {@code null} for {@code nextEntry}.
     *
     * @param value the value of the entry
     */
    public Entry(T value) {
        this(value, null);
    } //Entry

    /**
     * Constructs a newly allocated {@code Entry} object with initial values of {@code null} for {@code value} and {@code nextEntry}.
     */
    public Entry() {
        this(null);
    } //Entry

    /**
     * Gets the value of the entry.
     *
     * @return the value of the entry
     */
    public T getValue() {
        return this.value;
    } //getValue

    /**
     * Gets the next entry of the entry.
     *
     * @return the next entry of the entry
     */
    public Entry<T> getNextEntry() {
        return this.nextEntry;
    } //getNextEntry

    /**
     * Sets the value of the entry.
     *
     * @param value the value of the entry
     */
    public void setValue(T value) {
        this.value = value;
    } //setValue

    /**
     * Sets the next entry of the entry.
     *
     * @param nextEntry the next entry of the entry
     */
    public void setNextEntry(Entry<T> nextEntry) {
        this.nextEntry = nextEntry;
    } //setNextEntry

    @Override
    public int hashCode() {
        int result = 23;

        result = 19 * result + (this.value == null ? 0 : this.value.hashCode());

        result = 19 * result + (this.nextEntry == null ? 0 : this.nextEntry.hashCode());

        return result;
    } //hashCode

    @Override
    public boolean equals(Object o) {
        return o instanceof Entry && (this.value == null ? ((Entry) o).value == null : this.value.equals(((Entry) o).value)) && (this.nextEntry == null ? ((Entry) o).nextEntry == null : this.nextEntry.equals(((Entry) o).nextEntry));
    } //equals

    @Override
    public String toString() {
        return String.format("Entry[%s]", this.value);
    } //toString
}