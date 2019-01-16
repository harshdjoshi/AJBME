
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	SoldArtwork(string new_customer, string new_address, double new_amount) :
		customer_name(new_customer), customer_address(new_address), sale_amount(new_amount) {
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
	bool insert_artwork(Artwork& artwork_info) {
		for (int index = 0; index < artworks.size(); ++index) {
			if (artwork_info == artworks[index]) {
				break;
			}
		}
		artworks.push_back(artwork_info);
	}

	bool sell_artwork(SoldArtwork & artwork_info) {
		static_cast<Artwork>(artwork_info);
		for (int index = 0; index < artworks.size(); ++index) {
			if (artworks[index] == artwork_info) {
				artworks.erase(artworks.begin() + index);
				--index;
			}
		}
		soldArtworks.push_back(artwork_info);
	}

	bool operator==(const ArtCollection& target) {
		bool are_equal = true;
		for (int index = 0; index < target.artworks.size(); ++index)
		{
			are_equal = static_cast<Artwork>(target.artworks[index]) == static_cast<Artwork>(artworks[index]);
			if (are_equal==false) {
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
		/*
		for (artwork1 : this.artworks) {
			for (artwork2 : target.artworks) {
				if (artwork1 == artwork2) {

				}
			}
		}*/
		//are_equal = are_equal && (this. == target);
		return are_equal;
	}

	friend ArtCollection operator+(const ArtCollection & target) {

	}
};

int main()
{

}