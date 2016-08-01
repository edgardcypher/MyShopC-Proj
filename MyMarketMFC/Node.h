#pragma once
#include <cstdlib>
#include<string>
#include<cctype>
#include<cstdlib>
#include<iostream>
using namespace std;
struct Item {
	string stockNum;
	int qtte;
	string descr;
	double eachPrice;

};/*myStock[] = {
	{ "A100", 20, "Hammer", 9.95 },
	{ "A250", 25, "Saw", 13.95 },
	{ "B400", 50, "Flat-Head Nails", 11.99 },
	{ "C888", 50, "Flat-Head Screwdriver", 6.59 },
	{ "A499", 75, "Pliers", 4.95 },
	{ "C667", 50, "Drill", 22.95 },
	{ "B875", 70, "Plumber's Wrench", 11.90 },
	{ "D547", 60, "Ladder 10 foot", 70.44 },
	{ "A910", 85, "Flashlight 10 inch", 9.99 },
	{ "B123", 90, "Assorted Buss Fuses", 4.99 }
};*/

struct MyItemNode {
	Item item;
	MyItemNode* nextInventItem=nullptr;
	MyItemNode* nextCustItem=nullptr;

};
