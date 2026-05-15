#include <iostream>

class Wallet
{
private:

	double balance;

public:
	Wallet(int start_balance)
	{
		balance = start_balance;
	}

	void checkBalance()
	{
		std::cout << "Current balance: $" << balance << std::endl;
	};

	friend class Bank;
};

class Bank
{

public:

	void withdrawMoney(Wallet& w, double wmoney)
	{
		w.balance -= wmoney; // Withdraw $50 from the wallet
		std::cout << "Withdrew $" << wmoney << " from the wallet." << std::endl;
	};

	void depositMoney(Wallet& d, double dmoney)
	{
		d.balance += dmoney; // Deposit $100 into the wallet
		std::cout << "Deposited $" << dmoney << " into the wallet." << std::endl;
	};
};

int main()
{
	Wallet myWallet(100); // Create a wallet with an initial balance of $100
	myWallet.checkBalance(); // Check the initial balance

	Bank myBank; // Create a bank object

	myBank.withdrawMoney(myWallet, 50); // Withdraw $50 from the wallet
	myWallet.checkBalance(); // Check the balance after withdrawal

	myBank.depositMoney(myWallet, 100); // Deposit $100 into the wallet
	myWallet.checkBalance(); // Check the balance after deposit

	return 0;
}