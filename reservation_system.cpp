#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct person
{
    string name;
    string dep_city;
    string des_city;
    string time;
    string date;
    string ticket_number;
};
typedef struct person Info_person;

Info_person get_data(ifstream &read)
{
    Info_person ip;

	getline(read, ip.name);
    getline(read, ip.dep_city);
    getline(read, ip.des_city);
    getline(read, ip.date);
    getline(read, ip.time);
    getline(read, ip.ticket_number);
	return ip;
}

class View
{
    public:
        View(){}
        void insert_info(Info_person &ip, ofstream &fout);
        void write_file(Info_person &ip, ofstream &fout);
        void search_info(Info_person &ip, ifstream &fin);
};

class Mode
{
    string line;
    ifstream fin;
    ofstream fout;
    public:
        void read_file(Info_person &ip,ifstream &fin);
        void write_file(Info_person &ip,ofstream &fout);
        void update_info(Info_person &ip, ifstream &info);
        void insert_data(Info_person &ip,ofstream &fout);
        void delete_info(Info_person &ip, ifstream &info);
};

void View::insert_info(Info_person &ip,ofstream &fout)
{
    cout << "Name of passenger" << endl;
    getline(cin, ip.name);
    cout << "Departure City" << endl;
    getline(cin, ip.dep_city);
    cout << "Destination City" << endl;
    getline(cin, ip.des_city);
    cout << "Date of travel" << endl;
    getline(cin, ip.date);
    cout << "Time of travel" << endl;
    getline(cin, ip.time);
    cout << "Number of tickets" << endl;
    cin >> ip.ticket_number;
    string seat_number;
    seat_number = ip.ticket_number.substr(6, 7);
    cout << "Your seat number is: " << seat_number << endl;
    write_file(ip,fout);

    cout << "Susscessful insert !\n\n\n";
}

void print_data(Info_person &ip) 
{
    cout << "Name of passenger: " << ip.name << endl;
    cout << "Departure City: " << ip.dep_city << endl;
    cout << "Destination City: " << ip.des_city << endl;
    cout << "Date of travel: " << ip.date << endl;
    cout << "Time of travel: " << ip.time << endl;
    cout << "Number of tickets: " << ip.ticket_number << endl;
}

void View::search_info(Info_person &ip, ifstream &fin)
{
    string search_name;
    string search_date;
    cout<<"Enter name for searching: ";
    getline(cin,search_name);
    cout<<"Enter date for searching: ";
    getline(cin,search_date);
    cout<<"\n\n";
    ip = get_data(fin);
    while (!fin.eof())
    {
        if(ip.name == search_name && ip.date == search_date)
        {
            print_data(ip);
        }
        ip = get_data(fin);

    }
    fin.close();
    cout << "Susscessful search !\n\n\n";
}

void View::write_file(Info_person &ip, ofstream &fout)
{
    fout << ip.name << endl;
    fout << ip.dep_city << endl;
    fout << ip.des_city << endl;
    fout << ip.date << endl;
    fout << ip.time << endl;
    fout << ip.ticket_number << endl;
    fout.close();
}

void Mode::read_file(Info_person &ip, ifstream &fin)
{
    if(!fin.is_open())
    {
        fin.close();
        cout << "There are no information, please insert the information !" << endl;
    }
    else
    {
    cout << "***** Information of passenger *****\n" << endl;
    ip = get_data(fin);
    while (!fin.eof())
    {
        print_data(ip);
        ip = get_data(fin);

    }
    fin.close();
    }

}


void Mode::write_file(Info_person &ip, ofstream &fout)
{
    fout << ip.name << endl;
    fout << ip.dep_city << endl;
    fout << ip.des_city << endl;
    fout << ip.date << endl;
    fout << ip.time << endl;
    fout << ip.ticket_number << endl;
}

void Mode::insert_data(Info_person &ip,ofstream &fout)
{
    cout << "Name of passenger" << endl;
    getline(cin, ip.name);
    cout << "Departure City" << endl;
    getline(cin, ip.dep_city);
    cout << "Destination City" << endl;
    getline(cin, ip.des_city);
    cout << "Date of travel" << endl;
    getline(cin, ip.date);
    cout << "Time of travel" << endl;
    getline(cin, ip.time);
    cout << "Number of tickets" << endl;
    cin >> ip.ticket_number;
    write_file(ip,fout);
}

void Mode::update_info(Info_person &ip, ifstream &info)
{
	ofstream temp("temp.txt",ios::out);
    string edit_info;
    cout<<"Enter infomation wanna change: ";
    getline(cin,edit_info);
	ip = get_data(info);
    while (!info.eof())
    {
        if (ip.name == edit_info)
		//Update data
		 {
			insert_data(ip, temp);
            
		}
		else {
			write_file(ip, temp);
		}
		ip = get_data(info);
	}
	info.close();
	temp.close();
	remove("test.txt");
	rename("temp.txt", "test.txt");
    cout << "Susscessful update !\n\n\n";
    
}

void Mode::delete_info(Info_person &ip, ifstream &info)
{
	ofstream temp("temp.txt",ios::out);
    string a;
    cout<<"Enter infomation wanna change: ";
    getline(cin,a);
	ip = get_data(info);
    while (!info.eof())
    {
        if (ip.name != a)
		//Delete data
		{
			write_file(ip, temp);
        }
		ip = get_data(info);
	}
	info.close();
	temp.close();
	remove("test.txt");
	rename("temp.txt", "test.txt");
    cout << "Susscessful cancel !\n\n\n";
}

int main()
{

    ifstream text_i;
    ofstream text_o;
    Info_person p1;
    Mode m_psg1;  
    View v_psg1;   
    char menuInput;
    cout << "***** Welcome to Reservation System of Daewoo ! *****\n\n";
    do
    {
        cout<<"r -> Read the information\n";
        cout<<"u -> Update the information\n";
        cout<<"i -> Insert the information\n";
        cout<<"c -> Cancel the reservation\n";
        cout<<"s -> Search the information\n";
        cout<<"q -> Quit\n";  
        cin >> menuInput;
        switch (menuInput)
        {
            case 'u':
                cin.ignore();   
                text_i.open("test.txt",ios::in);   
                m_psg1.update_info(p1, text_i);
                break;
            case 'd':
                cin.ignore();   
                text_i.open("test.txt",ios::in);   
                m_psg1.delete_info(p1, text_i);
                break;
            case 'r': 
                text_i.open("test.txt",ios::in);
                m_psg1.read_file(p1,text_i);
                break;
            case 'i':
                cin.ignore();    
                text_o.open("test.txt",ios::app);
                v_psg1.insert_info(p1,text_o);
                break;
            case 's': 
                cin.ignore();   
                text_i.open("test.txt",ios::in);
                v_psg1.search_info(p1,text_i);
                break;
            case 'q':
                cout<< "Thank you for using our service !";
                exit(0);
                break;
            default:
                cin.ignore(); 
                printf("Wrong syntax\n");
        }
    }while (1);
    return 0;
}