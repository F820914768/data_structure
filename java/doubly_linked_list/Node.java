public class Node<T> {
    T value;
    Node<T> next;
    Node<T> previous;

    public Node(){
        next = null; previous = null; value = null;
    }
    public Node(T value){
        next = null; previous = null;
        this.value = value;
    }
}