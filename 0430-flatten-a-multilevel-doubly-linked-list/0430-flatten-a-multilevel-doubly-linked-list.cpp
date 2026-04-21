class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node* curr = head;
        
        while(curr){
            if(curr->child){
                Node* next = curr->next;
                Node* child = curr->child;
                
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                
                Node* temp = child;
                while(temp->next) temp = temp->next;
                
                temp->next = next;
                if(next) next->prev = temp;
            }
            curr = curr->next;
        }
        
        return head;
    }
};