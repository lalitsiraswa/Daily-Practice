class Node {
    public Integer data;
    public Node next;

    public Node(Integer data) {
        this.data = data;
        next = null;
    }
}

// 1 -> 2 -> 3 -> 4 -> 5 -> null;
// 1 -> null
public class Assignment {
    public static void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static void reverseList(Node head) {
        Node temp = head;
        Node newHead = null;
        Node previous = null;
        while (temp != null) {
            Node next = temp.next;
            temp.next = previous;
            previous = temp;
            newHead = temp;
            temp = next;
        }
        printList(newHead);
    }

    public static void main(String args[]) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        printList(head);
        System.out.println("-------------------------");
        reverseList(head);
    }
}