#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <__ASSERT.h>

using namespace std;

class Artwork { //declare Artist class
	string artist_name, title;
	unsigned int make_year;

public:
	// default constructor
	Artwork() {
		make_year = 0;
	}
	// parametric constructor
	Artwork(string new_artist, string new_title, unsigned int new_year) :
		artist_name(new_artist), title(new_title), make_year(new_year) {
	}

	bool operator==(const Artwork& target) {
		bool are_equal = true;
		are_equal = are_equal && (artist_name == target.artist_name);
		are_equal = are_equal && (title == target.title);
		are_equal = are_equal && (make_year == target.make_year);
		return are_equal;
	}
};

class SoldArtwork : public Artwork {
	string customer_name, customer_address;
	double sale_amount;

public:
	// default constructor
	SoldArtwork() {
		sale_amount = 0;
	}
	// parametric constructor
	SoldArtwork(string new_customer, string new_address, double new_amount, string new_artist, string new_title, unsigned int new_year)
		:Artwork(new_artist, new_title, new_year)
	{
		customer_name = new_customer, customer_address = new_address, sale_amount = new_amount;
	}

	bool operator==(const SoldArtwork& target) {
		bool are_equal = true;
		are_equal = are_equal && (customer_name == target.customer_name);
		are_equal = are_equal && (customer_address == target.customer_address);
		are_equal = are_equal && (sale_amount == target.sale_amount);
		return are_equal;
	}
};

class ArtCollection {
	vector<Artwork> artworks;
	vector<SoldArtwork> soldArtworks;

public:
	int getArtworksSize() {
		return artworks.size();
	}
	int getSoldArtworksSize() {
		return soldArtworks.size();
	}
	bool is_duplicate(Artwork& artwork_info) {
		int copy_count = 0;
		for (int index = 0; index < artworks.size(); ++index) {
			if (artworks[index] == artwork_info) {
				++copy_count;
			}
			return copy_count > 1;
		}
	}

	bool insert_artwork(Artwork& artwork_info) {
		int collectionSize = artworks.size();
		bool isDuplicate = false;
		for (int index = 0; index < collectionSize; ++index) {
			if (artwork_info == artworks[index]) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) {
			artworks.push_back(artwork_info);
		}
		return artworks.size() == collectionSize + 1;
	}

	bool sell_artwork(SoldArtwork & artwork_info) {
		bool artWorkExists = false;
		Artwork createdArtwork = static_cast<Artwork>(artwork_info);
		int collectionSize = artworks.size();
		for (int index = 0; index < collectionSize; ++index) {
			if (artworks[index] == createdArtwork) {
				artWorkExists = true;
				artworks.erase(artworks.begin() + index);
				break;
			}
		}
		if (artWorkExists) {
			soldArtworks.push_back(artwork_info);
			return true;
		}
		return false;
	}

	bool operator==(const ArtCollection& target) {
		bool are_equal = true;

		for (int index = 0; index < target.artworks.size(); ++index)
		{
			are_equal = static_cast<Artwork>(target.artworks[index]) == static_cast<Artwork>(artworks[index]);
			if (are_equal == false) {
				break;
			}
		}
		for (int index = 0; index < target.soldArtworks.size(); ++index)
		{
			are_equal = static_cast<SoldArtwork>(target.soldArtworks[index]) == static_cast<SoldArtwork>(soldArtworks[index]);
			if (are_equal == false) {
				break;
			}
		}
		return are_equal;
	}

	friend ArtCollection operator+(const ArtCollection &target1, const ArtCollection &target2);
};

