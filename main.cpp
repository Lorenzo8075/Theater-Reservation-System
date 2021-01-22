#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Movie{
  private: 
    string movie_name;
    int seats_available;
    double ticket_price;

  public:
    static const string default_movie;
    static const int default_seats;
    static const double default_t_price;

    //Default Constructor
    Movie();
    //3 args constructor
    Movie(string movie_name,int seats_available,double ticket_price);
    //Destructor
    ~Movie();
    string get_movie_name()const;
    void set_name(string movie_name);
    int get_seats( )const;
    void set_seats(int seats_available);
    int get_price() const;
    void set_price(double ticket_price);
    int PurchaseTicket(int tickets_requested);
    void Display();

};

const string Movie::default_movie = "Mystery Movie";
const int Movie::default_seats = 100;
const double Movie::default_t_price = 11.99;


class MovieTicketMaster{
private:
  string theater_name;
  string theater_location;
  int movie_count;
  static const int movie_list_size = 32;
  Movie movie_list[movie_list_size];
  void ViewMovies();
  Movie* FindMovie(string movie_name);
  Movie* SearchMovie();
  void PurchaseTicket();

public: 
  static const int array_size = 32;
  static const int default_movie_count;
  static const string default_theater_name;
  static const string default_theater_location;

  //default constructor
  MovieTicketMaster();
  //non-default constructor
  MovieTicketMaster(string m_theater_name, string m_theater_location, int m_movie_count);
  //public destructor
  ~MovieTicketMaster();

  string get_theater_name()const;
  void set_theater_name(string theater_name);
  string get_location( )const;
  void set_location(int theater_location);
  int get_movie_count() const;
  void set_movie_count(int movie_count);
//   void init(Movie* p_movie_list,int kSize);
  void init();
  void run();

  //viewmovies function: use local pointer to traver the array of movie objects and invoke display_movie_info
  //searchmovie function: ask user to input movie name and then invoke the findmovie function
  //findmovie function: take a string moviename. Then search though the array (using moving pointer
  //    to access the array using linear search). If a movie is found return the pointer to the found 
  //    movie object. OTHERWISE return a nullpointer
  //purchaseticket function: ask user to input movie name and invoke findmovie to verify movie exist.
  //    if found, ask user for the # of tickets. Then use the returned pointer by findmovie to invoke purchase ticket
  //    function for the found Movie object. if Purchase ticket function return -1, display sold out. Otherwise
  //    sahow total cost
};

const int MovieTicketMaster::default_movie_count = 0;
const string MovieTicketMaster::default_theater_name = "AMC";
const string MovieTicketMaster::default_theater_location = "Seattle";

