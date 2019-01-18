#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <_ASSERT.h>

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
	//Test return type of insert
	void test_insert_artwork() {
		Artwork akArt = Artwork("ak_j", "romance_with_bme", 2017);
		ArtCollection collection = ArtCollection();
		_ASSERT(collection.insert_artwork(akArt) == true);
		_ASSERT(collection.insert_artwork(akArt) == false);
	}

	//Test return type for sell
	void test_sell_artwork() {
		SoldArtwork akArtSold = SoldArtwork("Monet", "Waterloo-A", 1000, "ak_j", "romance_with_bme", 2017);
		SoldArtwork akFakeArtSold = SoldArtwork("Monet", "Waterloo-A", 5000, "fakeArtist", "mybme", 2017);
		Artwork akArt = Artwork("ak_j", "romance_with_bme", 2017);
		ArtCollection collection = ArtCollection();
		//create artwork collection
		collection.insert_artwork(akArt);
		//sell fake art
		_ASSERT(collection.sell_artwork(akFakeArtSold) == false);
		//sell artwork
		_ASSERT(collection.sell_artwork(akArtSold) == true);
		_ASSERT(collection.sell_artwork(akArtSold) == false);

	}

	//Test collection size
	void test_insert_artwork_collections() {
		Artwork akArt = Artwork("ak_j", "romance_with_bme", 2017);
		Artwork ajArt = Artwork("ak_jo", "romance_with_engineering", 2018);
		Artwork ajoArt = Artwork("ak_jo", "romance_with_programming", 2019);
		ArtCollection collection = ArtCollection();
		collection.insert_artwork(akArt);
		collection.insert_artwork(ajArt);
		_ASSERT(collection.getArtworksSize() == 2);
		collection.insert_artwork(akArt);
		_ASSERT(collection.getArtworksSize() == 2);
		collection.insert_artwork(ajoArt);
		_ASSERT(collection.getArtworksSize() == 3);
		collection.insert_artwork(ajoArt);
		collection.insert_artwork(ajoArt);
		collection.insert_artwork(ajoArt);
		_ASSERT(collection.getArtworksSize() == 3);
	}

	//Test collection size for sold artwork
	void test_sell_artwork_collections() {
		SoldArtwork akArtSold = SoldArtwork("Monet", "Waterloo-A", 1000, "ak_j", "romance_with_bme", 2017);
		SoldArtwork ajArtSold = SoldArtwork("Picasso", "Waterloo-B", 3000, "ak_jo", "romance_with_engineering", 2018);
		SoldArtwork ajoArtSold = SoldArtwork("DaVinci", "Waterloo-C", 5000, "ak_jo", "romance_with_programming", 2019);
		Artwork akArt = Artwork("ak_j", "romance_with_bme", 2017);
		Artwork ajArt = Artwork("ak_jo", "romance_with_engineering", 2018);
		Artwork ajoArt = Artwork("ak_jo", "romance_with_programming", 2019);
		ArtCollection collection = ArtCollection();

		//create artwork collection
		collection.insert_artwork(akArt);
		collection.insert_artwork(ajArt);
		collection.insert_artwork(ajoArt);

		//sell artwork
		collection.sell_artwork(ajoArtSold);
		collection.sell_artwork(akArtSold);
		collection.sell_artwork(ajArtSold);
		_ASSERT(collection.getSoldArtworksSize() == 3);
		//try selling artwork that does not exist
		SoldArtwork ajoFakeArtSold = SoldArtwork("DaVinci", "Waterloo-C", 5000, "ak_jo", "no_romance_with_programming", 2016);
		collection.sell_artwork(ajoFakeArtSold);
		_ASSERT(collection.getSoldArtworksSize() == 3);
	}

	void test_plus_operator_overloading() {
		//Add two art collections using + operator
		ArtCollection collection2 = ArtCollection();
		ArtCollection collection1 = ArtCollection();
		Artwork art1 = Artwork("Van Gogh,", "Starry Night", 1889);
		Artwork ajArtCopy = Artwork("ak_jo", "romance_with_engineering", 2018);
		Artwork ajArt = Artwork("ak_jo", "romance_with_engineering", 2018);
		SoldArtwork art1Sold = SoldArtwork("Monet", "Waterloo-C", 5000, "Van Gogh,", "Starry Night", 1889);
		SoldArtwork akArtSold = SoldArtwork("Monet", "Waterloo-A", 1000, "ak_j", "romance_with_bme", 2017);
		SoldArtwork ajArtSold = SoldArtwork("Picasso", "Waterloo-B", 3000, "ak_jo", "romance_with_engineering", 2018);
		SoldArtwork ajoArtSold = SoldArtwork("DaVinci", "Waterloo-C", 5000, "ak_jo", "romance_with_programming", 2019);
		collection2.insert_artwork(art1);
		collection1.insert_artwork(ajArt);
		ArtCollection bigCollection = collection2 + collection1;
		_ASSERT(bigCollection.getArtworksSize() == 2);
		collection2.insert_artwork(ajArtCopy);
		bigCollection = collection2 + collection1;
		_ASSERT(bigCollection.getArtworksSize() == 2);

		collection2.sell_artwork(ajArtSold);
		collection1.sell_artwork(ajArtSold);
		_ASSERT(bigCollection.getSoldArtworksSize() == 1);
		_ASSERT(bigCollection.getArtworksSize() == 1);
		collection2.sell_artwork(art1Sold);
		_ASSERT(bigCollection.getSoldArtworksSize() == 2);
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