ArtCollection operator+(const ArtCollection &target1, const ArtCollection &target2)
{
	ArtCollection newCollection = ArtCollection();
	newCollection.artworks = vector<Artwork>();
	newCollection.soldArtworks = vector<SoldArtwork>();
	//Target 1
	for (int index = 0; index < target1.artworks.size(); ++index)
	{
		bool isDuplicate = false;
		for (int k = 0; k < newCollection.artworks.size(); ++k)
		{
			if (static_cast<Artwork>(target1.artworks[index]) == newCollection.artworks[k])
			{
				isDuplicate = true;
			}
		}
		if (!isDuplicate) {
			newCollection.artworks.push_back(target1.artworks[index]);
		}
	}
	for (int index = 0; index < target1.soldArtworks.size(); ++index)
	{
		bool isDuplicate = false;
		for (int k = 0; k < newCollection.soldArtworks.size(); ++k)
		{
			if (static_cast<SoldArtwork>(target1.soldArtworks[index]) == newCollection.soldArtworks[k])
			{
				isDuplicate = true;
			}
		}
		if (!isDuplicate) {
			newCollection.soldArtworks.push_back(target1.soldArtworks[index]);
		}
	}
	//Target 2
	for (int index = 0; index < target2.artworks.size(); ++index)
	{
		bool isDuplicate = false;
		for (int k = 0; k < newCollection.artworks.size(); ++k)
		{
			if (static_cast<Artwork>(target2.artworks[index]) == newCollection.artworks[k])
			{
				isDuplicate = true;
			}
		}
		if (!isDuplicate) {
			newCollection.artworks.push_back(target2.artworks[index]);
		}
	}
	for (int index = 0; index < target2.soldArtworks.size(); ++index)
	{
		bool isDuplicate = false;
		for (int k = 0; k < newCollection.soldArtworks.size(); ++k)
		{
			if (static_cast<SoldArtwork>(target2.soldArtworks[index]) == newCollection.soldArtworks[k])
			{
				isDuplicate = true;
			}
		}
		if (!isDuplicate) {
			newCollection.soldArtworks.push_back(target2.soldArtworks[index]);
		}
	}
	return newCollection;
}

class TestArtworkCollection {
public:
	//Test insert artwork - check return type
	void test_insert_artwork() {
		Artwork artOne = Artwork("Vermeer", "Girl with the Pearl Earring", 1665);
		ArtCollection collection = ArtCollection();
		_ASSERT(collection.insert_artwork(artOne) == true);
		_ASSERT(collection.insert_artwork(artOne) == false);
	}

	//Test sell artwork - check return type
	void test_sell_artwork() {
		//Create artwork and sold artwork
		Artwork artTwo = Artwork("Whistler", "Whistler's Mother'", 1871);
		SoldArtwork artTwoSold = SoldArtwork("Mr. A", "Waterloo", 1000, "Whistler", "Whistler's Mother'", 1871);
		//Create non-existant art to sell
		SoldArtwork fakeArtSold = SoldArtwork("Mr. A", "Waterloo", 1000, "fakeArtist", "fake", 2019);
		//Create artwork collection
		ArtCollection collection = ArtCollection();
		collection.insert_artwork(artTwo);
		//Sell fake artwork - check that it is false
		_ASSERT(collection.sell_artwork(fakeArtSold) == false);
		//Sell artwork - check that it is true
		_ASSERT(collection.sell_artwork(artTwoSold) == true);
		//Try selling the same artwork again - should be false
		_ASSERT(collection.sell_artwork(artTwoSold) == false);

	}

	//Test the size of an Art Collection when inserting artwork
	void test_insert_artwork_collections() {
		//Create artwork
		Artwork artThree = Artwork("Klimt", "Woman in Gold", 1907);
		Artwork artFour = Artwork("Da Vinci", "Mona Lisa", 1503);
		Artwork artFive = Artwork("Botticelli", "Birth of Venus", 1484);
		//Create a new art collection
		ArtCollection collection = ArtCollection();
		//Insert artwork
		collection.insert_artwork(artThree);
		collection.insert_artwork(artFour);
		//Check the collection artwork vector size - should be two
		_ASSERT(collection.getArtworksSize() == 2);
		//Try inserting artwork that is already in the collection - duplicate
		collection.insert_artwork(artThree);
		//Check the collection artwork vector size - should still be two
		_ASSERT(collection.getArtworksSize() == 2);
		//Insert new piece of art
		collection.insert_artwork(artFive);
		//Check the collection artwork vector size - should be three now
		_ASSERT(collection.getArtworksSize() == 3);
		//Add duplicate values again
		collection.insert_artwork(artThree);
		collection.insert_artwork(artFour);
		collection.insert_artwork(artFive);
		//Check the collection artwork vector size - should still be three
		_ASSERT(collection.getArtworksSize() == 3);
	}

