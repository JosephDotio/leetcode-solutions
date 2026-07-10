var addTwoNumbers = function (l1, l2) {

    // Create a dummy node
    let dummy = new ListNode(0);

    // 'current' will help us build the new linked list
    let current = dummy;

    // Initially, there is no carry
    let carry = 0;

    // Continue until both lists are finished and no carry remains
    while (l1 !== null || l2 !== null || carry !== 0) {

        // Get values from each list
        // If the list is finished, use 0
        let val1 = l1 ? l1.val : 0;
        let val2 = l2 ? l2.val : 0;

        // Add both values and the carry
        let sum = val1 + val2 + carry;

        // New carry
        carry = Math.floor(sum / 10);

        // Digit to store in current node
        let digit = sum % 10;

        // Create a new node
        current.next = new ListNode(digit);

        // Move current pointer
        current = current.next;

        // Move l1 pointer if possible
        if (l1) {
            l1 = l1.next;
        }

        // Move l2 pointer if possible
        if (l2) {
            l2 = l2.next;
        }
    }

    // Skip dummy node
    return dummy.next;
};