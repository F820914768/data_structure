import java.lang.Iterable;
import java.util.Iterator;


class DoublyLinkedList<T> implements Iterable<T>{
    Node<T> front;
    Node<T> end;

    public static void main(String[] args){
        DoublyLinkedList<Integer> list = new DoublyLinkedList<>();
        list.push_back(3);
        list.push_back(7);
        list.push_back(12);
        list.add_front(10);

        System.out.println(list);

        for(int num : list){
            System.out.println(num);
        }
    }

    public class LinkedListIterator implements Iterator<T>{
        private Node<T> current;
        
        @Override
        public boolean hasNext(){
            if (current.next.value == null){
                return false;
            }
            return true;
        }
        
        @Override
        public T next(){
            T value = current.value;
            current = current.next;
            return value;
        } 

        public LinkedListIterator(){
            current = front;
        }

    }

    @Override
    public Iterator<T> iterator(){
        return new LinkedListIterator();
    }

    private void insertNode(Node<T> node1, Node<T> node2, Node<T> nodeInsert){
        node1.next = nodeInsert;
        nodeInsert.previous = node1;
        node2.previous = nodeInsert;
        nodeInsert.next = node2;
    }

    public DoublyLinkedList(){
        front = new Node<T>();
        end = new Node<T>();
        front.next = end;
        front.previous = end;
        end.next = front;
        end.previous = front;
    }

    public void push_back(T value){
        Node<T> newNode = new Node<T>(value);
        Node<T> temp = end.previous;
        insertNode(temp, end, newNode);
    }

    public void add_front(T value){
        Node<T> newNode = new Node<T>(value);
        Node<T> temp = front.next;
        insertNode(front, temp, newNode);       
    }

    public T at(int i){
        Node<T> current = front;
        for (int j = 0; j <= i; j++){
            current = current.next;
            if (current.value == null){
                return null;
            }
        }
        return current.value;
    }

    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();
        Node<T> current = front.next;
        while (current.value != null){
            stringBuilder.append(String.valueOf(current.value));
            stringBuilder.append(" ");
            current = current.next;
        }

        return stringBuilder.toString();
    }

}