	//Test the size of an Art Collection when selling artwork
	void test_sell_artwork_collections() {
		//Create new artwork
		Artwork artSix = Artwork("Dali", "Persistence of Memory", 1931);
		Artwork artSeven = Artwork("Kandinsky", "Composition 8", 1923);
		Artwork artEight = Artwork("Renoir", "Moulin de la Galette", 1876);
		SoldArtwork artSixSold = SoldArtwork("Mr. B", "Calgary", 1000, "Dali", "Persistence of Memory", 1931);
		SoldArtwork artSevenSold = SoldArtwork("Mr. C", "Montreal", 3000, "Kandinsky", "Composition 8", 1923);
		SoldArtwork artEightSold = SoldArtwork("Mr. D", "Vancouver", 5000, "Renoir", "Moulin de la Galette", 1876);
		//Create a new Art Collection
		ArtCollection collection = ArtCollection();
		//Insert artwork
		collection.insert_artwork(artSix);
		collection.insert_artwork(artSeven);
		collection.insert_artwork(artEight);
		//Sell artwork
		collection.sell_artwork(artSixSold);
		collection.sell_artwork(artSevenSold);
		collection.sell_artwork(artEightSold);
		//Check the size of the soldArtwork vector - should be 3
		_ASSERT(collection.getSoldArtworksSize() == 3);
		//Try selling artwork that has already been sold - duplicate
		collection.sell_artwork(artSixSold);
		//Check the size of the soldArtwork vector - should still be 3
		_ASSERT(collection.getSoldArtworksSize() == 3);
		//Try selling artwork that does not exist
		SoldArtwork fakeArtSold = SoldArtwork("Mr. E", "Ottawa", 5000, "fake artist", "fake artwork", 2019);
		collection.sell_artwork(fakeArtSold);
		//Check the size of the soldArtwork vector - should still be 3
		_ASSERT(collection.getSoldArtworksSize() == 3);
	}

	//Test the + operator
	void test_plus_operator_overloading() {
		//Create two art collections
		ArtCollection collection1 = ArtCollection();
		ArtCollection collection2 = ArtCollection();
		//Create artwork
		Artwork artNine = Artwork("Van Gogh,", "Starry Night", 1889);
		Artwork artTen = Artwork("Munch", "The Scream", 1893);
		Artwork artTenCopy = Artwork("Munch", "The Scream", 1893);
		//Create sold artwork
		SoldArtwork artNineSold = SoldArtwork("Mr. F", "Hamilton", 5000, "Van Gogh,", "Starry Night", 1889);
		SoldArtwork artTenSold = SoldArtwork("Mr. G", "Toronto", 1000, "Munch", "The Scream", 1893);
		//Insert artwork into the art collections
		collection1.insert_artwork(artNine);
		collection2.insert_artwork(artTen);
		//Add both art collections together
		ArtCollection combined = collection1 + collection2;
		//Check the size of the artworks vector of the combined art collection - should be 2
		_ASSERT(combined.getArtworksSize() == 2);
		//Add a copy of artTen to collection1
		collection1.insert_artwork(artTenCopy);
		combined = collection1 + collection2;
		//Check the size of the artworks vector of the combined art collection - should still be 2
		_ASSERT(combined.getArtworksSize() == 2);
		//Sell artwork from collections
		collection1.sell_artwork(artNineSold);
		collection2.sell_artwork(artTenSold);
		combined = collection1 + collection2;
		//Check the size of the soldArtworks vector of the combined art collection - should be 2
		_ASSERT(combined.getSoldArtworksSize() == 2);
		//Check the size of the artworks vector of the combined art collection - should be 0
		_ASSERT(combined.getArtworksSize() == 1);
	}

	void run() {
		test_insert_artwork();
		test_sell_artwork();
		test_insert_artwork_collections();
		test_sell_artwork_collections();
		test_plus_operator_overloading();
	}
};

int main()
{
	TestArtworkCollection tests = TestArtworkCollection();
	tests.run();
}