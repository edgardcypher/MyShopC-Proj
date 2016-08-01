#include"NodeHead.h"
bool MyStore::checkStoreItems(string sNum, MyItemNode *prcNode, int &qt) {
	if (!prcNode)return false;

	else {
		while (prcNode) {
			if ((prcNode->item.stockNum == sNum))
				break;
			prcNode = prcNode->nextInventItem;

		}
		if (prcNode == nullptr) {
			cout << "\n we don't have that item in stock";
			return false;

		}
		if (prcNode) {
			if (prcNode->item.qtte == 0) {
				cout << "\nSORRY WE ARE OUT OF STOCK FOR THIS ITEM";
				return false;
			}
			if (prcNode->item.qtte <= qt) {
				cout << "\nquantity in stock is not enough for your order";
				return false;
			}
			prcNode->item.qtte -= qt;
			return true;
		}

	}
}

bool MyStore::checkCartItem(string idItem) {
	MyItemNode* prNode = headCart;
	MyItemNode* tpNode;
	if (!headCart)return false;
	if (headCart->item.stockNum == idItem) {
		tpNode = headCart->nextCustItem;
		this->backItem(tpNode);
		delete headCart;
		headCart = tpNode;
		return true;
	}
	else {
		MyItemNode* pviewNode=nullptr;
		while (prNode) {
			if (prNode->item.stockNum == idItem)
				break;
			pviewNode = prNode;
			prNode = prNode->nextCustItem;
		}
		if (prNode) {
			pviewNode->nextCustItem = prNode->nextCustItem;
			this->backItem(prNode);
			delete prNode;
			return true;
		}
	}
	return false;
}

void MyStore::backItem(MyItemNode* itmCart) {
	MyItemNode* itmInv;
	itmInv = headInventory;
	if (itmInv->item.stockNum == itmCart->item.stockNum)
		itmInv->item.qtte += itmCart->item.qtte;
	else {
		while (itmInv) {
			if (itmInv->item.stockNum == itmCart->item.stockNum)
				itmInv->item.qtte += itmCart->item.qtte;
			itmInv = itmInv->nextInventItem;
		}
	}

}

void MyStore::listInventory(MyItemNode* nStock) {
	MyItemNode* stock;
	for (int i = 0; i < 10; i++) {
		nStock = new MyItemNode;
		nStock->item = myStock[i];
		nStock->nextInventItem = nullptr;
		nStock->nextCustItem = nullptr;
		if (!headInventory) {
			headInventory = nStock;
		}
		else {
			stock = headInventory;
			while (stock->nextInventItem)
				stock = stock->nextInventItem;
			stock->nextInventItem = nStock;
		}
		delete nStock;
	}
}

void MyStore::viewInventory() {
	MyItemNode* stock;
	stock = headInventory;
	cout << "\n-------------View Inventory-------------------" << endl;
	if (!stock)
		cout << "Store is empty" << endl;
	else {
		while (stock) {
			cout << stock->item.stockNum << "-----" << stock->item.qtte << "----" << stock->item.descr << "-----" << stock->item.eachPrice << endl;
			stock = stock->nextInventItem;
		}
	}
}

void MyStore::viewCart() {
	MyItemNode* myItems;
	myItems = headCart;
	cout << "-------------View Cart-----------------" << endl;
	if (!myItems) {
		cout << "\ncart is empty";
	}
	else {
		while (myItems) {
			this->custExtension = myItems->item.qtte * myItems->item.eachPrice;
			cout << myItems->item.stockNum << "-----" << myItems->item.qtte << "----" << myItems->item.descr << "-----" << myItems->item.eachPrice << "---" << this->custExtension << endl;
			myItems = myItems->nextCustItem;
		}


	}
}

void MyStore::checkOut() {
	string allname;
	string address;
	double priceTotal = 0.0;
	cin.ignore();
	cout << "Please enter your full name:";
	getline(cin, allname);
	cout << "enter you full address:";
	getline(cin, address);
	MyItemNode* myItems;
	myItems = headCart;
	system("clear");
	cout << "-------------Check out-----------------" << endl;
	cout << "\nName: " << allname;
	cout << "\naddress:" << address << endl;
	if (!myItems) {
		cout << "\ncart is empty";
	}
	else {
		while (myItems) {
			this->custExtension = myItems->item.qtte * myItems->item.eachPrice;
			priceTotal += this->custExtension;
			cout << myItems->item.stockNum << "-----" << myItems->item.qtte << "----" << myItems->item.descr << "-----" << myItems->item.eachPrice << "---" << this->custExtension << endl;
			myItems = myItems->nextCustItem;
		}
		cout << "-----------------------------------------------------";
		this->custTotal = priceTotal + (priceTotal*0.0625) + 9.95;
	}
	cout << "\nShipping: 9.95";
	cout << "\nsales Tax:" << priceTotal*0.0625;
	cout << "\nTotal:" << this->custTotal;
}

void MyStore::addCart() {
	char ans;
	do {
		MyItemNode *custNode, *parNode;
		Item custItems;
		cout << "Stock number:";
		cin >> custItems.stockNum;
		cout << "\nQuantity:";
		cin >> custItems.qtte;
		cout << "\nDescription:";
		cin >> custItems.descr;
		cout << "\n price Per each:";
		cin >> custItems.eachPrice;
		custNode = new MyItemNode;
		custNode->item = custItems;
		custNode->nextInventItem = nullptr;
		custNode->nextCustItem = nullptr;
		if (checkStoreItems(custItems.stockNum, headInventory, custItems.qtte)) {
			if (!headCart) {
				headCart = custNode;
				cout << "Items added to the cart" << endl;
			}
			else {
				parNode = headCart;
				while (parNode->nextCustItem)
					parNode = parNode->nextCustItem;
				parNode->nextCustItem = custNode;
				cout << "Items added to the cart" << endl;
			}
		}
		cout << "\nKeep shopping(Y/N)?:";
		cin >> ans;

	} while (toupper(ans) != 'N');
}

MyStore::MyStore() {
	headCart = nullptr;
	headInventory = nullptr;
	custExtension = 0.0;
	custTotal = 0.0;
}

void MyStore::removeItem() {
	string stNum;
	cout << "please enter Stock number of item you want to remove:";
	cin >> stNum;
	if (checkCartItem(stNum))
		cout << "it is there\n";
	else
		cout << "it is not there\n";
}

int main(int argc, char** argv) {
	MyStore shop;
	MyItemNode* myNode;
	myNode = new MyItemNode();
	shop.listInventory(myNode);
	shop.addCart();
	shop.viewCart();
	shop.checkOut();
	//return 0;
    shop.removeItem();
	 shop.viewCart();
	 shop.viewInventory();
	 return 0;
}