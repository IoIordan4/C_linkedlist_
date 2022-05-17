class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self, head=None):
        self.head = head
        self.Success = 0
        self.Fail = -1

    def display(self):
        length = 0
        if self.head is None:
            print('Size of linked list is: ', length)
            return self.Fail
        current_node = self.head
        while current_node is not None:
            print('Node data = ', current_node.data)
            current_node = current_node.next
            length += 1
        print('Size of linked list is: ', length)

        return self.Success

    def sorted_link_insert(self, data):
        data = data.lower()
        # Check if data is NULL or data not having only letters
        if data is None or data.isalpha() is False:
            return self.Fail
        # Case head = Null; Make new node as head
        if self.head is None:
            new_node = Node(data)
            self.head = new_node
            #del new_node
            return self.Success
        # Case data is < head data; Make new node as head
        if data < self.head.data:
            new_head = Node(data)
            new_head.next = self.head
            self.head = new_head
            return self.Success

        current_node = self.head
        # Case data > current_node data; Search for current_node data <= data
        while current_node.next is not None and current_node.next.data <= data:
            current_node = current_node.next
        # Make new_node point to current_node next node and current node point to new node
        new_node = Node(data)
        new_node.next = current_node.next
        current_node.next = new_node

        return self.Success

    def sorted_link_remove(self, data):
        data = data.lower()
        # Check if head is not Null or data not having only letters
        if self.head is None or data.isalpha() is False:
            return self.Fail
        prev = None
        curr = self.head
        # While current node is not Null
        while curr:
            # Check if current node data is equal to data
            if curr.data == data:
                # Check if previous node is not null
                if prev:
                    # Make previous node point to what current node points to
                    prev.next = curr.next
                else:
                    # Delete head node by Make head equal to current next
                    self.head = curr.next
                del curr
                return self.Success
            # Make previous node equal to current and current equal to next node
            prev = curr
            curr = curr.next

        return self.Fail


if __name__ == '__main__':

    myList = LinkedList()

    myList.sorted_link_insert("Iordan")
    myList.sorted_link_insert("MicHElangelo")
    myList.sorted_link_insert("zeus")
    myList.sorted_link_insert("antique")
    myList.sorted_link_insert("abc1")
    myList.sorted_link_insert("#")
    myList.display()
    myList.sorted_link_remove("Iordan")
    myList.sorted_link_remove("zeus")
    myList.sorted_link_remove("antique")
    myList.sorted_link_remove("MicHElangelo")
    myList.sorted_link_remove("abc1")
    myList.display()