int main() {
  
  MovieTicketMaster* object_a = nullptr;
  object_a = new MovieTicketMaster("AMC", "Seattle",8);

  object_a->init();
  object_a->run();

 
  
  delete object_a;
 
  return 0;
  }

  //Default Constructor
  Movie::Movie(): movie_name(Movie::default_movie), seats_available(Movie::default_seats), 
    ticket_price(Movie::default_t_price){}

  //3 args constructor
  Movie::Movie(string movie_name,int seats_available,double ticket_price):
    movie_name(movie_name), seats_available(seats_available),ticket_price(ticket_price){}

  //Destructor
  Movie::~Movie(){ cout << "Movie " << movie_name << " object is not longer showing"; }

  string Movie:: get_movie_name()const{ return movie_name; }

  void Movie::set_name(string movie_name){ this->movie_name = movie_name; }

  int Movie::get_seats( )const{ return seats_available; }

  void Movie::set_seats(int seats_available){ this->seats_available = seats_available; }

  int Movie::get_price() const {return ticket_price;}

  void Movie::set_price(double ticket_price){this->ticket_price = ticket_price;}

  int Movie::PurchaseTicket(int tickets_requested){
    int* p_seats_available = nullptr;
    p_seats_available = &seats_available;
      
    if(tickets_requested > seats_available){
      return -1;
    }
    else {

      double tot_cost = static_cast<double>(tickets_requested) * ticket_price;
      *p_seats_available = seats_available - tickets_requested;
      return tot_cost;
    }
  }

  void Movie::Display(){
      
    cout << "Movie name: " << movie_name << endl;
    cout << "Number of seats available: : " << seats_available << endl;
    cout << "Ticket price: $" << setprecision(2) << fixed << ticket_price << endl << endl;   
    }

  //MovieTicketMaster

  //default constructor
  MovieTicketMaster::MovieTicketMaster():
    theater_name(MovieTicketMaster::default_theater_name),theater_location(MovieTicketMaster::default_theater_location),
    movie_count(MovieTicketMaster::default_movie_count){}

  //non-default constructor
  MovieTicketMaster::MovieTicketMaster(string theater_name, string theater_location, int movie_count):
    theater_name(theater_name), theater_location(theater_location), movie_count(movie_count) {}

  //public destructor
  MovieTicketMaster::~MovieTicketMaster(){ cout << "Theater " << theater_name << " at " << theater_location << " is currently closed.";}

  string MovieTicketMaster::get_theater_name()const{ return theater_name;}

  void MovieTicketMaster::set_theater_name(string theater_name){ this->theater_name = theater_name;}

  string MovieTicketMaster::get_location()const{ return theater_location;}

  void MovieTicketMaster::set_location(int theater_location){ this->theater_location = theater_location;}

  int MovieTicketMaster::get_movie_count() const {return movie_count;}

  void MovieTicketMaster::set_movie_count(int movie_count){ this->movie_count = movie_count;}


    //initialize 3 local arrays
  void MovieTicketMaster::init(){
        
    const int kSize = 8;
    string movie_names[kSize] = {"Harry Potter 1","Harry Potter 2", 
    "Harry Potter 3", "Harry Potter 4", "Harry Potter 5", 
    "Harry Potter 6", "Harry Potter 7", "Harry Potter 8" };

    int seats_number[kSize] = {1000, 250, 500, 750, 1250, 1500, 1750, 2000};

    double movie_prices[kSize] = {5.00,7.00,10.00,12.00,15.00,17.00,20.00,50.00};

    Movie* p_movie_list = nullptr;
    p_movie_list = movie_list; // set p_movie to point to the 1st element in the Movie array

    //Local Pointer
    string* p_movie_names = nullptr; 
    p_movie_names = movie_names; // also  p_movie_name_list =  &movie_name[0]

    int* p_seats_number = nullptr;
    p_seats_number = seats_number;

    double* p_movie_prices = nullptr;
    p_movie_prices = movie_prices;

    int *p_movie_count = &movie_count;
    *p_movie_count = 8; //setting movie count to 8 after the loop is done

    for(int i = 0; i < *p_movie_count; i++){
      
        p_movie_list->set_name(*p_movie_names);
        p_movie_names++;

        p_movie_list->set_seats(*p_seats_number);
        p_seats_number++;

        p_movie_list->set_price(*p_movie_prices);
        p_movie_prices++;
            
        p_movie_list++;
    
        }
    } 

  void MovieTicketMaster::run(){

    Movie* p_view_movie = movie_list;
    int user_choice;
      
    do{
    
    cout << "Movie Ticket Master " << theater_name << " at " << theater_location << endl;
    cout << "Movie Tuesday only for $5" << endl;
    cout << "1. View all movies" << endl;
    cout << "2. Search a movie" << endl;
    cout << "3. Purchase a ticket" << endl;
    cout << "4. Quit" << endl;

    cin >> user_choice;
      
      switch(user_choice){
          case 1:
              ViewMovies();
              break;
          case 2: 
              SearchMovie();
              break;

          case 3:
              PurchaseTicket();
              break;        
            
          case 4: 
            cout << "Thank you for vising our theater! See you soon.\n\n";
            break;

          default: 
            cout << "Incorrect input, please try again."<< endl;  
            break;
          }
      }
    
      while(user_choice != 4);
        
  }


  void MovieTicketMaster::ViewMovies(){
    
    Movie* p_view_movie = movie_list;
    for(int i = 0; i < 8; i++){
        p_view_movie->Display();
        p_view_movie++;
                }
                
  }

  Movie* MovieTicketMaster::FindMovie(string movie_name){
    
    Movie * p_find_movie = movie_list;
    
    for(int i = 0; i < 8; i++){

        if(p_find_movie->get_movie_name() == movie_name){
            cout << "Movie found" << endl;
            return p_find_movie;}
        else{
            p_find_movie++;
            }    
        }
        return nullptr;
    }
    


  Movie* MovieTicketMaster::SearchMovie(){

    string search_movie_name;
    
    cout << "Enter movie name: " << endl;
    
    cin.ignore(); 
    getline(cin, search_movie_name);
    
    Movie * p_find_movie = FindMovie(search_movie_name);
    
    if(p_find_movie != nullptr){
        p_find_movie->Display();
    }
    
    else{
        cout << "Movie not found.\n\n";
    }
    
    return p_find_movie;
} 


  void MovieTicketMaster::PurchaseTicket(){
    
    string movie_purchased;
    int number_of_tickets;
    
    cout << "Which movie would you like to purchase?" << endl;
    cin.ignore(); 
    getline(cin, movie_purchased);
    
    Movie* p_find_movie = nullptr;
    p_find_movie = FindMovie(movie_purchased);
    if (p_find_movie != nullptr){
        
        cout << "Enter the number of tickets: " << endl;
        cin >> number_of_tickets;
        
        double tickets_purchased = p_find_movie->PurchaseTicket(number_of_tickets);
        if(tickets_purchased != -1){
         
         cout << "The total of the ticket(s) is: $" << setprecision(2) << fixed << tickets_purchased << endl;
        }
        
        else{
            cout << "The show has been sold out or not enough tickets available per your request!\n\n";
                } 
            }
    else{
        cout << "Error message.\n\n";
    }        
        }  
