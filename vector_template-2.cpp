#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q) {
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory{
    private:
        std::vector<Item<T>> items;
    public:
        // Write Your code 
        void addNewItem(const Item<T>& item) {
            for (const auto& existingItem : items) {
                if (existingItem.name == item.name) {
                    std::cout << "Item already exists!" << std::endl;
                    return;
                }
            }
            items.push_back(item);
        }

        void increaseQuantity(const T& itemName, int amount) {
            for (auto& item : items) {
                if (item.name == itemName) {
                    item.quantity += amount;
                    std::cout << "Quantity of " << itemName << " is now " << item.quantity << std::endl;
                return;
                }
            }
            std::cout << itemName << " not found in inventory." << std::endl;
        }

        void updateItem(const T& itemName, const T& exp, const T& categ, int quant) {
            for (auto& item : items) {
                if (item.name == itemName) {
                    item.expiration = exp;
                    item.category = categ;
                    item.quantity = quant;
                    std::cout << itemName << " updated." << std::endl;
                    return;
                }
            }
            throw "Item not found";
        }

        void removeItem(const T& itemName) {
            for (auto it = items.begin(); it != items.end(); ++it) {
                if (it->name == itemName) {
                    items.erase(it);
                    std::cout << "Removed item: " << itemName << std::endl;
                    return;
                }
            }
            throw "Item not found";
        }

        int Total() const {
            int total = 0;
            for (const auto& item : items) {
                total += item.quantity;
            }
            return total;
        }

        void searchItem(const T& itemName) const {
        for (const auto& item : items) {
            if (item.name == itemName) {
                std::cout << "Item found:" << std::endl;
                std::cout << "Name: " << item.name << std::endl;
                std::cout << "Expiration: " << item.expiration << std::endl;
                std::cout << "Category: " << item.category << std::endl;
                std::cout << "Quantity: " << item.quantity << std::endl;
                return;
            }
        }
            throw "Item not found";
        }

        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }
};
template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
        private:
        std::vector<Appointment<T>> appointments;
        public:
        // Write Your code
        void schedule(const Appointment<T>& appointment) {
            for (const auto& existingAppointment : appointments) {
                if (existingAppointment.CWID == appointment.CWID) {
                    std::cout << "You have already scheduled an appointment. " << std::endl;
                    return;
                }
            }
            appointments.push_back(appointment);
            std::cout << "Appointment scheduled for " << appointment.c_name << " (CWID: " << appointment.CWID << ")" << std::endl;
        }

        int Total_appointments(const T& date, const T& time) const {
            int count = 0;
            for (const auto& appointment : appointments) {
                if (appointment.ap_date == date && appointment.ap_time == time) {
                    count++;
                }
            }
            return count;
        }

        void removeRecent() {
            if (appointments.empty()) {
                std::cout << "No appointments to remove!" << std::endl;
                return;
            }
            Appointment<T> removedAppointment = appointments.back();
            appointments.pop_back();
            std::cout << "Removed recent appointment: " << removedAppointment.c_name << " (CWID: " << removedAppointment.CWID << ")" << std::endl;
        }

        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<appointments.size();i++){
                std::cout<<std::left << std::setw(20)<<appointments[i].c_name<<std::setw(15)<<appointments[i].ap_date<<std::setw(15)<<appointments[i].ap_time<<std::setw(15)<<appointments[i].CWID<<std::endl;
            }
        }
};
int main(){
//  Remove comments and run following test cases
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
}