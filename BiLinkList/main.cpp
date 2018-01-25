#include "BiLinkList.h"

int main() {

    /*NOTE: here, index begin with 1, not zero! so the task has been modified accordingly*/

    //----------------------BiLinkList 1----------------------------
    std::cout << "--------------------BiLinkList 1 begin-------------------" << std::endl;
    std::cout << "append data (1,2,3,4,5): " << std::endl;
    BiLinkList b1;
    for (int i = 1; i < 6; i++) {
        b1.append(i);
    }
    b1.show();
    std::cout << "get_forward_item(3,7)" << std::endl;
    BiLinkList out1;
    b1.get_forward_item(3, 7, out1);
    out1.show();
    std::cout << "--------------------BiLinkList 1   end-------------------" << std::endl << std::endl;


    //----------------------BiLinkList 2-----------------------------
    std::cout << "--------------------BiLinkList 2 begin-------------------" << std::endl;
    std::cout << std::endl << "append data (6,7,8,9): " << std::endl;
    BiLinkList b2;
    for (int i = 6; i < 10; i++) {
        b2.append(i);
    }
    b2.show();
    std::cout << std::endl << "get_backward_item(1,3): " << std::endl;
    BiLinkList out2;
    b2.get_backward_item(1, 3, out2);
    out2.show();

    std::cout << std::endl << "insert(1,3): " << std::endl;
    b2.insert(3, 3);
    b2.show();
    std::cout << "--------------------BiLinkList 2 end-------------------" << std::endl;

};